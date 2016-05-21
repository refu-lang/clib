/**
 * @author: Lefteris Karapetsas
 * @licence: BSD3 (Check repository root for details)
 */
#include <rfbase/string/corex.h>

#include <rfbase/string/traversalx.h>
#include <rfbase/string/core.h>
#include "rf_str_common.ph"

#include <rfbase/utils/endianess.h>
#include <rfbase/utils/rf_unicode.h>
#include <rfbase/utils/log.h>
#include <rfbase/defs/retcodes.h>
#include <rfbase/utils/constcmp.h>
#include <rfbase/utils/memory.h>
#include <rfbase/utils/sanity.h>
#include <rfbase/persistent/buffers.h>

#include <stdarg.h>
#include <stdio.h>

/* === Init functions === */

/* --- Functions that already exist for RFstring - START --- */
struct RFstringx* rf_stringx_createv(const char* lit, ...)
{
    struct RFstringx* ret;
    va_list args;

    va_start(args, lit);
    ret = rf_stringx_createvl(lit, args);
    va_end(args);
    return ret;
}

struct RFstringx* rf_stringx_createvl(const char* lit, va_list args)
{
    struct RFstringx* ret;

    RF_MALLOC(ret, sizeof(*ret), return NULL);
    if (!rf_stringx_initvl(ret, lit, args)) {
        free(ret);
        return NULL;
    }
    return ret;
}

struct RFstringx* rf_stringx_create(const char* lit)
{
    struct RFstringx* ret;
    RF_MALLOC(ret, sizeof(*ret), return NULL);
    if(!rf_stringx_init(ret, lit))
    {
        free(ret);
        return NULL;
    }
    return ret;
}

bool rf_stringx_initv(struct RFstringx* str, const char* lit, ...)
{
    bool ret;
    va_list args;

    va_start(args, lit);
    ret = rf_stringx_initvl(str, lit, args);
    va_end(args);
    return ret;
}

bool rf_stringx_initvl(struct RFstringx* str, const char* lit, va_list args)
{
    bool ret = false;
    char *buff_ptr;
    unsigned int size;
    RF_ASSERT(str, "got NULL string in function");

    if (!lit) {
        RF_ERROR("String initialization failed due to null pointer input");
        return false;
    }

    //read the var args
    RFS_PUSH();
    if (!rf_strings_buffer_fillfmt(lit, &size, &buff_ptr, args)) {
        RF_ERROR("StringX creation failure due to failing at reading the "
                  "formatted string");
        goto end;
    }
    //initialize the string
    if (!rf_stringx_init_unsafe_nnt(str,
                                    (const char*)buff_ptr,
                                    size)) {
        goto end;
    }
    ret = true;


end:
    RFS_POP();
    return ret;
}

bool rf_stringx_init(struct RFstringx* str, const char* lit)
{
    //check the string literal for valid utf-8 byte sequence
    uint32_t byteLength;
    RF_ASSERT(str, "got NULL string in function");

    if (!lit) {
        RF_ERROR("Failed to initialize string due to null c string input");
        return false;
    }
    if(!rf_utf8_verify(lit ,&byteLength, 0))
    {
        RF_ERROR("Error at StringX initialization due to invalid UTF-8 "
                 "byte sequence");
        return false;
    }

    return rf_stringx_init_unsafe_nnt(str, lit, byteLength);
}

struct RFstringx* rf_stringx_create_cp(uint32_t codepoint)
{
    struct RFstringx* ret;
    RF_MALLOC(ret, sizeof(*ret), return NULL);
    if(!rf_stringx_init_cp(ret, codepoint))
    {
        free(ret);
        return NULL;
    }
    return ret;
}
bool rf_stringx_init_cp(struct RFstringx* str, uint32_t codepoint)
{
    RF_ASSERT(str, "got NULL string in function");
    if(!rf_string_init_cp(&str->INH_String, codepoint))
    {
        return false;
    }
    str->bSize = MAX_UTF8C_BYTES;
    str->bIndex = 0;
    return true;
}

struct RFstringx* rf_stringx_create_int(int i)
{
    struct RFstringx* ret;
    RF_MALLOC(ret, sizeof(*ret), NULL);
    if (!rf_stringx_init_int(ret, i)) {
        free(ret);
        return NULL;
    }
    return ret;
}
bool rf_stringx_init_int(struct RFstringx* str, int i)
{
    RF_ASSERT(str, "got NULL string in function");
    if (!rf_string_init_int(&str->INH_String, i)) {
        return false;
    }

    str->bSize = rf_string_length_bytes(str);
    str->bIndex = 0;
    return true;
}
struct RFstringx* rf_stringx_create_double(double d, unsigned int precision)
{
    struct RFstringx* ret;
    RF_MALLOC(ret, sizeof(*ret), return NULL);
    if (!rf_stringx_init_double(ret, d, precision)) {
        free(ret);
        return NULL;
    }
    return ret;
}
bool rf_stringx_init_double(struct RFstringx* str,
                            double d,
                            unsigned int precision)
{
    RF_ASSERT(str, "got NULL string in function");
    if (!rf_string_init_double(&str->INH_String, d, precision)) {
        return false;
    }
    str->bSize = rf_string_length_bytes(str);
    return true;
}

struct RFstringx* rf_stringx_create_utf16(const uint16_t* s, unsigned int len)
{
    struct RFstringx* ret;
    RF_MALLOC(ret, sizeof(*ret), return NULL);
    if (!rf_stringx_init_utf16(ret, s, len)) {
        free(ret);
        return NULL;
    }
    return ret;
}
bool rf_stringx_init_utf16(struct RFstringx* str,
                           const uint16_t* s,
                           unsigned int len)
{
    RF_ASSERT(str, "got NULL string in function");
    if (!rf_string_init_utf16(&str->INH_String, s, len)) {
        return false;
    }
    str->bIndex = 0;
    str->bSize = rf_string_length_bytes(str);
    return true;
}
struct RFstringx* rf_stringx_create_utf32(const uint32_t* s, unsigned int len)
{
    struct RFstringx* ret;
    RF_MALLOC(ret, sizeof(*ret), return NULL);
    if(!rf_stringx_init_utf32(ret, s, len))
    {
        free(ret);
        return 0;
    }
    return ret;
}
bool rf_stringx_init_utf32(struct RFstringx* str, const uint32_t* codeBuffer,
                          unsigned int len)
{
    RF_ASSERT(str, "got NULL string in function");
    if(!rf_string_init_utf32(&str->INH_String, codeBuffer, len))
    {
        return false;
    }
    str->bIndex = 0;
    str->bSize = rf_string_length_bytes(str);
    return true;
}
struct RFstringx* rf_stringx_create_unsafe(const char* lit)
{
    struct RFstringx* ret;
    RF_MALLOC(ret, sizeof(*ret), return NULL);
    if(!rf_stringx_init_unsafe(ret, lit))
    {
        free(ret);
        return NULL;
    }
    return ret;
}
bool rf_stringx_init_unsafe(struct RFstringx* str, const char* lit)
{
    if(!rf_string_init_unsafe(&str->INH_String, lit))
    {
        return false;
    }
    str->bIndex = 0;
    str->bSize = rf_string_length_bytes(str);
    return true;
}
bool rf_stringx_init_unsafe_nnt(struct RFstringx* str, const char* s,
                               size_t length)
{
    RF_ASSERT(str, "got NULL string in function");
    str->bSize = length * RF_OPTION_STRINGX_CAPACITY_MULTIPLIER;
    RF_MALLOC(rf_string_data(str), str->bSize, return false);
    memcpy(rf_string_data(str), s, length);
    rf_string_length_bytes(str) = length;
    str->bIndex = 0;
    return true;
}

bool rf_stringx_init_unsafe_bnnt(struct RFstringx* str, const char* s,
                                size_t length, size_t buff_size)
{
    RF_ASSERT(str, "got NULL string in function");
    str->bSize = buff_size;
    RF_MALLOC(rf_string_data(str), str->bSize, return false);
    memcpy(rf_string_data(str), s, length);
    rf_string_length_bytes(str) = length;
    str->bIndex = 0;
    return true;
}

/* --- Functions that already exist for RFstring - END --- */

struct RFstringx* rf_stringx_create_buffv(uint32_t buffSize, const char* lit, ...)
{
    struct RFstringx* ret = NULL;
    va_list args;
    char *buff_ptr;
    unsigned int size;

    if (!lit) {
        RF_ERROR("Provided null pointer for the string literal");
        return NULL;
    }

    va_start(args, lit);
    //read the var args
    RFS_PUSH();
    if (!rf_strings_buffer_fillfmt(lit, &size, &buff_ptr, args)) {
        RF_ERROR("StringX creation failure due to failing at reading the "
                  "formatted string");
        goto end;
    }
    va_end(args);

    //Make sure that the buff size fits the string
    if (buffSize < size) {
        buffSize = size;
    }
    RF_MALLOC(ret, sizeof(*ret), ret = NULL; goto end);
    if (!rf_stringx_init_unsafe_bnnt(ret, buff_ptr, size, buffSize)) {
        free(ret);
        ret = NULL;
    }

end:
    RFS_POP();
    return ret;
}
struct RFstringx* rf_stringx_create_buff(uint32_t buffSize,const char* lit)
{
    struct RFstringx* ret;
    RF_MALLOC(ret, sizeof(*ret), return NULL);
    if (!rf_stringx_init_buff(ret, buffSize, lit)) {
        free(ret);
        return NULL;
    }
    return ret;
}


bool rf_stringx_init_buffv(struct RFstringx* str,
                           uint32_t buffSize,
                           const char* lit, ...)
{
    bool ret = false;
    va_list args;
    char *buff_ptr;
    unsigned int size;
    RF_ASSERT(str, "got NULL string in function");

    if (!lit) {
        RF_ERROR("Provided null pointer for the string literal");
        return false;
    }

    va_start(args, lit);
    //read the var args
    RFS_PUSH();
    if (!rf_strings_buffer_fillfmt(lit, &size, &buff_ptr, args)) {
        RF_ERROR("StringX creation failure due to failing at reading the "
                  "formatted string");
        goto end;
    }
    va_end(args);

    //Make sure that the buff size fits the string
    if (buffSize < size) {
        buffSize = size;
    }
    ret = rf_stringx_init_unsafe_bnnt(str, buff_ptr, size, buffSize);
    ret = true;

end:
    RFS_POP();
    return ret;
}

bool rf_stringx_init_buff(struct RFstringx* str, uint32_t buffSize,
                             const char* lit)
{
    //check the string literal for valid utf-8 byte sequence
    uint32_t byteLength;
    RF_ASSERT(str, "got NULL string in function");
    if (!lit) {
        RF_WARNING("provided null source string literal");
        return false;
    }
    if (!rf_utf8_verify(lit, &byteLength, 0)) {
        RF_ERROR("Error at StringX initialization due to invalid UTF-8 "
                  "byte sequence");
        return false;
    }
    //make sure that the buff size fits the string
    if (buffSize < byteLength) {
        buffSize = byteLength;
    }
    return rf_stringx_init_unsafe_bnnt(str, lit, byteLength, buffSize);
}


/*---- Methods to copy/assign an RFstringx ----*/

bool rf_stringx_assign(struct RFstringx* dst, const struct RFstring *source)
{
    RF_ASSERT(dst, "got NULL string in function");
    if (!source) {
        RF_WARNING("provided null source string");
        return false;
    }
    //only if the new string value won't fit in the buffer reallocate the buffer
    RF_STRINGX_REALLOC(dst,
                       rf_string_length_bytes(source),
                       return false);
    //now copy the value and the bytelength
    memcpy(rf_string_data(dst),
           rf_string_data(source),
           rf_string_length_bytes(source));
    rf_string_length_bytes(dst) = rf_string_length_bytes(source);

    return true;
}

i_DECLIMEX_ bool rf_stringx_assignv(struct RFstringx* str, const char* s, ...)
{
    va_list args;
    bool ret;

    va_start(args, s);
    ret = rf_stringx_assignvl(str, s, args);
    va_end(args);
    return ret;
}
i_DECLIMEX_ bool rf_stringx_assignvl(struct RFstringx* str,
                                     const char* s,
                                     va_list args)
{
    unsigned int size;
    char *buff_ptr;
    bool ret = false;
    RF_ASSERT(str, "got NULL string in function");

    if (!s) {
        RF_ERROR("Stringx assignment failed due to null pointer input");
        return false;
    }
    //read the var args
    RFS_PUSH();
    if (!rf_strings_buffer_fillfmt(s, &size, &buff_ptr, args)) {
        RF_ERROR("Stringx assignment failure due to failing at reading the "
                 "formatted string");
        goto end;
    }
    RF_STRINGX_REALLOC(str, size, goto end;);
    //get length
    rf_string_length_bytes(str) = size;
    memcpy(rf_string_data(str), buff_ptr, rf_string_length_bytes(str));
    ret = true;

end:
    RFS_POP();
    return ret;
}

bool rf_stringx_assign_char(struct RFstringx* str, uint32_t codepoint)
{
    int bytes;
    RF_ASSERT(str, "got NULL string in function");
    //reset the buffer if needed
    rf_stringx_reset(str);
    //realloc if needed
    if (str->bSize < 5) {
        RF_REALLOC(rf_string_data(str), char,
                   5 * RF_OPTION_STRINGX_CAPACITY_MULTIPLIER, return false);
    }
    if ((bytes=rf_utf8_encode_single(codepoint, rf_string_data(str))) <= 0) {
        RF_ERROR("Assigning a character to an RFstringx failed "
                 "due to utf8 encoding");
        return false;
    }
    rf_string_length_bytes(str) = bytes;
    return true;
}

bool rf_stringx_assign_unsafe_nnt(struct RFstringx* str, const char* s,
                                 size_t length)
{
    bool ret = true;
    RF_ASSERT(str, "got NULL string in function");
    if (!s) {
        RF_WARNING("Provided null pointer for assignment");
        return false;
    }

    /* make sure it fits in the string */
    rf_stringx_reset(str);
    RF_STRINGX_REALLOC(str, length, ret=false; goto cleanup);
    //now copy the value
    memcpy(rf_string_data(str), s, length);
    //and fix the lengths
    rf_string_length_bytes(str) = length;

  cleanup:
    return ret;
}

struct RFstringx* rf_stringx_from_string_out(const struct RFstring* s)
{
    struct RFstringx* ret;
    RF_MALLOC(ret, sizeof(*ret), return NULL);
    if(!rf_stringx_from_string_in(ret, s))
    {
        free(ret);
        return NULL;
    }
    return ret;
}

bool rf_stringx_from_string_in(struct RFstringx* dst,
                               const struct RFstring* src)
{
    RF_ASSERT(dst, "got NULL string in function");
    if (!src) {
        RF_WARNING("provided null source string");
        return false;
    }
    //allocate the stringX
    dst->bIndex = 0;
    dst->bSize = (
        rf_string_length_bytes(src) * RF_OPTION_STRINGX_CAPACITY_MULTIPLIER
    );
    RF_MALLOC(rf_string_data(dst), dst->bSize, return false);
    rf_string_length_bytes(dst) = rf_string_length_bytes(src);
    //copy the bytes from the String
    memcpy(rf_string_data(dst), rf_string_data(src), rf_string_length_bytes(src));
    return true;
}

struct RFstringx* rf_stringx_copy_out(struct RFstringx* s)
{
    struct RFstringx* ret;
    RF_MALLOC(ret, sizeof(*ret), return NULL);
    if(!rf_stringx_copy_in(ret, s))
    {
        free(ret);
        return NULL;
    }
    return ret;
}

bool rf_stringx_copy_in(struct RFstringx* dst, struct RFstringx* src)
{
    RF_ASSERT(dst, "got NULL string in function");
    if (!src) {
        RF_WARNING("Provided null source string");
        return false;
    }
    //assert that the source string is copied from the beginning of its buffer
    rf_string_data(src) -= src->bIndex;
    //copy the bytes
    RF_MALLOC(rf_string_data(dst), src->bSize, return false);
    memcpy(rf_string_data(dst), rf_string_data(src), src->bSize);
    //push the source bytes back and also the new copied bytes
    //buffer to the same index
    rf_string_data(src) += src->bIndex;
    rf_string_data(dst) += src->bIndex;
    //copy the parameters
    dst->bSize = src->bSize;
    dst->bIndex = src->bIndex;
    rf_string_length_bytes(dst) = rf_string_length_bytes(src);
    return true;
}

bool rf_stringx_copy_chars(struct RFstringx* dst, struct RFstringx* src,
                          uint32_t charsN)
{
    uint32_t i=0,bytePos;
    if (!rf_stringx_copy_in(dst, src)) {
        return false;
    }
    //find the byte position and end the string there
    RF_STRING_ITERATE_START(src, i, bytePos)
    if(i == charsN)
        break;
    RF_STRING_ITERATE_END(i, bytePos)
    rf_string_length_bytes(dst)= bytePos;
    return true;
}

/*--- Methods to get rid of an RFstringx ---*/

void rf_stringx_destroy(struct RFstringx* s)
{
    //an extended string can have moved its internal pointer forward
    //so we have to put it back at the origin to free properly
    rf_string_data(s) -= s->bIndex;
    free(rf_string_data(s));
    free(s);
}
void rf_stringx_deinit(struct RFstringx* s)
{
    //an extended string can have moved its internal pointer forward
    //so we have to put it back at the origin to free properly
    rf_string_data(s) -= s->bIndex;
    free(rf_string_data(s));
}
