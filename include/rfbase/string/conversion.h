/**
 * @author: Lefteris Karapetsas
 * @licence: BSD3 (Check repository root for details)
 */
#ifndef RF_STRING_CONVERSION_H
#define RF_STRING_CONVERSION_H

#include <rfbase/string/xdecl.h>
#include <rfbase/string/retrieval.h>

#include <rfbase/defs/imex.h>
#include <rfbase/defs/types.h>
#include <rfbase/defs/retcodes.h>
#include <rfbase/defs/inline.h>
#include <rfbase/utils/rf_unicode.h>

#include <string.h>

#ifdef __cplusplus
extern "C"
{///opening bracket for calling from C++
#endif

//! @name Unicode Conversion Functions
//! @{

/**
 * @brief Returns the strings contents as a UTF-16 buffer
 *
 * @isinherited{StringX}
 * This function allocates a UTF-16 buffer in which the string's
 * UTF-8 contents are encoded as UTF-16. The endianess of the buffer
 * is that of the system. The returned buffer needs to be freed by the user
 * later.
 * @param[in]  s      The string in question. @inhtype{String,StringX}
 * @param[out] length Give a reference to a uint32_t in
 *             this argument to receive the length of
 *             the returned UTF-16 buffer in 16-bit words
 * @return Returns an allocated UTF-16 buffer. Needs to be freed by the user later.
 * @see rf_string_tout_f8()
 * @see rf_string_to_utf32()
 */
i_DECLIMEX_ uint16_t *rf_string_to_utf16(const struct RFstring *s, uint32_t *length);

/**
 * @brief Returns the strings contents as a UTF-32 buffer
 *
 * @isinherited{StringX}
 * This function allocates a UTF-32 buffer in which the string's
 * UTF-8 contents are encoded as UTF-32. The endianess of the buffer
 * is that of the system. The returned buffer needs to be freed by the user
 * later.
 * @param[in]  s      The string in question. @inhtype{String,StringX}
 * @param[out] length Give a reference to a uint32_t in this
 *                    argument to receive the length
 *                   of the returned UTF-32 buffer in codepoints. (32-bit) words
 * @return Returns an allocated UTF-16 buffer. Needs to be freed by the user later.
 * @see rf_string_tout_f8()
 * @see rf_string_to_utf16()
 */
i_DECLIMEX_ uint32_t *rf_string_to_utf32(const struct RFstring *s, uint32_t *length);

//! @}

//! @name String Conversion Functions
//! @{

/**
 * @brief Creates a Cstring representation of the string
 *
 * @isinherited{StringX}
 * Since RFstring is not null terminated this function shall allocate
 * a c string where it will be stored.
 *
 * @warning Make sure to free the returned string after using
 *
 * @param s       The string whose cstring repesentation to get.
 *                @inhtype{String,StringX}
 * @return        Returns the pointer to the allocated c string
 */
i_DECLIMEX_ char *rf_string_cstr(const struct RFstring *s);

/**
 * Turns the given string into a null terminated c string.
 * Make sure to call @ref RFS_PUSH() before use
 *  and @ref RFS_POP() after use
 */
i_DECLIMEX_ char *rf_string_cstr_from_buff(const void* s);
i_DECLIMEX_ char *rf_string_cstr_from_buff_or_die(const void* s);

/**
 * @brief Returns the integer value of a String
 *
 * The parameter string must start with a number in any form.
 * @isinherited{StringX}
 * @param thisstr     The string whose integer value to return.
 *                    @inhtype{String,StringX}
 * @param start_off  The offset of the string at which to start
 *                    the conversion attempt. This is needed since some
 *                    bases, like octal and binary may start with 0b or 0
 *                    and are not understoof by strtol().
 * @param[out] v      Will hold the return value
 * @param[out] off    Will hold the offset from the beginning of
 *                    the string up to which a conversion happened.
 *                    Is absolutely needed for hex and octal versions.
 * @return            True in case of succesfull conversion or false if no
 *                    integer was represented by the string
 * @see rf_string_to_double()
 */
i_DECLIMEX_ bool rf_string_to_int(const struct RFstring *s, int64_t *v, size_t *off);
i_DECLIMEX_ bool rf_string_to_uint(
    const struct RFstring *thisstr,
    size_t start_off,
    uint64_t *v,
    size_t *off,
    int base
);

i_INLINE_DECL bool rf_string_to_uint_dec(
    const struct RFstring *thisstr,
    uint64_t *v,
    size_t *off
)
{
    return rf_string_to_uint(thisstr, 0, v, off, 10);
}

i_INLINE_DECL bool rf_string_to_uint_hex(
    const struct RFstring *thisstr,
    uint64_t *v,
    size_t *off
)
{
    const char *c = rf_string_data(thisstr);
    if (!rf_string_to_uint(thisstr, 0, v, off, 16)) {
        return false;
    }

    if (c[0] == '0' && (c[1] == 'x' || c[1] == 'X') && *off <= 1) {
        return false;
    }

    return true;
}

i_INLINE_DECL bool rf_string_to_uint_bin(
    const struct RFstring *thisstr,
    uint64_t *v,
    size_t *off
)
{
    char *s = rf_string_data(thisstr);

    if (rf_string_length_bytes(thisstr) > 2 && *s == '0' && *(s + 1) == 'b') {
        return rf_string_to_uint(thisstr, 2, v, off, 2);
    }
    return rf_string_to_uint(thisstr, 0, v, off, 2);
}

i_INLINE_DECL bool rf_string_to_uint_oct(
    const struct RFstring *thisstr,
    uint64_t *v,
    size_t *off
)
{
    const char *c = rf_string_data(thisstr);
    if (!rf_string_to_uint(thisstr, 0, v, off, 0)) {
        return false;
    }

    if (c[0] == '0' && *off <= 1) {
        return false;
    }

    return true;
}

/**
 * @brief Returns the double value of a String
 *
 * @isinherited{StringX}
 * The parameter string must start with a floating point number
 * @param thisstr     The string whose floating point value to return.
 *                    @inhtype{String,StringX}
 * @param[out] f      Will hold the return float value
 * @param[out] off    Optional. Will hold the offset from the beginning of
 *                    the string up to which a conversion happened.
 * @return            True in case of succesfull conversion or false if no
 *                    double was represented by the string
 * @see rf_string_to_int()
 */
i_DECLIMEX_ bool rf_string_to_double(
    const struct RFstring *thisstr,
    double *f,
    size_t *off
);

/**
 * @brief Turns any uppercase characters of the string into lower case
 *
 * @isinherited{StringX}
 * This function as of now only works with letter of the English alphabet.
 * All the characters of the string that are uppercase shall
 * be turned into lowercase
 * @param thisstr The string for which to perform the uppercase
 *                to lowercase conversion
 * @see rf_string_to_upper()
 */
i_DECLIMEX_ void rf_string_to_lower(struct RFstring *thisstr);

/**
 * @brief Turns any lowercase characters of the string into upper case
 *
 * @isinherited{StringX}
 * This function as of now only works with letter of the English alphabet.
 * All the characters of the string that are lowercase shall be turned
 * into uppercase
 * @param thisstr The string for which to perform the lowercase to
 *                uppercase conversion
 * @see rf_string_to_lower()
 */
i_DECLIMEX_ void rf_string_to_upper(struct RFstring *thisstr);

/**
 * @brief Tokenizes the given string
 *
 * @isinherited{StringX}
 * Separates it into @c tokensN depending on how many substrings
 * can be created from the @c sep separator and stores them
 * into the Array of RFstring* that should be passed to the
 * function. The array gets initialized inside the function and
 * <b>has to be freed explicitly</b> later by thg user.
 * Also each String inside the array has to be Deinitialized too.
 * Here is an example usage:
 * @snippet Strings/tokenize.cpp Tokenize_C
 * @lmsFunction
 * @param[in] thisstr    The string to tokenize.
 *                       @inhtype{String,StringX}
 * @param[in] sep        A substring that will be used as a separator
 *                       @inhtype{String,StringX}
 * @param[out] tokensN   The number of tokens that got created
 * @param[out] tokens    Pass a pointer to an array of RF_Strings. @keepptr
 * @return Returns @c true in success and @c false in case the the
 * separating character has not been found
 */
i_DECLIMEX_ bool rf_string_tokenize(
    const struct RFstring *thisstr,
    const struct RFstring *sep,
    uint32_t *tokensN,
    struct RFstring **tokens
);

/**
 * @brief Get the string reprentation of an ordinal of a number
 *
 * @isinherited{StringX}
 * @warning wrap in RFS_PUSH()/RFS_POP()
 *
 * @param num           The number whose ordinal string to get
 * @return              The string representation of the number's ordinal
 */
i_DECLIMEX_ const struct RFstring *rf_string_ordinal(unsigned int num);
//! @}

#ifdef __cplusplus
}///closing bracket for calling from C++
#endif

#endif//include guards end
