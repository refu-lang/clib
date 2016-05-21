/**
**      ==START OF REFU LICENSE==
**
** Copyright (c) 2011-2013, Karapetsas Eleftherios
** All rights reserved.
** 
** Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
**  1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
**  2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the distribution.
**  3. Neither the name of the Original Author of Refu nor the names of its contributors may be used to endorse or promote products derived from
** 
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
** INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
** SERVICES;LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
** WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**      ==END OF REFU LICENSE==
**
**
** @author Lefteris
** @date 03/02/2012
**
** This collection of preprocessor macros achieves counting the number of arguments that
** are passed into a macro and through a clever trick provide a way to handle the case
** of no arguments.
**
** #CREDIT#The code is taken from this blog: http://gustedt.wordpress.com/2010/06/08/detect-empty-macro-arguments/
** The author of the blog seems to be the guy who thought it up so big kudos to him. It's brilliant.
** Seems he has that and other clever tricks gathered here: http://p99.gforge.inria.fr/
**/

#include "rf_xmacro_eq.h" //for the equal macros

#define i_RP_PASTE2(a__,b__)  a__##b__
#define i_RP_PASTE2_2(a__,b__)  a__##b__ 
#define i_RP_PASTE2_3(a__,b__)  a__##b__ 

#define i_RP_PASTE3(a__,b__,c__)   a__##b__##c__
#define i_RP_PASTE4(a__,b__,c__,d__)   a__##b__##c__##d__
#define i_RP_PASTE5(a__,b__,c__,d__,e__)  a__##b__##c__##d__##e__


// Just a macro that has a reverse sequence of 16 nums
#define i_RP_ARG36_RSEQ()    35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0
// A macro used internally by those counting the number of arguments
#define i_RP_ARG36(_0_, _1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, _9_, _10_, _11_, _12_, _13_, _14_, _15_, _16_, _17_, _18_, _19_, _20_, _21_, _22_, _23_, _24_, _25_, _26_, _27_, _28_,\
                _29_, _30_, _31_, _32_, _33_, _34_, _35_, ...) _35_
#define i_RP_HAS_COMMA(...) i_RP_ARG36(__VA_ARGS__,1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0)
#define i_RP_TRIGGER_PARENTHESIS_(...) ,

// So far this macro has a limit of 16 parameters. I could edit it up to 64 (c limit according to the author of the macro)
#define i_RP_EMPTY_NARG(...)                                                    \
i_RP_ISEMPTY(                                                               \
            /* test if there is just one argument, eventually an empty    \
	             one */                                                     \
	          i_RP_HAS_COMMA(__VA_ARGS__),                                       \
	          /* test if _TRIGGER_PARENTHESIS_ together with the argument   \
	             adds a comma */                                            \
	          i_RP_HAS_COMMA(i_RP_TRIGGER_PARENTHESIS_ __VA_ARGS__),                 \
	          /* test if the argument together with a parenthesis           \
	             adds a comma */                                            \
	          i_RP_HAS_COMMA(__VA_ARGS__ (/*empty*/)),                           \
	          /* test if placing it between _TRIGGER_PARENTHESIS_ and the   \
	             parenthesis adds a comma */                                \
	          i_RP_HAS_COMMA(i_RP_TRIGGER_PARENTHESIS_ __VA_ARGS__ (/*empty*/))      \
	          )


#define i_RP_ISEMPTY(_0_, _1_, _2_, _3_) i_RP_HAS_COMMA(i_RP_PASTE5(i_RP_IS_EMPTY_CASE_, _0_, _1_, _2_, _3_))
#define i_RP_IS_EMPTY_CASE_0001 ,




// This macro checks for the number of arguments of the provided variadic macro list. If provided with an empty list the result is wrong. That's why you should call RF_NARG()
#define i_RP_NARG_NOEMPTY(...)          i_RP_NARG_NOEMPTY_IMP(__VA_ARGS__,i_RP_ARG36_RSEQ())
#define i_RP_NARG_NOEMPTY_IMP(...)       i_RP_ARG36(__VA_ARGS__)


    // Two different helper macro that evaluate if the variadic list is empty or not.
    #define i_RP_NARG_EMPTY_1(V__) 0
    #define i_RP_NARG_EMPTY_0(V__) V__

/**
 ** @defgroup RFpreprocessor_g_r_p Preprocessor
 ** @addtogroup RFpreprocessor_g_r_p
//! @{
 **
 **/


/**
 ** @brief Calls a function with specific arguments
 **/
#define RP_CALL(i_func_, ...) i_func_(__VA_ARGS__)


/**
 ** @brief Places argument @c i_move_arg at the end of a @c __VA_ARGS__ list
 **/
#define RP_END_OF_ARGLIST0(i_func_, i_move_arg_, ...) \
    RP_CALL(i_func_, __VA_ARGS__, i_move_arg_)

/**
 ** @brief Places argument @c i_move_arg at the end of a @c __VA_ARGS__ list
 ** while also having one argument at the beginning of that list
 **/
#define RP_END_OF_ARGLIST1(i_func_, i_arg1_, i_move_arg_, ...) \
    RP_CALL(i_func_, i_arg1_, __VA_ARGS__, i_move_arg_)

/**
 ** @brief Places argument @c i_move_arg at the end of a @c __VA_ARGS__ list
 ** while also having two arguments at the beginning of that list
 **/
#define RP_END_OF_ARGLIST2(i_func_, i_arg1_, i_arg2_, i_move_arg_, ...)  \
    RP_CALL(i_func_, i_arg1_, i_arg2_, __VA_ARGS__, i_move_arg_)

/**
 ** @brief Places argument @c i_move_arg at the end of a @c __VA_ARGS__ list
 ** while also having three arguments at the beginning of that list
 **/
#define RP_END_OF_ARGLIST3(i_func_, i_arg1_, i_arg2_, i_arg3_, i_move_arg_, ...) \
    RP_CALL(i_func_, i_arg1_, i_arg2_, i_arg3_, __VA_ARGS__, i_move_arg_)

/**
 ** @brief Counts the number of arguments
 **
 ** This is the macro that actually counts the number of arguments that are passed to it and returns it. Works for empty argument list too
 ** Max number of arguments that this macro will currently work for is 36. If given an empty argument list it returns 0.
 ** @param ... The arguments list whose number of arguments we need counted.
 **
 **/
#define RF_NARG(...) i_RP_NARG_1(i_RP_EMPTY_NARG(__VA_ARGS__), i_RP_NARG_NOEMPTY(__VA_ARGS__))
//!@}

    // Helper macro. Takes in the result of if the variadic list is empty (1) or not (0) and pastes it to RP_NARG_EMPTY_
    #define i_RP_NARG_1(B__, V__) i_RP_NARG_2( i_RP_PASTE2(i_RP_NARG_EMPTY_, B__), V__)
    // Helper macro. Basically decides what RP_NARG returns, which is either __V__ the value of RF_NARG_NOEMPTY or 0 in the case of NARG_EMPTY() evaluating to 0
    #define i_RP_NARG_2(B__, V__) B__(V__)

/**
 ** @ingroup RFpreprocessor_default_args_g_r_p
 ** @brief Selects an appropriate function depending on the number of arguments
 **
 ** This macro selects the function name according to the arguments given and passes both the name and the arguments to the selected function.
 ** Basically what this macro does is paste the token of the name with the token of the function number and hence issue a call to the corresponding
 ** function.
 ** @param i_FUNCNAME_ The name of the function
 ** @param ... Pass the arguments to the function here. The arguments passed NEED to be no more than the arguments defined for the same function with #RF_DECLARE_DFUNCXX
 **            and also no less than the number of MaxArguments-DefaultArguments. Calling this macro with wrong number of arguments will result in compile error.
 **
 **/
#define RF_SELECT_FUNC(i_FUNCNAME_,...) RP_SELECT_FUNC(i_FUNCNAME_,RF_NARG(__VA_ARGS__), __VA_ARGS__)
#define RF_SELECT_FUNC2(i_FUNCNAME_,...) RP_SELECT_FUNC2(i_FUNCNAME_,RF_NARG(__VA_ARGS__), __VA_ARGS__)


//This macro helps select the function to run
#define  RP_SELECT_FUNC(FUNCNAME_,ARGSN_,...)   RP_RUN_FUNC( i_RP_PASTE2(FUNCNAME_,ARGSN_),__VA_ARGS__)
#define  RP_SELECT_FUNC2(FUNCNAME_,ARGSN_,...)   RP_RUN_FUNC2( i_RP_PASTE2(FUNCNAME_,ARGSN_),__VA_ARGS__)
//This macro runs the function take from select function with the given argument
#define  RP_RUN_FUNC(FUNCNAME_,...)    FUNCNAME_(__VA_ARGS__)
#define  RP_RUN_FUNC2(FUNCNAME_,...)   FUNCNAME_(__VA_ARGS__)
//This macro selects a function if I_COND is met. Assumes selecting the function means 1 and not means 0
#define i_RP_SELECT_FUNC_IF(i_FUNCNAME,i_COND,...)  i_RP_PASTE2(i_FUNCNAME,i_COND)(__VA_ARGS__)
#define i_RP_SELECT_FUNC_IF2(i_FUNCNAME,i_COND,...)  i_RP_PASTE2_2(i_FUNCNAME,i_COND)(__VA_ARGS__)
#define i_RP_SELECT_FUNC_IF3(i_FUNCNAME,i_COND,...)  i_RP_PASTE2_3(i_FUNCNAME,i_COND)(__VA_ARGS__) 

//This macro helps select the function if the number of arguments is i_NARG
#define RP_SELECT_FUNC_IF_NARGIS(i_FUNCNAME,i_NARG, ...)    i_RP_SELECT_FUNC_IF(i_FUNCNAME,RP_NARG_IS(i_NARG,__VA_ARGS__),__VA_ARGS__)
#define RP_SELECT_FUNC_IF_NARGIS2(i_FUNCNAME,i_NARG, ...)    i_RP_SELECT_FUNC_IF2(i_FUNCNAME,RP_NARG_IS(i_NARG,__VA_ARGS__),__VA_ARGS__)
#define RP_SELECT_FUNC_IF_NARGIS3(i_FUNCNAME,i_NARG, ...)    i_RP_SELECT_FUNC_IF3(i_FUNCNAME,RP_NARG_IS(i_NARG,__VA_ARGS__),__VA_ARGS__)
//The macro below return true(token 1) or false (token 0) depending on whether the number of arguments is the one given at i_NARG
#define RP_NARG_IS(i_NARG,...)    i_RP_NARG_IS(RF_NARG(__VA_ARGS__),i_NARG)
#define i_RP_NARG_IS(i_WANTED,i_GOT)    RP_EQ(i_WANTED,i_GOT)

//This macro help select the function if the number of arguments is greater than the given one
#define RF_SELECT_FUNC_IF_NARGGT(i_FUNCNAME,i_NARG,...) i_RP_SELECT_FUNC_IF(i_FUNCNAME,RP_NARG_GT(i_NARG,__VA_ARGS__),__VA_ARGS__)
#define RF_SELECT_FUNC_IF_NARGGT2(i_FUNCNAME,i_NARG,...) i_RP_SELECT_FUNC_IF2(i_FUNCNAME,RP_NARG_GT2(i_NARG,__VA_ARGS__),__VA_ARGS__) //second is for a second macro expansion from the same macro
#define RF_SELECT_FUNC_IF_NARGGT3(i_FUNCNAME,i_NARG,...) i_RP_SELECT_FUNC_IF3(i_FUNCNAME,RP_NARG_GT3(i_NARG,__VA_ARGS__),__VA_ARGS__)

//The macro below returns true(token 1) or false(token0) depending on whether the number of args is greater than the one given at i_NARG
#define i_RP_NARG_GT(i_WANTED,i_GOT)    RP_GT(i_WANTED,i_GOT)
#define i_RP_NARG_GT2(i_WANTED,i_GOT)    RP_GT2(i_WANTED,i_GOT)
#define i_RP_NARG_GT3(i_WANTED,i_GOT)    RP_GT3(i_WANTED,i_GOT)
#define RP_NARG_GT(i_NARG,...) i_RP_NARG_GT(RF_NARG(__VA_ARGS__),i_NARG)
#define RP_NARG_GT2(i_NARG,...) i_RP_NARG_GT(RF_NARG(__VA_ARGS__),i_NARG)
#define RP_NARG_GT3(i_NARG,...) i_RP_NARG_GT(RF_NARG(__VA_ARGS__),i_NARG)



