/*
 *    == START OF REFU LICENSE ==
 *
 * Copyright (c) 2011-2013, Karapetsas Eleftherios
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the Original Author of Refu nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES;LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *    == END OF REFU LICENSE ==
*/
#ifndef RF_STRING_MODULE_HEADERS
#define RF_STRING_MODULE_HEADERS

#include <rf_options.h>
#ifdef RF_MODULE_STRINGS//check if the strings are included as a module


/*---------other needed headers-----*/
#include <Utils/rf_unicode.h>
/*---------RFstring headers--------*/
#include <String/rf_str_xdecl.h>
#include <String/rf_str_common.h>
#include <String/rf_str_core.h>
#include <String/rf_str_retrieval.h>
#include <String/rf_str_conversion.h>
#include <String/rf_str_manipulation.h>
#include <String/rf_str_files.h>
/*---------RFstringx headers--------*/
#include <String/rf_str_corex.h>
#include <String/rf_str_manipulationx.h>
#include <String/rf_str_traversalx.h>
#include <String/rf_str_filesx.h>
#include <stdarg.h> //needed for the va_list argument

#else //end of the strings module include
    #error Attempted to include Refu String manipulation without the proper flag
#endif

#endif //end OF ifndef guards
