/**
 * @author: Lefteris Karapetsas
 * @licence: BSD3 (Check repository root for details)
 */
#ifndef RF_STRING_MANIPULATION_H
#define RF_STRING_MANIPULATION_H

#include <rfbase/string/decl.h>
#include <rfbase/string/flags.h>

#include <rfbase/defs/imex.h>
#include <rfbase/defs/types.h>
#include <rfbase/defs/retcodes.h>

#ifdef __cplusplus
extern "C"
{///opening bracket for calling from C++
#endif

//! @name Adding to a String
//! @{

/**
 * @brief Appends a string to this one
 *
 * @notinherited{StringX}
 * @lmsFunction
 * @param thisstr   The string to append to
 * @param other     The string to add to this string.
 *                  @inhtype{String,StringX} @tmpSTR
 * @return          Returns @c true for success and @c false otherwise
 * @see rf_string_append_int()
 * @see rf_string_append_double()
 * @see rf_string_prepend()
 */
i_DECLIMEX_ bool rf_string_append(struct RFstring* thisstr, const struct RFstring *other);


/**
 * @brief Appends an integer to the string
 *
 * @notinherited{StringX}
 * @param thisstr     The string to append to
 * @param i           The integer to add
 * @return             Returns @c true for success and @c false otherwise
 * @see rf_string_append()
 * @see rf_string_append_double()
 */
i_DECLIMEX_ bool rf_string_append_int(struct RFstring* thisstr, const int32_t i);

/**
 * @brief Appends a float to the string
 *
 * @notinherited{StringX}
 * @param thisstr       The string to append to
 * @param d             The double
 * @param precision     The number of digits the number should have after
 *                      the decimal point.
 * @return              Returns @c true for success and @c false otherwise
 * @see rf_string_append()
 * @see rf_string_append_int()
 */
i_DECLIMEX_ bool rf_string_append_double(struct RFstring* thisstr,
                                         double d,
                                         unsigned int precision);

/**
 * @brief Prepends the parameter String to this string
 *
 * @notinherited{StringX}
 * @lmsFunction
 * @param thisstr   The string to prepend to
 * @param other     The string to prepend to this string.
 *                  @inhtype{String,StringX} @tmpSTR
 * @return          Returns @c true for success and @c false otherwise
 * @see rf_string_append()
 */
i_DECLIMEX_ bool rf_string_prepend(struct RFstring* thisstr, const struct RFstring *other);


//! @}

//! @name Removing from a String
//! @{

/**
 * @brief Removes occurences of a substring
 *
 * @isinherited{StringX}
 * Removes a @c number of occurences of a substring from this string,
 * that agree with the given parameters.
 * <b>Does not</b> reallocate buffer size
 * @lmsFunction
 * @param thisstr    This string we want to remove from.
 *                   @inhtype{String,StringX}
 * @param rstr       The string whose occurences we need to locate
 *                   and remove from the current string.
 *                   @inhtype{String,StringX} @tmpSTR
 * @param number     The number of occurences to remove.
 *                   Give @e 0 for all the occurences. If the given number
 *                   is bigger than the actual number of occurences, still
 *                   all occurences get replaced.
 * @param options    Bitflag options for the function. All possible values
 *                   can be seen at @ref RFstring_matching_options.
 *                   Give 0 for the defaults.
 *                   For this function only the following are legal:
 *                   + @c RF_CASE_IGNORE
 *                   + @c RF_MATCH_WORD
 * @return                Returns true in case of success, and false if
 *                        the substring was not even found inside the string
 * @see rf_string_append()
 * @see rf_string_trim()
 *
 */
i_DECLIMEX_ bool rf_string_remove(
    struct RFstring *thisstr,
    const struct RFstring *rstr,
    uint32_t number,
    enum RFstring_matching_options options
);


/**
 * @brief Removes all of the characters of the string except those specified
 *
 * This string is scanned for the existence of each characters inside the
 * given @c keepstr. Any character found there is kept in the original
 * string. All other characters are removed.
 * @isinherited{StringX}
 * @lmsFunction
 * @param thisstr     The string to remove from @inhtype{String,StringX}
 * @param keepstr     A string all of whose characters will be kept
 *                    in @c thisstr @inhtype{String,StringX} @tmpSTR
 * @param removals    If you want to know the number of removed characters
 *                    pass an int here . If not just leave as NULL.
 * @return            Returns @c true in success and @c false otherwise
 */
i_DECLIMEX_ bool rf_string_keep_only(
    struct RFstring *thisstr,
    const struct RFstring *keepstr,
    int *removals
);


/**
 * @brief Removes the first n characters from the start of the string.
 *
 * @isinherited{StringX}
 * @param thisstr    The string to prune from. @inhtype{String,StringX}
 * @param n          The number of characters to remove. Must be a
 *                   positive integer.
 * @param options    General string options. Accepted values here are:
 *                       + RF_SOPT_TEMP: Make sure to wrap call with
 *                                       RFS_PUSH()/POP()
 *                       + RF_SOPT_ASCII
 * @param removals   Pass a variable in which to return the number of
 *                   pruned characters or NULL if you don't care.
 * @return           In success, a pointer to @a thisstr with n characters
 *                   removed or a temporary string if that was requested.
 *                   NULL for failure.
 * @see rf_string_prune_end()
 * @see rf_string_prune_middle_b()
 * @see rf_string_prune_middle_f()
 */
i_DECLIMEX_ struct RFstring *rf_string_prune_start(
    struct RFstring *thisstr,
    uint32_t n,
    int options,
    unsigned int *removals
);

/**
 * @brief Removes the last n characters from the end of the string
 *
 * @isinherited{StringX}
 * @param thisstr       The string to prune from. @inhtype{String,StringX}
 * @param n             The number of characters to remove.
 *                      Must be a positive integer.
 * @param options       General string options. Accepted values here are:
 *                         + RF_SOPT_TEMP: Make sure to wrap call with
 *                                       RFS_PUSH()/POP()
 *                         + RF_SOPT_ASCII
 * @param removals      Pass a variable in which to return the number of
 *                      pruned characters or NULL if you don't care.
 * @return              In success, a pointer to @a thisstr with n characters
 *                      removed or a temporary string if that was requested.
 *                      NULL for failure.
 * @see rf_string_prune_start()
 * @see rf_string_prune_middle_b()
 * @see rf_string_prune_middle_f()
 */
i_DECLIMEX_ struct RFstring *rf_string_prune_end(
    struct RFstring *thisstr,
    uint32_t n,
    int options,
    unsigned int *removals
);

/**
 * @brief Removes characters from one point of the string
 * to another going backwards
 *
 * @isinherited{StringX}
 * Removes n characters from the position p (including the character at p)
 * of the string counting backwards. If @c p is not found in the string nothing
 * is done and @c false is returned. If going backwards for @c n takes us over
 * the start of the string, then simply the whole string from p to the beginning
 * is pruned.
 * @param thisstr     The string to prune from. @inhtype{String,StringX}
 * @param p           The position to remove the characters from.
 *                    Must be a positive integer. Indexing starts from zero.
 * @param n           The number of characters to remove from the position
 *                    and back.Must be a positive integer.
 * @param removals    Pass a variable in which to return the number of
 *                    pruned characters or NULL if you don't care.
 * @return            Returns true in case of succesfull removal and
 *                    false in error and the case of giving a @c which is out
 *                    of bounds for the given string.
 * @see rf_string_prune_middle_f()
 * @see rf_string_prune_start()
 * @see rf_string_prune_end()
 */
i_DECLIMEX_ bool rf_string_prune_middle_b(
    struct RFstring *thisstr,
    uint32_t p,
    uint32_t n,
    unsigned int *removals
);

/**
 * @brief Removes characters from one point of the string
 * to another going forward
 *
 * @isinherited{StringX}
 * Removes n characters from the position @c p (including the character at p)
 * of the string counting forwards. If @c p is not found in the string nothing
 * is done and @c false is returned. If going forwards for @c n takes us over
 * the end of the string, then simply the whole string from p to the end
 * is pruned.
 * @param thisstr     The string to prune from. @inhtype{String,StringX}
 * @param p           The position to remove the characters from.
 *                    Must be a positive integer. Indexing starts from zero.
 * @param n           The number of characters to remove from the
 *                    position and on. Must be a positive integer.
 * @param removals    Pass a variable in which to return the number of
 *                    pruned characters or NULL if you don't care.
 * @return            Returns true in case of succesfull removal and
 *                    false in error and the case of giving a @c which is out
 *                    of bounds for the given string.
 * @see rf_string_prune_middle_b()
 * @see rf_string_prune_start()
 * @see rf_string_prune_end()
 */
i_DECLIMEX_ bool rf_string_prune_middle_f(
    struct RFstring *thisstr,
    uint32_t p,
    uint32_t n,
    unsigned int *removals
);

/**
 * @brief Removes all characters of a substring only from
 * the start of the String
 *
 * @isinherited{StringX}
 * Searches for and removes each individual character inside the
 * @c sub substring from the given String @c thisstr starting from the
 * beginning of the String and until it finds any other character
 * @lmsFunction
 * @param thisstr    The string to search in. @inhtype{String,StringX}
 * @param sub        The substring to search for.
 *                   @inhtype{String,StringX} @tmpSTR
 * @param removals   Pass a variable in which to return the number of
 *                   trimmed characters or NULL if you don't care.
 * @return           Returns true for success irrespective of whether any
 *                   characters were trimmed. To confirm that characters were
 *                   trimmed query the @c removals value. Returns @c false on
 *                   error
 * @see rf_string_trim()
 * @see rf_string_trim_end()
 */
i_DECLIMEX_ bool rf_string_trim_start(
    struct RFstring *thisstr,
    const struct RFstring *sub,
    unsigned int *removals
);

/**
 * @brief Removes all characters of a substring starting
 * from the end of the String
 *
 * @isinherited{StringX}
 * Searches for and removes each individual character inside the @c sub
 * substring from the given String @c thisstr starting from the end of
 * the String and until it finds any other character
 * @lmsFunction
 * @param thisstr     The string to search in. @inhtype{String,StringX}
 * @param sub         The substring to search for.
 *                    @inhtype{String,StringX} @tmpSTR
 * @param removals    Pass a variable in which to return the number of
 *                    trimmed characters or NULL if you don't care.
 * @return            Returns true for success irrespective of whether any
 *                    characters were trimmed. To confirm that characters were
 *                    trimmed query the @c removals value. Returns @c false on
 *                    error
 * @see rf_string_trim()
 * @see rf_string_trim_start()
 */
i_DECLIMEX_ bool rf_string_trim_end(
    struct RFstring *thisstr,
    const struct RFstring *sub,
    unsigned int *removals
);

/**
 * @brief Removes all characters of a substring from both ends
 * of the given String
 *
 * @isinherited{StringX}
 * Searches for and removes each individual character inside
 * the @c sub substring from the given String @c thisstr starting
 * from both the beginning and the end of the String and until
 * it finds any other character
 * @lmsFunction
 * @param thisstr     The string to search in.
 *                    @inhtype{String,StringX}
 * @param sub         The substring to search for.
 *                    @inhtype{String,StringX} @tmpSTR
 * @param removals    Pass a variable in which to return the number of
 *                    trimmed characters or NULL if you don't care.
 * @return            Returns true for success irrespective of whether any
 *                    characters were trimmed. To confirm that characters were
 *                    trimmed query the @c removals value. Returns @c false on
 *                    error
 * @see rf_string_trim_start()
 * @see rf_string_trim_end()
 */
i_DECLIMEX_ bool rf_string_trim(
    struct RFstring *thisstr,
    const struct RFstring *sub,
    unsigned int *removals
);

//! @}

//! @name Replacing parts of a String
//! @{

/**
 * @brief Replace all occurences of a String
 *
 * @notinherited{StringX}
 * Replaces all of the specified @c sstr substring from the String with
 * @c rstr and reallocates size, unless the new size is smaller
 * @lmsFunction
 * @param thisstr          The string in which to do the replacing
 * @param sstr             The string to locate and replace from the
 *                         current string. @inhtype{String,StringX} @tmpSTR
 * @param rstr             The string with which to replace it.
 *                         @inhtype{String,StringX} @tmpSTR
 * @param number           The number of occurences to
 *                         replace. Give @e 0 for all the occurences.
 *                         If the given number is bigger than the actual
 *                         number of occurences, still all occurences
 *                         get replaced.
 * @param options    Bitflag options for the function. All possible values
 *                   can be seen at @ref RFstring_matching_options.
 *                   Give 0 for the defaults.
 *                   For this function only the following are legal:
 *                   + @c RF_CASE_IGNORE
 *                   + @c RF_MATCH_WORD
 * @return                   Returns true in case of success, and false if
 *                           the substring was not even found inside the string
 * @see rf_stringx_replace()
 */
i_DECLIMEX_ bool rf_string_replace(
    struct RFstring *thisstr,
    const struct RFstring *sstr,
    const struct RFstring *rstr,
    const uint32_t number,
    enum RFstring_matching_options options
);
//! @}


#ifdef __cplusplus
}///closing bracket for calling from C++
#endif

#endif//include guards end
