/**
 * @author: Lefteris Karapetsas
 * @licence: BSD3 (Check repository root for details)
 */
#ifndef RF_STRING_TRAVERSALX_H
#define RF_STRING_TRAVERSALX_H

#include <rfbase/string/xdecl.h>
#include <rfbase/string/flags.h>

#include <rfbase/defs/imex.h>
#include <rfbase/defs/types.h>
#include <rfbase/defs/retcodes.h>
#include <rfbase/defs/inline.h>

#ifdef __cplusplus
extern "C"
{///opening bracket for calling from C++
#endif

//! @name Traversing an RFstringx
//! @{

/**
 * @brief Moves the internal pointer right after the the first occurence
 * of substring
 *
 * Searches the StringX for the @c sub substring and moves the internal
 * pointer right after it. Optionally the string between the beginning and
 * the end of the moving is returned in @c result parameter
 * @lmsFunction
 * @param thisstr     The extended string to work on
 * @param sub         The substring after which to move inside the current
 *                    String. @inhtype{String,StringX} @tmpSTR
 * @param result      Pass a pointer to a @c String type to be
 *                    assigned to with the substring between the start of
 *                    @c thisstr and the end of the moving. If the passed
 *                    pointer is of RFstringx type also pass the
 *                    @c RF_STRINGX_ARGUMENT bitflag argument in the
 *                    @c options argument. The caller is responsible for
 *                    initializing  and freeing the string but the function
 *                    will assign to it
 *                    and also reallocate its buffer if needed. If
 *                    @c RF_STRING_DEPENDENT is passed instead then the
 *                    string should not be allocated and it will only point
 *                    to the buffer of @c thisstr. In that case it will only
 *                    be valid as long as @c thisstr is.
 *                    If 0 nothing is assigned @inhtype{String,StringX}
 * @param options     @see rf_string_remove() for details of the
 *                    possible options. An additional option that can be given:
 *                    + @c RF_STRINGX_ARGUMENT: Pass this bitflag option if the
 *                    pointer you gave for initialization at @c result is
 *                    of RFstringx type
 *                    + @c RF_STRING_DEPENDENT: Pass this bitglag option
 *                      if the pointer for the return string should not have
 *                      its own buffer but should depend on the lifetime of
 *                      @c thisstr
 * @return            Returns the number of positions (bytes) moved
 *                    or RF_FAILURE if the substring was not found in the String
 * @see rf_stringx_move_afterv()
 * @see rf_stringx_move_after_pair()
 * @see rf_stringx_move_forward()
 * @see rf_stringx_move_back()
 * @see rf_stringx_reset()
 */
i_DECLIMEX_ int32_t rf_stringx_move_after(
    struct RFstringx *thisstr,
    const struct RFstring *sub,
    void *result,
    enum RFstring_matching_options options
);

/**
 * @brief Moves the internal pointer n characters back
 *
 * It never goes before the original start of the buffer so there is
 * no worry of memory corruption.
 * @param thisstr     The extended string to work on
 * @param n           The number of characters to move the internal pointer
 * @see rf_stringx_move_forward()
 * @see rf_stringx_move_after()
 * @see rf_stringx_reset()
 */
i_DECLIMEX_ void rf_stringx_move_back(struct RFstringx *thisstr, uint32_t n);

/**
 * @brief Moves the internal pointer to the position denoted
 * by @c byte_index
 *
 * This is an unsafe function. No checks are performed.
 * Use only if you know that @c byte_index is a valid position
 *
 * @param s The string for which to move
 * @param byte_index The byte index to move to
 */
i_INLINE_DECL void rf_stringx_move_to_index(struct RFstringx *s,
                                            uint32_t byte_index)
{
    unsigned int n = s->bIndex - byte_index;
    s->INH_String.length += n;
    s->INH_String.data -= n;
    s->bIndex = byte_index;
}

/**
 * @brief Moves the internal pointer by the given number of bytes
 *
 * This is an unsafe function. No checks are performed.
 * Use only if you know that after @c bytes_num the string is still
 * valid
 *
 * @param s The string for which to move
 * @param byte_num The number of bytes to move
 */
i_INLINE_DECL void rf_stringx_move_bytes(struct RFstringx *s,
                                         int bytes_num)
{
    s->INH_String.length -= bytes_num;
    s->INH_String.data += bytes_num;
    s->bIndex += bytes_num;
}

/**
 * @brief Moves the internal pointer n characters forward
 *
 * It never goes beyond the buffer's length so there is no fear of memory
 * corruption. But since many times the buffer can be bigger than the string
 * we can have it go to non-string buffer data so the user has to be careful.
 * @param thisstr The extended string to work on
 * @param n The number of character to move the internal pointer
 * @see rf_stringx_move_back()
 * @see rf_stringx_move_after()
 * @see rf_stringx_reset()
 */
i_DECLIMEX_ void rf_stringx_move_forward(struct RFstringx *thisstr, uint32_t n);

/**
 * @brief Moves the internal pointer to the end of the string
 * @param s The string to move
 */
i_INLINE_DECL void rf_stringx_move_end(struct RFstringx *s)
{
    s->INH_String.data += s->INH_String.length;
    s->bIndex += s->INH_String.length;
    s->INH_String.length = 0;
}

/**
 * @brief Resets the internal pointer of the StringX
 *
 * @param thisstr The stringX whose internal pointer to reset
 * @see rf_stringx_move_forward()
 * @see rf_stringx_move_back()
 * @see rf_stringx_move_after()
 */
i_DECLIMEX_ void rf_stringx_reset(struct RFstringx *thisstr);

/**
 * @brief Resets the internal pointer and makes sure the string is empty.
 *
 * @param thisstr The stringX to clear
 */
i_DECLIMEX_ void rf_stringx_clear(struct RFstringx *thisstr);

/**
 * @brief Moves the internal pointer after the first occurence of any
 * of the given substrings
 *
 * Searches for any of the given Substrings inside @c thisstr. Moves the
 * internal pointer right after the first occuring substring. Optionally and
 * if the value given at @c result is not 0 the string between the start and
 * the end of the moving is returned.
 * @param thisstr      The extended string to work on
 * @param result       For details @see rf_stringx_move_after()
 * @param options      For details @see rf_stringx_move_after()
 * @param parN         The number of parameters
 * @extraVarArgLim
 * @param ...          The strings to search for.
 *                     @inhtype{String,StringX} @tmpSTR
 * @return             true if the substring got initialized and false if
 *                     none of the parameters are found or due to error
 * @see rf_stringx_move_after()
 * @see rf_stringx_move_after_pair()
 * @see rf_stringx_move_forward()
 * @see rf_stringx_move_back()
 * @see rf_stringx_reset()
 */
i_DECLIMEX_ bool rf_stringx_move_afterv(
    struct RFstringx *thisstr,
    void *result,
    enum RFstring_matching_options options,
    const unsigned char parN,
    ...
);

/**
 * @brief Moves the internal pointer by as much as needed to skip characters
 *
 * Skips all occurences of the given characters from the start of the string
 * and until any other character is found. Moves the internal pointer there
 *
 * @lmsFunction
 * @param thisstr           The extended string to work on
 * @param chars             A string containing all the characters to skip
 * @param limit             If not NULL, a pointer to a position inside
 *                          @c thisstr after which to stop skipping chars.
 *                          Characters will be skipped up to and including
 *                          @c limit.
 * @param bytes[out]        If not 0, this will contain the number of bytes of
 *                          @c thisstr that were skipped
 * @param line_count[out]   If not 0, this will contain the number of lines
 *                          that were skipped
 * @return                  The number of chars of @thisstr that were skipped
 */
i_DECLIMEX_ unsigned int rf_stringx_skip_chars(
    struct RFstringx *thisstr,
    const struct RFstring *chars,
    const char *limit,
    unsigned int *bytes,
    unsigned int *line_count
);

/**
 * @brief Moves the internal string pointer after the substring formed
 * by the @c left and @c right substrings
 *
 * Searches @c thisstr for the occurence of both the @c left and @c right
 * substrings and if found moves the internal pointer right after them.
 * If the number given at @c occurence does not exist in the string the
 * function returns @c false. Finally if @c result is not zero then what
 * is between the @c left and @c right substrings is returned inside @c result.
 * @lmsFunction
 * @param thisstr       The extended string to work on
 * @param left          The left substring that will define the new substring.
 *                      @inhtype{String,StringX} @tmpSTR
 * @param right         The right substring that will define the new substring.
 *                      @inhtype{String,StringX} @tmpSTR
 * @param result        For details @see rf_stringx_move_after()
 *                      The string is copied to using copy_in, so provide a
 *                      non initialized string, or free it before passing it
 *                      to the function.
 * @param options       For details @see rf_stringx_move_after()
 * @param occurence     If this is not 0 then the function
 *                      will search for the number of occurence given in this
 *                      parameter. If it is 0 it will search for the first
 *                      occurence. If it is not found then the function shall
 *                      return false
 * @return              Returns true if the substring is found and false if
 *                      not and in the case of an error
 * @see rf_stringx_move_after()
 * @see rf_stringx_move_afterv()
 * @see rf_stringx_move_forward()
 * @see rf_stringx_move_back()
 * @see rf_stringx_reset()
 */
i_DECLIMEX_ bool rf_stringx_move_after_pair(
    struct RFstringx *thisstr,
    const struct RFstring *left,
    const struct RFstring *right,
    void *result,
    enum RFstring_matching_options options,
    uint32_t occurence
);

//! @}

#ifdef __cplusplus
}///closing bracket for calling from C++
#endif

#endif//include guards end
