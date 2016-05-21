/**
 * @author: Lefteris Karapetsas
 * @licence: BSD3 (Check repository root for details)
 */
#ifndef RF_STRING_MANIPULATIONX_H
#define RF_STRING_MANIPULATIONX_H

#include <rfbase/string/xdecl.h>
#include <rfbase/string/flags.h>

#include <rfbase/defs/imex.h>
#include <rfbase/defs/types.h>
#include <rfbase/defs/retcodes.h>

#ifdef __cplusplus
extern "C"
{///opening bracket for calling from C++
#endif


//! @name RFstringx Appending
//! @{

/**
 * @brief Appends the parameter String to this extended string.
 *
 * @lmsFunction
 * @param thisstr     The extended string to append to
 * @param other       The string to add to this string.
 *                    @inhtype{String,StringX} @tmpSTR
 * @return            Returns @c true in success and @c false otherwise
 * @see rf_stringx_prepend()
 */
i_DECLIMEX_ bool rf_stringx_append(struct RFstringx *thisstr, const struct RFstring *other);

/**
 * @brief Appends a number of characters from the parameter String
 * to this extended string.
 *
 * If the number of characters given at @c chars is greater than the actual
 * character length of the @c other String then all of the string is appended.
 * @lmsFunction
 * @param thisstr      The extended string to append to
 * @param other        The string to add to this string.
 *                     @inhtype{String,StringX} @tmpSTR
 * @param chars        The number of chars of @c other to append to @c thisstr
 *                     If 0 is given then all chars are appended
 * @return             Returns @c true in success and @c false otherwise
 * @see rf_stringx_prepend()
 */
i_DECLIMEX_ bool rf_stringx_append_chars(
    struct RFstringx *thisstr,
    const struct RFstring *other,
    unsigned int chars
);

/**
 * @brief Appends a single unicode character to this string
 *
 * @param thisstr      The extended string to append to
 * @param unichar      The character to append to this string.
 *                     It should be a unicode codepoint (UTF-32)
 * @return             Returns @c true in success and @c false otherwise
 * @see rf_stringx_prepend()
 */
i_DECLIMEX_ bool rf_stringx_append_char(struct RFstringx *thisstr, uint32_t unichar);

/**
 * @brief Prepends the parameter String to this extended string
 *
 * @lmsFunction
 * @param thisstr        The extended string to prepend to
 * @param other          The string to prepend to this string.
 *                       @inhtype{String,StringX} @tmpSTR
 * @return               Returns @c true in success and @c false otherwise
 * @see rf_stringx_append()
 */
i_DECLIMEX_ bool rf_stringx_prepend(struct RFstringx *thisstr, const struct RFstring *other);



/**
 * @brief Inserts a string to this extended string at the
 * parameter character position
 *
 * This function takes the given string @c thisstr and finds its @c pos
 * character. Then it inserts the @c other string in the position of that
 * character pushing the rest of the string further ahead.
 * @lmsFunction
 * @param thisstr     The extended string to insert to
 * @param pos         The character position in the string to add it.
 *                    Should be a positive (or zero) integer. If the position
 *                    is over the string's size nothing happens.
 * @param other       The string to add. @inhtype{String,StringX} @tmpSTR
 * @return            Returns @c true in success and @c false otherwise
 * @see rf_stringx_append()
 * @see rf_stringx_prepend()
 */
i_DECLIMEX_ bool rf_stringx_insert(
    struct RFstringx* thisstr,
    uint32_t pos,
    const struct RFstring *other
);

//! @}

//! @name Unsafe appending functions
//! @{

/**
 * @brief Appends some bytes of the parameter String to this extended string.
 *
 * @warning This is a dangerous function. No check is performed in the
 * function to see if a byte is a continuation byte or not. It is mostly
 * used internally and should not
 * be utilized by the user unless you know what you are doing.
 * @lmsFunction
 * @param thisstr      The extended string to append to
 * @param other        The string to add to this string.
 *                     @inhtype{String,StringX} @tmpSTR
 * @param bytes        The number of bytes of @c other to append to @c thisstr
 *                     If more than the total number of bytes of the string
 *                     then all of the bytes are added
 * @return             Returns @c true in success and @c false otherwise
 * @see rf_stringx_append()
 */
i_DECLIMEX_ bool rf_stringx_append_bytes(
    struct RFstringx *thisstr,
    const struct RFstring *other,
    const unsigned int bytes
);

/**
 * @brief Appends a cstring to this string
 *
 * @warning This is a dangerous function. No check is performed in the
 * function to see if the given @c cstr is a valid UTF8 buffer.
 * For a safe way to add a UTF8 string use
 * @ref rf_stringx_append() and enclose the @c cstr with @ref RFS_()
 * @param thisstr      The extended string to append to
 * @param cstr         The cstring to add to this functions
 * @return             Returns @c true in success and @c false otherwise
 * @see rf_stringx_append()
 */
i_DECLIMEX_ bool rf_stringx_append_cstr(
    struct RFstringx *thisstr,
    const char *cstr
);

//! @}

//! @name RFstringx Replacing
//! @{

/**
 * @brief Replaces all occurences of a String
 * @see rf_string_replace()
 */
i_DECLIMEX_ bool rf_stringx_replace(
    struct RFstringx *thisstr,
    const struct RFstring *sstr,
    const struct RFstring *rstr,
    uint32_t number,
    enum RFstring_matching_options options
);


/**
 * @brief Replaces Strings between substrings for a given number of occurences
 *
 * Replaces what exists between the ith left and right substrings of this
 * extended String. Utilizes the internal string pointer.
 * @lmsFunction
 * @param thisstr     The extended string to work on
 * @param left        The left substring that will define the new substring.
 *                    @inhtype{String,StringX} @tmpSTR
 * @param rstr        The string to act as replacement.
 *                    @inhtype{String,StringX} @tmpSTR
 * @param options     @see rf_string_replace()
 * @param i           \rfoptional{0}. The specific between occurence to
 *                    replace. Should range between 1 and infinity. If 0 all
 *                    occurences will be replaced
 * @return            Returns true if the replacing happened and false if
 *                    either the left or the right strings were not found or
 *                    for error
 * @see rf_stringx_replace()
 */
i_DECLIMEX_ bool rf_stringx_replace_between(
    struct RFstringx *thisstr,
    const struct RFstring *left,
    const struct RFstring *right,
    const struct RFstring *rstr,
    enum RFstring_matching_options options,
    uint32_t i
);


//! @}


#ifdef __cplusplus
}///closing bracket for calling from C++
#endif

#endif//include guards end
