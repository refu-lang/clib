/* Taken from the CCAN project:
 * http://ccodearchive.net/index.html
 * https://github.com/rustyrussell/ccan
 *
 * The original code was Licensed under LGPLv2+ - see LICENSE file for details 
 *
 * Modified  a bit by Lefteris Karapetsas<lefteris@refu.co>.
 * All additions are licensed under the same license
 * as the rest of the project (BSD3)
 */
#ifndef RF_DATASTRUCTURES_HTABLE_H
#define RF_DATASTRUCTURES_HTABLE_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <rfbase/defs/inline.h>

/**
 * struct htable - private definition of a htable.
 *
 * It's exposed here so you can put it in your structures and so we can
 * supply inline functions.
 */
struct htable {
	size_t (*rehash)(const void *elem, void *priv);
	void *priv;
	unsigned int bits;
	size_t elems, deleted, max, max_with_deleted;
	/* These are the bits which are the same in all pointers. */
	uintptr_t common_mask, common_bits;
	uintptr_t perfect_bit;
	uintptr_t *table;
};

/**
 * HTABLE_INITIALIZER - static initialization for a hash table.
 * @name: name of this htable.
 * @rehash: hash function to use for rehashing.
 * @priv: private argument to @rehash function.
 *
 * This is useful for setting up static and global hash tables.
 *
 * Example:
 *	// For simplicity's sake, say hash value is contents of elem.
 *	static size_t rehash(const void *elem, void *unused)
 *	{
 *		return *(size_t *)elem;
 *	}
 *	static struct htable ht = HTABLE_INITIALIZER(ht, rehash, NULL);
 */
#define HTABLE_INITIALIZER(name, rehash, priv)				\
	{ rehash, priv, 0, 0, 0, 0, 0, -1, 0, 0, &name.perfect_bit }

/**
 * htable_init - initialize an empty hash table.
 * @ht: the hash table to initialize
 * @rehash: hash function to use for rehashing.
 * @priv: private argument to @rehash function.
 */
void htable_init(struct htable *ht,
		 size_t (*rehash)(const void *elem, void *priv), void *priv);

/**
 * htable_clear - empty a hash table.
 * @ht: the hash table to clear
 *
 * This doesn't do anything to any pointers left in it.
 */
void htable_clear(struct htable *ht);

/**
 * htable_rehash - use a hashtree's rehash function
 * @elem: the argument to rehash()
 *
 */
size_t htable_rehash(const void *elem);

/**
 * htable_add - add a pointer into a hash table.
 * @ht: the htable
 * @hash: the hash value of the object
 * @p: the non-NULL pointer
 *
 * Also note that this can only fail due to allocation failure.  Otherwise, it
 * returns true. If an item is already inserted into the htable it's added again.
 * No duplicate checks happen in this function.
 */
bool htable_add(struct htable *ht, size_t hash, const void *p);

/**
 * htable_del - remove a pointer from a hash table
 * @ht: the htable
 * @hash: the hash value of the object
 * @p: the pointer
 *
 * Returns true if the pointer was found (and deleted).
 */
bool htable_del(struct htable *ht, size_t hash, const void *p);

/**
 * struct htable_iter - iterator or htable_first or htable_firstval etc.
 *
 * This refers to a location inside the hashtable.
 */
struct htable_iter {
	size_t off;
};

/**
 * htable_firstval - find a candidate for a given hash value
 * @htable: the hashtable
 * @i: the struct htable_iter to initialize
 * @hash: the hash value
 *
 * You'll need to check the value is what you want; returns NULL if none.
 * See Also:
 *	htable_delval()
 */
void *htable_firstval(const struct htable *htable,
		      struct htable_iter *i, size_t hash);

/**
 * htable_nextval - find another candidate for a given hash value
 * @htable: the hashtable
 * @i: the struct htable_iter to initialize
 * @hash: the hash value
 *
 * You'll need to check the value is what you want; returns NULL if no more.
 */
void *htable_nextval(const struct htable *htable,
		     struct htable_iter *i, size_t hash);

/**
 * htable_get - find an entry in the hash table
 * @ht: the hashtable
 * @h: the hash value of the entry
 * @cmp: the comparison function
 * @ptr: the pointer to hand to the comparison function.
 *
 * Convenient inline wrapper for htable_firstval/htable_nextval loop.
 */
static inline void *htable_get(const struct htable *ht,
			       size_t h,
			       bool (*cmp)(const void *candidate, void *ptr),
			       const void *ptr)
{
	struct htable_iter i;
	void *c;

	for (c = htable_firstval(ht,&i,h); c; c = htable_nextval(ht,&i,h)) {
		if (cmp(c, (void *)ptr))
			return c;
	}
	return NULL;
}

/**
 * htable_first - find an entry in the hash table
 * @ht: the hashtable
 * @i: the struct htable_iter to initialize
 *
 * Get an entry in the hashtable; NULL if empty.
 */
void *htable_first(const struct htable *htable, struct htable_iter *i);

/**
 * htable_is_empty - check if the hash table is empty
 * @ht: the hashtable to check for
 *
 * @return true if it's empty and false if not
 */
i_INLINE_DECL bool htable_is_empty(const struct htable *htable)
{
    struct htable_iter it;
    return htable_first(htable, &it) == NULL;
}

/**
 * htable_next - find another entry in the hash table
 * @ht: the hashtable
 * @i: the struct htable_iter to use
 *
 * Get another entry in the hashtable; NULL if all done.
 * This is usually used after htable_first or prior non-NULL htable_next.
 */
void *htable_next(const struct htable *htable, struct htable_iter *i);

/**
 * htable_delval - remove an iterated pointer from a hash table
 * @ht: the htable
 * @i: the htable_iter
 *
 * Usually used to delete a hash entry after it has been found with
 * htable_firstval etc.
 */
void htable_delval(struct htable *ht, struct htable_iter *i);


/**
 * Iterate all values of the hash table
 *
 * @param ht_      The hash table to iterate
 * @param it_      A struct htable_iter to use as an iterator
 * @param val_     A pointer to hold each value during iteration
 */
#define htable_foreach(ht_, it_, val_)                   \
    for (val_ = htable_first((ht_), (it_));              \
         val_;                                           \
         val_ = htable_next((ht_), (it_)))

typedef void (*htable_iter_cb)(void *record, void *user_arg);
/**
 * Perform an action for each record of the htable
 * @param ht        The hash table to iterate
 * @param cb        The callback to execute for each record
 * @param user_arg  The optional user argument to the callback
 */
void htable_iterate_records(struct htable *ht, htable_iter_cb cb, void *user_arg);
#endif
