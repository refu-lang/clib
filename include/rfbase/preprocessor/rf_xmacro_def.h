/**
 * @author: Lefteris Karapetsas
 * @licence: BSD3 (Check repository root for details)
 */

#include "rf_xmacro_sub.h"//to be able to do subtraction with the preprocessor
#include "rf_xmacro_gt.h"//to be able to do greater than comparisons with the preprocessor
#include "rf_xmacro_lt.h"//to be able to do less than comparisons with the preprocessor

#include "rf_xmacro_eq.h"//to be able to do equality comparisons with the preprocessor

#include "rf_xmacro_argcount.h"//to be able to count the number of arguments

#include "rf_xmacro_utils.h"//to use util macros for token pasting


///These macros here are used in order to pickup the correct function macro definition
#define i_RP_DEF_CHECK2(A__,B__)   RP_GT(B__,A__)
#define i_RP_DEF_CHECK1(A__,B__)   RP_LT(B__,A__)
#define i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,thisArgN__)  i_RP_DEF_CHECK1(RP_SUB(maxArgsN__,defArgsN__),thisArgN__)
#define i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,thisArgN__)  i_RP_DEF_CHECK2(RP_SUB(maxArgsN__,defArgsN__),thisArgN__)
#define i_RP_PICK_FUNC_DEF(funcmacro__,eqresult__,cmpresult__)  i_RP_PASTE3(funcmacro__,eqresult__,cmpresult__)


///These macros are used to reverse a list of arguments. They are used to obtain the appropriate default arguments
#define i_REVERSE36(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,def23,def24,def25,def26,def27,def28,def29,def30,def31,def32,def33,def34,def35,def36,...)   def36,def35,def34,def33,def32,def31,def30,def29,def28,def27,def26,def25,def24,def23,def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE35(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,def23,def24,def25,def26,def27,def28,def29,def30,def31,def32,def33,def34,def35,...)   def35,def34,def33,def32,def31,def30,def29,def28,def27,def26,def25,def24,def23,def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE34(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,def23,def24,def25,def26,def27,def28,def29,def30,def31,def32,def33,def34,...)   def34,def33,def32,def31,def30,def29,def28,def27,def26,def25,def24,def23,def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE33(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,def23,def24,def25,def26,def27,def28,def29,def30,def31,def32,def33,...)   def33,def32,def31,def30,def29,def28,def27,def26,def25,def24,def23,def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE32(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,def23,def24,def25,def26,def27,def28,def29,def30,def31,def32,...)   def32,def31,def30,def29,def28,def27,def26,def25,def24,def23,def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE31(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,def23,def24,def25,def26,def27,def28,def29,def30,def31,...)   def31,def30,def29,def28,def27,def26,def25,def24,def23,def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE30(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,def23,def24,def25,def26,def27,def28,def29,def30,...)   def30,def29,def28,def27,def26,def25,def24,def23,def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE29(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,def23,def24,def25,def26,def27,def28,def29,...)   def29,def28,def27,def26,def25,def24,def23,def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE28(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,def23,def24,def25,def26,def27,def28,...)   def28,def27,def26,def25,def24,def23,def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE27(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,def23,def24,def25,def26,def27,...)   def27,def26,def25,def24,def23,def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE26(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,def23,def24,def25,def26,...)   def26,def25,def24,def23,def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE25(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,def23,def24,def25,...)   def25,def24,def23,def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE24(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,def23,def24,...)   def24,def23,def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE23(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,def23,...)   def23,def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE22(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,def22,...)   def22,def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE21(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,def21,...)   def21,def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE20(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,def20,...)   def20,def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE19(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,def19,...)   def19,def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE18(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,def18,...)   def18,def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE17(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,def17,...)   def17,def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE16(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,def16,...)   def16,def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE15(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,def15,...)   def15,def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE14(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,def14,...)   def14,def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE13(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,def13,...)   def13,def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE12(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,def12,...)   def12,def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE11(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,def11,...)   def11,def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE10(def1,def2,def3,def4,def5,def6,def7,def8,def9,def10,...)   def10,def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE9(def1,def2,def3,def4,def5,def6,def7,def8,def9,...)   def9,def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE8(def1,def2,def3,def4,def5,def6,def7,def8,...)   def8,def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE7(def1,def2,def3,def4,def5,def6,def7,...)   def7,def6,def5,def4,def3,def2,def1,
#define i_REVERSE6(def1,def2,def3,def4,def5,def6,...)   def6,def5,def4,def3,def2,def1,
#define i_REVERSE5(def1,def2,def3,def4,def5,...)   def5,def4,def3,def2,def1,
#define i_REVERSE4(def1,def2,def3,def4,...)   def4,def3,def2,def1,
#define i_REVERSE3(def1,def2,def3,...)   def3,def2,def1,
#define i_REVERSE2(def1,def2,...)   def2,def1,
#define i_REVERSE1(def1,...)   def1,
#define i_REVERSE0(...)

///The following is commented because I used to have it like that to reverse the arguments list. Keeping an example in case I want to remember how to do it in the future
/*
#define i_FIRST2_IMP(_1_,_2_,...)   ,_1_,_2_
#define i_FIRST2(...)   i_FIRST2_IMP(__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_2(defArgsN__,...)   i_FIRST2(i_RP_PASTE2(i_REVERSE,defArgsN__)(__VA_ARGS__))
*/

/**
 **These macros are used to get the appropriate number of default arguments
 **
 **/


/**
 ** Macros to get the appropriate number of arguments for 36
 **
 **/
#define i_AFTER_FIRST36(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,p35__,p36__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST36_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,p35__,p36__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST36(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,p35__,p36__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,p35__,p36__
#define i_FIRST36_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,p35__,p36__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,p35__,p36__
#define i_LAST36(defArgsN__,...)   i_LAST36_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,36))(36,__VA_ARGS__)
#define i_LAST36_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST36_NOCOMMA(defArgsN__,...)   i_LAST36_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,36))(36,__VA_ARGS__)
#define i_LAST36_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_36_LAST0(defArgsN__,...)   i_LAST36(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_36_LAST1(defArgsN__,...)   i_LAST36_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 35
 **
 **/
#define i_AFTER_FIRST35(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,p35__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST35_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,p35__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST35(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,p35__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,p35__
#define i_FIRST35_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,p35__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,p35__
#define i_LAST35(defArgsN__,...)   i_LAST35_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,35))(35,__VA_ARGS__)
#define i_LAST35_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST35_NOCOMMA(defArgsN__,...)   i_LAST35_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,35))(35,__VA_ARGS__)
#define i_LAST35_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_35_LAST0(defArgsN__,...)   i_LAST35(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_35_LAST1(defArgsN__,...)   i_LAST35_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 34
 **
 **/
#define i_AFTER_FIRST34(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST34_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST34(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__
#define i_FIRST34_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,p34__
#define i_LAST34(defArgsN__,...)   i_LAST34_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,34))(34,__VA_ARGS__)
#define i_LAST34_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST34_NOCOMMA(defArgsN__,...)   i_LAST34_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,34))(34,__VA_ARGS__)
#define i_LAST34_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_34_LAST0(defArgsN__,...)   i_LAST34(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_34_LAST1(defArgsN__,...)   i_LAST34_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 33
 **
 **/
#define i_AFTER_FIRST33(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST33_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST33(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__
#define i_FIRST33_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,p33__
#define i_LAST33(defArgsN__,...)   i_LAST33_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,33))(33,__VA_ARGS__)
#define i_LAST33_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST33_NOCOMMA(defArgsN__,...)   i_LAST33_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,33))(33,__VA_ARGS__)
#define i_LAST33_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_33_LAST0(defArgsN__,...)   i_LAST33(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_33_LAST1(defArgsN__,...)   i_LAST33_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 32
 **
 **/
#define i_AFTER_FIRST32(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST32_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST32(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__
#define i_FIRST32_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,p32__
#define i_LAST32(defArgsN__,...)   i_LAST32_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,32))(32,__VA_ARGS__)
#define i_LAST32_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST32_NOCOMMA(defArgsN__,...)   i_LAST32_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,32))(32,__VA_ARGS__)
#define i_LAST32_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_32_LAST0(defArgsN__,...)   i_LAST32(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_32_LAST1(defArgsN__,...)   i_LAST32_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 31
 **
 **/
#define i_AFTER_FIRST31(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST31_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST31(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__
#define i_FIRST31_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,p31__
#define i_LAST31(defArgsN__,...)   i_LAST31_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,31))(31,__VA_ARGS__)
#define i_LAST31_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST31_NOCOMMA(defArgsN__,...)   i_LAST31_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,31))(31,__VA_ARGS__)
#define i_LAST31_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_31_LAST0(defArgsN__,...)   i_LAST31(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_31_LAST1(defArgsN__,...)   i_LAST31_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 30
 **
 **/
#define i_AFTER_FIRST30(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST30_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST30(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__
#define i_FIRST30_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,p30__
#define i_LAST30(defArgsN__,...)   i_LAST30_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,30))(30,__VA_ARGS__)
#define i_LAST30_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST30_NOCOMMA(defArgsN__,...)   i_LAST30_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,30))(30,__VA_ARGS__)
#define i_LAST30_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_30_LAST0(defArgsN__,...)   i_LAST30(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_30_LAST1(defArgsN__,...)   i_LAST30_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 29
 **
 **/
#define i_AFTER_FIRST29(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST29_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST29(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__
#define i_FIRST29_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,p29__
#define i_LAST29(defArgsN__,...)   i_LAST29_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,29))(29,__VA_ARGS__)
#define i_LAST29_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST29_NOCOMMA(defArgsN__,...)   i_LAST29_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,29))(29,__VA_ARGS__)
#define i_LAST29_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_29_LAST0(defArgsN__,...)   i_LAST29(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_29_LAST1(defArgsN__,...)   i_LAST29_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 28
 **
 **/
#define i_AFTER_FIRST28(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST28_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST28(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__
#define i_FIRST28_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,p28__
#define i_LAST28(defArgsN__,...)   i_LAST28_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,28))(28,__VA_ARGS__)
#define i_LAST28_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST28_NOCOMMA(defArgsN__,...)   i_LAST28_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,28))(28,__VA_ARGS__)
#define i_LAST28_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_28_LAST0(defArgsN__,...)   i_LAST28(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_28_LAST1(defArgsN__,...)   i_LAST28_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 27
 **
 **/
#define i_AFTER_FIRST27(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST27_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST27(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__
#define i_FIRST27_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,p27__
#define i_LAST27(defArgsN__,...)   i_LAST27_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,27))(27,__VA_ARGS__)
#define i_LAST27_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST27_NOCOMMA(defArgsN__,...)   i_LAST27_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,27))(27,__VA_ARGS__)
#define i_LAST27_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_27_LAST0(defArgsN__,...)   i_LAST27(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_27_LAST1(defArgsN__,...)   i_LAST27_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 26
 **
 **/
#define i_AFTER_FIRST26(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST26_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST26(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__
#define i_FIRST26_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,p26__
#define i_LAST26(defArgsN__,...)   i_LAST26_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,26))(26,__VA_ARGS__)
#define i_LAST26_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST26_NOCOMMA(defArgsN__,...)   i_LAST26_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,26))(26,__VA_ARGS__)
#define i_LAST26_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_26_LAST0(defArgsN__,...)   i_LAST26(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_26_LAST1(defArgsN__,...)   i_LAST26_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 25
 **
 **/
#define i_AFTER_FIRST25(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST25_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST25(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__
#define i_FIRST25_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,p25__
#define i_LAST25(defArgsN__,...)   i_LAST25_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,25))(25,__VA_ARGS__)
#define i_LAST25_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST25_NOCOMMA(defArgsN__,...)   i_LAST25_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,25))(25,__VA_ARGS__)
#define i_LAST25_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_25_LAST0(defArgsN__,...)   i_LAST25(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_25_LAST1(defArgsN__,...)   i_LAST25_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 24
 **
 **/
#define i_AFTER_FIRST24(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST24_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST24(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__
#define i_FIRST24_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,p24__
#define i_LAST24(defArgsN__,...)   i_LAST24_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,24))(24,__VA_ARGS__)
#define i_LAST24_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST24_NOCOMMA(defArgsN__,...)   i_LAST24_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,24))(24,__VA_ARGS__)
#define i_LAST24_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_24_LAST0(defArgsN__,...)   i_LAST24(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_24_LAST1(defArgsN__,...)   i_LAST24_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 23
 **
 **/
#define i_AFTER_FIRST23(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST23_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST23(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__
#define i_FIRST23_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,p23__
#define i_LAST23(defArgsN__,...)   i_LAST23_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,23))(23,__VA_ARGS__)
#define i_LAST23_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST23_NOCOMMA(defArgsN__,...)   i_LAST23_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,23))(23,__VA_ARGS__)
#define i_LAST23_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_23_LAST0(defArgsN__,...)   i_LAST23(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_23_LAST1(defArgsN__,...)   i_LAST23_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 22
 **
 **/
#define i_AFTER_FIRST22(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST22_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST22(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__
#define i_FIRST22_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,p22__
#define i_LAST22(defArgsN__,...)   i_LAST22_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,22))(22,__VA_ARGS__)
#define i_LAST22_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST22_NOCOMMA(defArgsN__,...)   i_LAST22_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,22))(22,__VA_ARGS__)
#define i_LAST22_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_22_LAST0(defArgsN__,...)   i_LAST22(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_22_LAST1(defArgsN__,...)   i_LAST22_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 21
 **
 **/
#define i_AFTER_FIRST21(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST21_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST21(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__
#define i_FIRST21_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,p21__
#define i_LAST21(defArgsN__,...)   i_LAST21_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,21))(21,__VA_ARGS__)
#define i_LAST21_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST21_NOCOMMA(defArgsN__,...)   i_LAST21_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,21))(21,__VA_ARGS__)
#define i_LAST21_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_21_LAST0(defArgsN__,...)   i_LAST21(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_21_LAST1(defArgsN__,...)   i_LAST21_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 20
 **
 **/
#define i_AFTER_FIRST20(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST20_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST20(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__
#define i_FIRST20_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,p20__
#define i_LAST20(defArgsN__,...)   i_LAST20_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,20))(20,__VA_ARGS__)
#define i_LAST20_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST20_NOCOMMA(defArgsN__,...)   i_LAST20_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,20))(20,__VA_ARGS__)
#define i_LAST20_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_20_LAST0(defArgsN__,...)   i_LAST20(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_20_LAST1(defArgsN__,...)   i_LAST20_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 19
 **
 **/
#define i_AFTER_FIRST19(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST19_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST19(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__
#define i_FIRST19_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,p19__
#define i_LAST19(defArgsN__,...)   i_LAST19_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,19))(19,__VA_ARGS__)
#define i_LAST19_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST19_NOCOMMA(defArgsN__,...)   i_LAST19_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,19))(19,__VA_ARGS__)
#define i_LAST19_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_19_LAST0(defArgsN__,...)   i_LAST19(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_19_LAST1(defArgsN__,...)   i_LAST19_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 18
 **
 **/
#define i_AFTER_FIRST18(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST18_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST18(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__
#define i_FIRST18_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,p18__
#define i_LAST18(defArgsN__,...)   i_LAST18_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,18))(18,__VA_ARGS__)
#define i_LAST18_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST18_NOCOMMA(defArgsN__,...)   i_LAST18_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,18))(18,__VA_ARGS__)
#define i_LAST18_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_18_LAST0(defArgsN__,...)   i_LAST18(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_18_LAST1(defArgsN__,...)   i_LAST18_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 17
 **
 **/
#define i_AFTER_FIRST17(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST17_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST17(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__
#define i_FIRST17_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,p17__
#define i_LAST17(defArgsN__,...)   i_LAST17_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,17))(17,__VA_ARGS__)
#define i_LAST17_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST17_NOCOMMA(defArgsN__,...)   i_LAST17_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,17))(17,__VA_ARGS__)
#define i_LAST17_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_17_LAST0(defArgsN__,...)   i_LAST17(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_17_LAST1(defArgsN__,...)   i_LAST17_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 16
 **
 **/
#define i_AFTER_FIRST16(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST16_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST16(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__
#define i_FIRST16_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,p16__
#define i_LAST16(defArgsN__,...)   i_LAST16_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,16))(16,__VA_ARGS__)
#define i_LAST16_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST16_NOCOMMA(defArgsN__,...)   i_LAST16_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,16))(16,__VA_ARGS__)
#define i_LAST16_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_16_LAST0(defArgsN__,...)   i_LAST16(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_16_LAST1(defArgsN__,...)   i_LAST16_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 15
 **
 **/
#define i_AFTER_FIRST15(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST15_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST15(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__
#define i_FIRST15_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,p15__
#define i_LAST15(defArgsN__,...)   i_LAST15_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,15))(15,__VA_ARGS__)
#define i_LAST15_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST15_NOCOMMA(defArgsN__,...)   i_LAST15_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,15))(15,__VA_ARGS__)
#define i_LAST15_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_15_LAST0(defArgsN__,...)   i_LAST15(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_15_LAST1(defArgsN__,...)   i_LAST15_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 14
 **
 **/
#define i_AFTER_FIRST14(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST14_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST14(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__
#define i_FIRST14_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,p14__
#define i_LAST14(defArgsN__,...)   i_LAST14_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,14))(14,__VA_ARGS__)
#define i_LAST14_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST14_NOCOMMA(defArgsN__,...)   i_LAST14_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,14))(14,__VA_ARGS__)
#define i_LAST14_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_14_LAST0(defArgsN__,...)   i_LAST14(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_14_LAST1(defArgsN__,...)   i_LAST14_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 13
 **
 **/
#define i_AFTER_FIRST13(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST13_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST13(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__
#define i_FIRST13_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,p13__
#define i_LAST13(defArgsN__,...)   i_LAST13_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,13))(13,__VA_ARGS__)
#define i_LAST13_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST13_NOCOMMA(defArgsN__,...)   i_LAST13_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,13))(13,__VA_ARGS__)
#define i_LAST13_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_13_LAST0(defArgsN__,...)   i_LAST13(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_13_LAST1(defArgsN__,...)   i_LAST13_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 12
 **
 **/
#define i_AFTER_FIRST12(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST12_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST12(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__
#define i_FIRST12_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,p12__
#define i_LAST12(defArgsN__,...)   i_LAST12_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,12))(12,__VA_ARGS__)
#define i_LAST12_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST12_NOCOMMA(defArgsN__,...)   i_LAST12_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,12))(12,__VA_ARGS__)
#define i_LAST12_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_12_LAST0(defArgsN__,...)   i_LAST12(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_12_LAST1(defArgsN__,...)   i_LAST12_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 11
 **
 **/
#define i_AFTER_FIRST11(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST11_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST11(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__
#define i_FIRST11_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,p11__
#define i_LAST11(defArgsN__,...)   i_LAST11_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,11))(11,__VA_ARGS__)
#define i_LAST11_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST11_NOCOMMA(defArgsN__,...)   i_LAST11_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,11))(11,__VA_ARGS__)
#define i_LAST11_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_11_LAST0(defArgsN__,...)   i_LAST11(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_11_LAST1(defArgsN__,...)   i_LAST11_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 10
 **
 **/
#define i_AFTER_FIRST10(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST10_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST10(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__
#define i_FIRST10_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,p10__
#define i_LAST10(defArgsN__,...)   i_LAST10_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,10))(10,__VA_ARGS__)
#define i_LAST10_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST10_NOCOMMA(defArgsN__,...)   i_LAST10_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,10))(10,__VA_ARGS__)
#define i_LAST10_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_10_LAST0(defArgsN__,...)   i_LAST10(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_10_LAST1(defArgsN__,...)   i_LAST10_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 9
 **
 **/
#define i_AFTER_FIRST9(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST9_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST9(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__
#define i_FIRST9_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,p9__
#define i_LAST9(defArgsN__,...)   i_LAST9_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,9))(9,__VA_ARGS__)
#define i_LAST9_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST9_NOCOMMA(defArgsN__,...)   i_LAST9_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,9))(9,__VA_ARGS__)
#define i_LAST9_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_9_LAST0(defArgsN__,...)   i_LAST9(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_9_LAST1(defArgsN__,...)   i_LAST9_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 8
 **
 **/
#define i_AFTER_FIRST8(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST8_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST8(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__
#define i_FIRST8_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__,p8__
#define i_LAST8(defArgsN__,...)   i_LAST8_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,8))(8,__VA_ARGS__)
#define i_LAST8_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST8_NOCOMMA(defArgsN__,...)   i_LAST8_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,8))(8,__VA_ARGS__)
#define i_LAST8_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_8_LAST0(defArgsN__,...)   i_LAST8(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_8_LAST1(defArgsN__,...)   i_LAST8_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 7
 **
 **/
#define i_AFTER_FIRST7(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST7_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,p7__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST7(p1__,p2__,p3__,p4__,p5__,p6__,p7__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__,p7__
#define i_FIRST7_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,p7__,...)  p1__,p2__,p3__,p4__,p5__,p6__,p7__
#define i_LAST7(defArgsN__,...)   i_LAST7_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,7))(7,__VA_ARGS__)
#define i_LAST7_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST7_NOCOMMA(defArgsN__,...)   i_LAST7_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,7))(7,__VA_ARGS__)
#define i_LAST7_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_7_LAST0(defArgsN__,...)   i_LAST7(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_7_LAST1(defArgsN__,...)   i_LAST7_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 6
 **
 **/
#define i_AFTER_FIRST6(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST6_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,p6__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST6(p1__,p2__,p3__,p4__,p5__,p6__,...)  ,p1__,p2__,p3__,p4__,p5__,p6__
#define i_FIRST6_NOCOMMA(p1__,p2__,p3__,p4__,p5__,p6__,...)  p1__,p2__,p3__,p4__,p5__,p6__
#define i_LAST6(defArgsN__,...)   i_LAST6_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,6))(6,__VA_ARGS__)
#define i_LAST6_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST6_NOCOMMA(defArgsN__,...)   i_LAST6_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,6))(6,__VA_ARGS__)
#define i_LAST6_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_6_LAST0(defArgsN__,...)   i_LAST6(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_6_LAST1(defArgsN__,...)   i_LAST6_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 5
 **
 **/
#define i_AFTER_FIRST5(argsN__,p1__,p2__,p3__,p4__,p5__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST5_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,p5__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST5(p1__,p2__,p3__,p4__,p5__,...)  ,p1__,p2__,p3__,p4__,p5__
#define i_FIRST5_NOCOMMA(p1__,p2__,p3__,p4__,p5__,...)  p1__,p2__,p3__,p4__,p5__
#define i_LAST5(defArgsN__,...)   i_LAST5_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,5))(5,__VA_ARGS__)
#define i_LAST5_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST5_NOCOMMA(defArgsN__,...)   i_LAST5_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,5))(5,__VA_ARGS__)
#define i_LAST5_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_5_LAST0(defArgsN__,...)   i_LAST5(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_5_LAST1(defArgsN__,...)   i_LAST5_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 4
 **
 **/
#define i_AFTER_FIRST4(argsN__,p1__,p2__,p3__,p4__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST4_NOCOMMA(argsN__,p1__,p2__,p3__,p4__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST4(p1__,p2__,p3__,p4__,...)  ,p1__,p2__,p3__,p4__
#define i_FIRST4_NOCOMMA(p1__,p2__,p3__,p4__,...)  p1__,p2__,p3__,p4__
#define i_LAST4(defArgsN__,...)   i_LAST4_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,4))(4,__VA_ARGS__)
#define i_LAST4_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST4_NOCOMMA(defArgsN__,...)   i_LAST4_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,4))(4,__VA_ARGS__)
#define i_LAST4_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_4_LAST0(defArgsN__,...)   i_LAST4(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_4_LAST1(defArgsN__,...)   i_LAST4_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 3
 **
 **/
#define i_AFTER_FIRST3(argsN__,p1__,p2__,p3__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST3_NOCOMMA(argsN__,p1__,p2__,p3__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST3(p1__,p2__,p3__,...)  ,p1__,p2__,p3__
#define i_FIRST3_NOCOMMA(p1__,p2__,p3__,...)  p1__,p2__,p3__
#define i_LAST3(defArgsN__,...)   i_LAST3_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,3))(3,__VA_ARGS__)
#define i_LAST3_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST3_NOCOMMA(defArgsN__,...)   i_LAST3_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,3))(3,__VA_ARGS__)
#define i_LAST3_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_3_LAST0(defArgsN__,...)   i_LAST3(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_3_LAST1(defArgsN__,...)   i_LAST3_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 2
 **
 **/
#define i_AFTER_FIRST2(argsN__,p1__,p2__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST2_NOCOMMA(argsN__,p1__,p2__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST2(p1__,p2__,...)  ,p1__,p2__
#define i_FIRST2_NOCOMMA(p1__,p2__,...)  p1__,p2__
#define i_LAST2(defArgsN__,...)   i_LAST2_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,2))(2,__VA_ARGS__)
#define i_LAST2_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST2_NOCOMMA(defArgsN__,...)   i_LAST2_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,2))(2,__VA_ARGS__)
#define i_LAST2_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_2_LAST0(defArgsN__,...)   i_LAST2(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_2_LAST1(defArgsN__,...)   i_LAST2_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 1
 **
 **/
#define i_AFTER_FIRST1(argsN__,p1__,...)   i_FIRST##argsN__(__VA_ARGS__)
#define i_AFTER_FIRST1_NOCOMMA(argsN__,p1__,...)   i_FIRST##argsN__##_NOCOMMA(__VA_ARGS__)
#define i_FIRST1(p1__,...)  ,p1__
#define i_FIRST1_NOCOMMA(p1__,...)  p1__
#define i_LAST1(defArgsN__,...)   i_LAST1_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,1))(1,__VA_ARGS__)
#define i_LAST1_IMP(id__,subres__)    i_RP_PASTE2(id__,subres__)
#define i_LAST1_NOCOMMA(defArgsN__,...)   i_LAST1_NOCCOMA_IMP(i_AFTER_FIRST,RP_SUB(defArgsN__,1))(1,__VA_ARGS__)
#define i_LAST1_NOCCOMA_IMP(id__,subres__)    i_RP_PASTE3(id__,subres__,_NOCOMMA)
#define i_RP_DEFAULT_ARGS_1_LAST0(defArgsN__,...)   i_LAST1(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_1_LAST1(defArgsN__,...)   i_LAST1_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** Macros to get the appropriate number of arguments for 0
 **
 **/
#define i_AFTER_FIRST0_IMP(argsN__,...)   ,__VA_ARGS__
#define i_AFTER_FIRST0_NOCOMMA_IMP(argsN__,...)   __VA_ARGS__
#define i_AFTER_FIRST0(...)   i_AFTER_FIRST0_IMP(__VA_ARGS__)
#define i_AFTER_FIRST0_NOCOMMA(...)   i_AFTER_FIRST0_NOCOMMA_IMP(__VA_ARGS__)
#define i_LAST0(defArgsN__,...)
#define i_LAST0_IMP(id__,subres__)
#define i_LAST0_NOCOMMA(defArgsN__,...)
#define i_LAST0_NOCCOMA_IMP(id__,subres__)
#define i_RP_DEFAULT_ARGS_0_LAST0(defArgsN__,...)   i_LAST0(defArgsN__,__VA_ARGS__)
#define i_RP_DEFAULT_ARGS_0_LAST1(defArgsN__,...)   i_LAST0_NOCOMMA(defArgsN__,__VA_ARGS__)

/**
 ** This macro gets the appropriate default arguments macro
 **
 **/
#define i_RP_GET_DEFAULT_ARG(args__,maxArgsN__) i_RP_GET_DEFAULT_ARG_IMP(i_RP_DEFAULT_ARGS_,args__,_LAST,RP_EQ(args__,maxArgsN__))
#define i_RP_GET_DEFAULT_ARG_IMP(macronarf__,args__,identifier__,last__)    i_RP_PASTE4(macronarf__,args__,identifier__,last__)


/**
 ** These macros are used when you want to define a function in a source file with default arguments and want to avoid lots of typing
 ** Function definition macros for 36 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC36(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,arg__36Type,arg__36Name,...)\
i_RP_DEFINE_FUNC35(funcNarf__,retType__,36,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,__VA_ARGS__)\
retType__ funcNarf__##36(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name,arg__33Type arg__33Name,arg__34Type arg__34Name,arg__35Type arg__35Name,arg__36Type arg__36Name)


#define i_RP_DEFINE_FUNC36(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,arg__36Type,arg__36Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC36_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,36),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,36))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,arg__36Type,arg__36Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC36_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,arg__36Type,arg__36Name,...)\
inline retType__  funcNarf__##36(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name,arg__33Type arg__33Name,arg__34Type arg__34Name,arg__35Type arg__35Name,arg__36Type arg__36Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name,arg__30Name,arg__31Name,arg__32Name,arg__33Name,arg__34Name,arg__35Name,arg__36Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,36),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC36_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,arg__36Type,arg__36Name,...)\
inline retType__  funcNarf__##36(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name,arg__33Type arg__33Name,arg__34Type arg__34Name,arg__35Type arg__35Name,arg__36Type arg__36Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name,arg__30Name,arg__31Name,arg__32Name,arg__33Name,arg__34Name,arg__35Name,arg__36Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,36),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC35(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC36_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,arg__36Type,arg__36Name,...)
#define i_RP_DEFINE_FUNC36_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,arg__36Type,arg__36Name,...)



/**
 ** Function definition macros for 35 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC35(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,...)\
i_RP_DEFINE_FUNC34(funcNarf__,retType__,35,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,__VA_ARGS__)\
retType__ funcNarf__##35(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name,arg__33Type arg__33Name,arg__34Type arg__34Name,arg__35Type arg__35Name)


#define i_RP_DEFINE_FUNC35(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC35_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,35),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,35))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC35_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,...)\
inline retType__  funcNarf__##35(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name,arg__33Type arg__33Name,arg__34Type arg__34Name,arg__35Type arg__35Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name,arg__30Name,arg__31Name,arg__32Name,arg__33Name,arg__34Name,arg__35Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,35),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC35_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,...)\
inline retType__  funcNarf__##35(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name,arg__33Type arg__33Name,arg__34Type arg__34Name,arg__35Type arg__35Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name,arg__30Name,arg__31Name,arg__32Name,arg__33Name,arg__34Name,arg__35Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,35),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC34(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC35_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,...)
#define i_RP_DEFINE_FUNC35_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,arg__35Type,arg__35Name,...)



/**
 ** Function definition macros for 34 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC34(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,...)\
i_RP_DEFINE_FUNC33(funcNarf__,retType__,34,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,__VA_ARGS__)\
retType__ funcNarf__##34(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name,arg__33Type arg__33Name,arg__34Type arg__34Name)


#define i_RP_DEFINE_FUNC34(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC34_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,34),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,34))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC34_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,...)\
inline retType__  funcNarf__##34(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name,arg__33Type arg__33Name,arg__34Type arg__34Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name,arg__30Name,arg__31Name,arg__32Name,arg__33Name,arg__34Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,34),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC34_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,...)\
inline retType__  funcNarf__##34(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name,arg__33Type arg__33Name,arg__34Type arg__34Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name,arg__30Name,arg__31Name,arg__32Name,arg__33Name,arg__34Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,34),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC33(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC34_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,...)
#define i_RP_DEFINE_FUNC34_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,arg__34Type,arg__34Name,...)



/**
 ** Function definition macros for 33 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC33(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,...)\
i_RP_DEFINE_FUNC32(funcNarf__,retType__,33,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,__VA_ARGS__)\
retType__ funcNarf__##33(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name,arg__33Type arg__33Name)


#define i_RP_DEFINE_FUNC33(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC33_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,33),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,33))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC33_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,...)\
inline retType__  funcNarf__##33(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name,arg__33Type arg__33Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name,arg__30Name,arg__31Name,arg__32Name,arg__33Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,33),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC33_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,...)\
inline retType__  funcNarf__##33(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name,arg__33Type arg__33Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name,arg__30Name,arg__31Name,arg__32Name,arg__33Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,33),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC32(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC33_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,...)
#define i_RP_DEFINE_FUNC33_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,arg__33Type,arg__33Name,...)



/**
 ** Function definition macros for 32 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC32(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,...)\
i_RP_DEFINE_FUNC31(funcNarf__,retType__,32,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,__VA_ARGS__)\
retType__ funcNarf__##32(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name)


#define i_RP_DEFINE_FUNC32(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC32_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,32),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,32))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC32_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,...)\
inline retType__  funcNarf__##32(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name,arg__30Name,arg__31Name,arg__32Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,32),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC32_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,...)\
inline retType__  funcNarf__##32(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name,arg__32Type arg__32Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name,arg__30Name,arg__31Name,arg__32Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,32),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC31(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC32_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,...)
#define i_RP_DEFINE_FUNC32_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,arg__32Type,arg__32Name,...)



/**
 ** Function definition macros for 31 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC31(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,...)\
i_RP_DEFINE_FUNC30(funcNarf__,retType__,31,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,__VA_ARGS__)\
retType__ funcNarf__##31(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name)


#define i_RP_DEFINE_FUNC31(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC31_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,31),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,31))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC31_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,...)\
inline retType__  funcNarf__##31(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name,arg__30Name,arg__31Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,31),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC31_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,...)\
inline retType__  funcNarf__##31(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name,arg__31Type arg__31Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name,arg__30Name,arg__31Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,31),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC30(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC31_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,...)
#define i_RP_DEFINE_FUNC31_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,arg__31Type,arg__31Name,...)



/**
 ** Function definition macros for 30 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC30(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,...)\
i_RP_DEFINE_FUNC29(funcNarf__,retType__,30,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,__VA_ARGS__)\
retType__ funcNarf__##30(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name)


#define i_RP_DEFINE_FUNC30(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC30_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,30),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,30))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC30_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,...)\
inline retType__  funcNarf__##30(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name,arg__30Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,30),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC30_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,...)\
inline retType__  funcNarf__##30(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name,arg__30Type arg__30Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name,arg__30Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,30),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC29(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC30_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,...)
#define i_RP_DEFINE_FUNC30_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,arg__30Type,arg__30Name,...)



/**
 ** Function definition macros for 29 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC29(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,...)\
i_RP_DEFINE_FUNC28(funcNarf__,retType__,29,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,__VA_ARGS__)\
retType__ funcNarf__##29(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name)


#define i_RP_DEFINE_FUNC29(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC29_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,29),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,29))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC29_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,...)\
inline retType__  funcNarf__##29(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,29),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC29_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,...)\
inline retType__  funcNarf__##29(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name,arg__29Type arg__29Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name,arg__29Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,29),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC28(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC29_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,...)
#define i_RP_DEFINE_FUNC29_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,arg__29Type,arg__29Name,...)



/**
 ** Function definition macros for 28 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC28(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,...)\
i_RP_DEFINE_FUNC27(funcNarf__,retType__,28,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,__VA_ARGS__)\
retType__ funcNarf__##28(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name)


#define i_RP_DEFINE_FUNC28(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC28_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,28),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,28))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC28_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,...)\
inline retType__  funcNarf__##28(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,28),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC28_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,...)\
inline retType__  funcNarf__##28(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name,arg__28Type arg__28Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name,arg__28Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,28),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC27(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC28_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,...)
#define i_RP_DEFINE_FUNC28_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,arg__28Type,arg__28Name,...)



/**
 ** Function definition macros for 27 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC27(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,...)\
i_RP_DEFINE_FUNC26(funcNarf__,retType__,27,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,__VA_ARGS__)\
retType__ funcNarf__##27(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name)


#define i_RP_DEFINE_FUNC27(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC27_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,27),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,27))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC27_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,...)\
inline retType__  funcNarf__##27(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,27),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC27_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,...)\
inline retType__  funcNarf__##27(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name,arg__27Type arg__27Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name,arg__27Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,27),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC26(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC27_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,...)
#define i_RP_DEFINE_FUNC27_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,arg__27Type,arg__27Name,...)



/**
 ** Function definition macros for 26 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC26(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,...)\
i_RP_DEFINE_FUNC25(funcNarf__,retType__,26,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,__VA_ARGS__)\
retType__ funcNarf__##26(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name)


#define i_RP_DEFINE_FUNC26(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC26_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,26),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,26))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC26_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,...)\
inline retType__  funcNarf__##26(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,26),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC26_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,...)\
inline retType__  funcNarf__##26(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name,arg__26Type arg__26Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name,arg__26Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,26),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC25(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC26_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,...)
#define i_RP_DEFINE_FUNC26_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,arg__26Type,arg__26Name,...)



/**
 ** Function definition macros for 25 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC25(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,...)\
i_RP_DEFINE_FUNC24(funcNarf__,retType__,25,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,__VA_ARGS__)\
retType__ funcNarf__##25(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name)


#define i_RP_DEFINE_FUNC25(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC25_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,25),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,25))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC25_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,...)\
inline retType__  funcNarf__##25(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,25),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC25_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,...)\
inline retType__  funcNarf__##25(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name,arg__25Type arg__25Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name,arg__25Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,25),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC24(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC25_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,...)
#define i_RP_DEFINE_FUNC25_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,arg__25Type,arg__25Name,...)



/**
 ** Function definition macros for 24 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC24(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,...)\
i_RP_DEFINE_FUNC23(funcNarf__,retType__,24,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,__VA_ARGS__)\
retType__ funcNarf__##24(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name)


#define i_RP_DEFINE_FUNC24(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC24_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,24),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,24))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC24_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,...)\
inline retType__  funcNarf__##24(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,24),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC24_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,...)\
inline retType__  funcNarf__##24(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name,arg__24Type arg__24Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name,arg__24Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,24),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC23(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC24_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,...)
#define i_RP_DEFINE_FUNC24_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,arg__24Type,arg__24Name,...)



/**
 ** Function definition macros for 23 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC23(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,...)\
i_RP_DEFINE_FUNC22(funcNarf__,retType__,23,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,__VA_ARGS__)\
retType__ funcNarf__##23(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name)


#define i_RP_DEFINE_FUNC23(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC23_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,23),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,23))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC23_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,...)\
inline retType__  funcNarf__##23(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,23),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC23_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,...)\
inline retType__  funcNarf__##23(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name,arg__23Type arg__23Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name,arg__23Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,23),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC22(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC23_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,...)
#define i_RP_DEFINE_FUNC23_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,arg__23Type,arg__23Name,...)



/**
 ** Function definition macros for 22 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC22(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,...)\
i_RP_DEFINE_FUNC21(funcNarf__,retType__,22,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,__VA_ARGS__)\
retType__ funcNarf__##22(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name)


#define i_RP_DEFINE_FUNC22(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC22_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,22),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,22))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC22_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,...)\
inline retType__  funcNarf__##22(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,22),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC22_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,...)\
inline retType__  funcNarf__##22(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name,arg__22Type arg__22Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name,arg__22Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,22),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC21(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC22_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,...)
#define i_RP_DEFINE_FUNC22_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,arg__22Type,arg__22Name,...)



/**
 ** Function definition macros for 21 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC21(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,...)\
i_RP_DEFINE_FUNC20(funcNarf__,retType__,21,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,__VA_ARGS__)\
retType__ funcNarf__##21(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name)


#define i_RP_DEFINE_FUNC21(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC21_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,21),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,21))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC21_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,...)\
inline retType__  funcNarf__##21(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,21),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC21_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,...)\
inline retType__  funcNarf__##21(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name,arg__21Type arg__21Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name,arg__21Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,21),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC20(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC21_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,...)
#define i_RP_DEFINE_FUNC21_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,arg__21Type,arg__21Name,...)



/**
 ** Function definition macros for 20 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC20(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,...)\
i_RP_DEFINE_FUNC19(funcNarf__,retType__,20,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,__VA_ARGS__)\
retType__ funcNarf__##20(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name)


#define i_RP_DEFINE_FUNC20(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC20_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,20),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,20))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC20_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,...)\
inline retType__  funcNarf__##20(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,20),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC20_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,...)\
inline retType__  funcNarf__##20(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name,arg__20Type arg__20Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name,arg__20Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,20),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC19(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC20_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,...)
#define i_RP_DEFINE_FUNC20_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,arg__20Type,arg__20Name,...)



/**
 ** Function definition macros for 19 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC19(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,...)\
i_RP_DEFINE_FUNC18(funcNarf__,retType__,19,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,__VA_ARGS__)\
retType__ funcNarf__##19(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name)


#define i_RP_DEFINE_FUNC19(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC19_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,19),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,19))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC19_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,...)\
inline retType__  funcNarf__##19(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,19),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC19_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,...)\
inline retType__  funcNarf__##19(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name,arg__19Type arg__19Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name,arg__19Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,19),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC18(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC19_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,...)
#define i_RP_DEFINE_FUNC19_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,arg__19Type,arg__19Name,...)



/**
 ** Function definition macros for 18 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC18(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,...)\
i_RP_DEFINE_FUNC17(funcNarf__,retType__,18,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,__VA_ARGS__)\
retType__ funcNarf__##18(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name)


#define i_RP_DEFINE_FUNC18(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC18_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,18),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,18))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC18_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,...)\
inline retType__  funcNarf__##18(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,18),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC18_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,...)\
inline retType__  funcNarf__##18(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name,arg__18Type arg__18Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name,arg__18Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,18),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC17(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC18_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,...)
#define i_RP_DEFINE_FUNC18_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,arg__18Type,arg__18Name,...)



/**
 ** Function definition macros for 17 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC17(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,...)\
i_RP_DEFINE_FUNC16(funcNarf__,retType__,17,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,__VA_ARGS__)\
retType__ funcNarf__##17(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name)


#define i_RP_DEFINE_FUNC17(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC17_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,17),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,17))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC17_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,...)\
inline retType__  funcNarf__##17(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,17),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC17_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,...)\
inline retType__  funcNarf__##17(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name,arg__17Type arg__17Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name,arg__17Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,17),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC16(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC17_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,...)
#define i_RP_DEFINE_FUNC17_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,arg__17Type,arg__17Name,...)



/**
 ** Function definition macros for 16 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC16(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,...)\
i_RP_DEFINE_FUNC15(funcNarf__,retType__,16,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,__VA_ARGS__)\
retType__ funcNarf__##16(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name)


#define i_RP_DEFINE_FUNC16(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC16_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,16),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,16))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC16_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,...)\
inline retType__  funcNarf__##16(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,16),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC16_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,...)\
inline retType__  funcNarf__##16(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name,arg__16Type arg__16Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name,arg__16Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,16),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC15(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC16_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,...)
#define i_RP_DEFINE_FUNC16_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,arg__16Type,arg__16Name,...)



/**
 ** Function definition macros for 15 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC15(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,...)\
i_RP_DEFINE_FUNC14(funcNarf__,retType__,15,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,__VA_ARGS__)\
retType__ funcNarf__##15(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name)


#define i_RP_DEFINE_FUNC15(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC15_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,15),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,15))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC15_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,...)\
inline retType__  funcNarf__##15(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,15),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC15_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,...)\
inline retType__  funcNarf__##15(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name,arg__15Type arg__15Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name,arg__15Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,15),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC14(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC15_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,...)
#define i_RP_DEFINE_FUNC15_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,arg__15Type,arg__15Name,...)



/**
 ** Function definition macros for 14 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC14(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,...)\
i_RP_DEFINE_FUNC13(funcNarf__,retType__,14,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,__VA_ARGS__)\
retType__ funcNarf__##14(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name)


#define i_RP_DEFINE_FUNC14(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC14_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,14),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,14))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC14_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,...)\
inline retType__  funcNarf__##14(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,14),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC14_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,...)\
inline retType__  funcNarf__##14(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name,arg__14Type arg__14Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name,arg__14Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,14),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC13(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC14_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,...)
#define i_RP_DEFINE_FUNC14_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,arg__14Type,arg__14Name,...)



/**
 ** Function definition macros for 13 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC13(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,...)\
i_RP_DEFINE_FUNC12(funcNarf__,retType__,13,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,__VA_ARGS__)\
retType__ funcNarf__##13(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name)


#define i_RP_DEFINE_FUNC13(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC13_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,13),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,13))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC13_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,...)\
inline retType__  funcNarf__##13(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,13),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC13_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,...)\
inline retType__  funcNarf__##13(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name,arg__13Type arg__13Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name,arg__13Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,13),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC12(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC13_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,...)
#define i_RP_DEFINE_FUNC13_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,arg__13Type,arg__13Name,...)



/**
 ** Function definition macros for 12 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC12(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,...)\
i_RP_DEFINE_FUNC11(funcNarf__,retType__,12,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,__VA_ARGS__)\
retType__ funcNarf__##12(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name)


#define i_RP_DEFINE_FUNC12(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC12_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,12),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,12))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC12_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,...)\
inline retType__  funcNarf__##12(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,12),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC12_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,...)\
inline retType__  funcNarf__##12(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name,arg__12Type arg__12Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name,arg__12Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,12),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC12_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,...)
#define i_RP_DEFINE_FUNC12_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,arg__12Type,arg__12Name,...)



/**
 ** Function definition macros for 11 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC11(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,...)\
i_RP_DEFINE_FUNC10(funcNarf__,retType__,11,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,__VA_ARGS__)\
retType__ funcNarf__##11(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name)


#define i_RP_DEFINE_FUNC11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC11_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,11),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,11))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC11_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,...)\
inline retType__  funcNarf__##11(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,11),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC11_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,...)\
inline retType__  funcNarf__##11(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name,arg__11Type arg__11Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name,arg__11Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,11),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC11_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,...)
#define i_RP_DEFINE_FUNC11_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,arg__11Type,arg__11Name,...)



/**
 ** Function definition macros for 10 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC10(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,...)\
i_RP_DEFINE_FUNC9(funcNarf__,retType__,10,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,__VA_ARGS__)\
retType__ funcNarf__##10(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name)


#define i_RP_DEFINE_FUNC10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC10_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,10),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,10))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC10_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,...)\
inline retType__  funcNarf__##10(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,10),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC10_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,...)\
inline retType__  funcNarf__##10(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name,arg__10Type arg__10Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name,arg__10Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,10),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC9(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC10_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,...)
#define i_RP_DEFINE_FUNC10_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,arg__10Type,arg__10Name,...)



/**
 ** Function definition macros for 9 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC9(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,...)\
i_RP_DEFINE_FUNC8(funcNarf__,retType__,9,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,__VA_ARGS__)\
retType__ funcNarf__##9(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name)


#define i_RP_DEFINE_FUNC9(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC9_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,9),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,9))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC9_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,...)\
inline retType__  funcNarf__##9(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,9),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC9_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,...)\
inline retType__  funcNarf__##9(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name,arg__9Type arg__9Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name,arg__9Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,9),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC8(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC9_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,...)
#define i_RP_DEFINE_FUNC9_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,arg__9Type,arg__9Name,...)



/**
 ** Function definition macros for 8 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC8(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,...)\
i_RP_DEFINE_FUNC7(funcNarf__,retType__,8,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,__VA_ARGS__)\
retType__ funcNarf__##8(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name)


#define i_RP_DEFINE_FUNC8(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC8_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,8),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,8))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC8_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,...)\
inline retType__  funcNarf__##8(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,8),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC8_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,...)\
inline retType__  funcNarf__##8(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name,arg__8Type arg__8Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name,arg__8Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,8),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC7(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC8_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,...)
#define i_RP_DEFINE_FUNC8_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,arg__8Type,arg__8Name,...)



/**
 ** Function definition macros for 7 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC7(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,...)\
i_RP_DEFINE_FUNC6(funcNarf__,retType__,7,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,__VA_ARGS__)\
retType__ funcNarf__##7(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name)


#define i_RP_DEFINE_FUNC7(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC7_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,7),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,7))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC7_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,...)\
inline retType__  funcNarf__##7(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,7),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC7_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,...)\
inline retType__  funcNarf__##7(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name,arg__7Type arg__7Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name,arg__7Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,7),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC6(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC7_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,...)
#define i_RP_DEFINE_FUNC7_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,arg__7Type,arg__7Name,...)



/**
 ** Function definition macros for 6 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC6(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,...)\
i_RP_DEFINE_FUNC5(funcNarf__,retType__,6,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,__VA_ARGS__)\
retType__ funcNarf__##6(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name)


#define i_RP_DEFINE_FUNC6(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC6_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,6),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,6))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC6_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,...)\
inline retType__  funcNarf__##6(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,6),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC6_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,...)\
inline retType__  funcNarf__##6(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name,arg__6Type arg__6Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name,arg__6Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,6),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC5(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC6_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,...)
#define i_RP_DEFINE_FUNC6_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,arg__6Type,arg__6Name,...)



/**
 ** Function definition macros for 5 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC5(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,...)\
i_RP_DEFINE_FUNC4(funcNarf__,retType__,5,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,__VA_ARGS__)\
retType__ funcNarf__##5(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name)


#define i_RP_DEFINE_FUNC5(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC5_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,5),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,5))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC5_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,...)\
inline retType__  funcNarf__##5(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,5),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC5_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,...)\
inline retType__  funcNarf__##5(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name,arg__5Type arg__5Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name,arg__5Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,5),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC4(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC5_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,...)
#define i_RP_DEFINE_FUNC5_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,arg__5Type,arg__5Name,...)



/**
 ** Function definition macros for 4 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC4(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,...)\
i_RP_DEFINE_FUNC3(funcNarf__,retType__,4,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,__VA_ARGS__)\
retType__ funcNarf__##4(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name)


#define i_RP_DEFINE_FUNC4(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC4_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,4),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,4))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC4_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,...)\
inline retType__  funcNarf__##4(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,4),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC4_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,...)\
inline retType__  funcNarf__##4(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name,arg__4Type arg__4Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name,arg__4Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,4),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC3(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC4_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,...)
#define i_RP_DEFINE_FUNC4_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,arg__4Type,arg__4Name,...)



/**
 ** Function definition macros for 3 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC3(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,...)\
i_RP_DEFINE_FUNC2(funcNarf__,retType__,3,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,arg__2Type,arg__2Name,__VA_ARGS__)\
retType__ funcNarf__##3(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name)


#define i_RP_DEFINE_FUNC3(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC3_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,3),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,3))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC3_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,...)\
inline retType__  funcNarf__##3(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,3),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC3_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,...)\
inline retType__  funcNarf__##3(arg__1Type arg__1Name,arg__2Type arg__2Name,arg__3Type arg__3Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name,arg__3Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,3),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC2(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC3_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,...)
#define i_RP_DEFINE_FUNC3_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,arg__3Type,arg__3Name,...)



/**
 ** Function definition macros for 2 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC2(retType__,funcNarf__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,...)\
i_RP_DEFINE_FUNC1(funcNarf__,retType__,2,RF_NARG(__VA_ARGS__),arg__1Type,arg__1Name,__VA_ARGS__)\
retType__ funcNarf__##2(arg__1Type arg__1Name,arg__2Type arg__2Name)


#define i_RP_DEFINE_FUNC2(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC2_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,2),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,2))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC2_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,...)\
inline retType__  funcNarf__##2(arg__1Type arg__1Name,arg__2Type arg__2Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name,arg__2Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,2),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC2_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,...)\
inline retType__  funcNarf__##2(arg__1Type arg__1Name,arg__2Type arg__2Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name,arg__2Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,2),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC1(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,__VA_ARGS__)
#define i_RP_DEFINE_FUNC2_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,...)
#define i_RP_DEFINE_FUNC2_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,arg__2Type,arg__2Name,...)



/**
 ** Function definition macros for 1 arguments functions. No comments here. All comments are in the generating python file.
 **
 **/
#define RF_DEFINE_DFUNC1(retType__,funcNarf__,arg__1Type,arg__1Name,...)\
i_RP_DEFINE_FUNC0(funcNarf__,retType__,1,RF_NARG(__VA_ARGS__),__VA_ARGS__)\
retType__ funcNarf__##1(arg__1Type arg__1Name)


#define i_RP_DEFINE_FUNC1(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC1_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,1),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,1))(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,__VA_ARGS__)

#define i_RP_DEFINE_FUNC1_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,...)\
inline retType__  funcNarf__##1(arg__1Type arg__1Name)\
{\
	 return  funcNarf__##maxArgsN__(arg__1Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,1),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}

#define i_RP_DEFINE_FUNC1_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,...)\
inline retType__  funcNarf__##1(arg__1Type arg__1Name)\
{\
	 return funcNarf__##maxArgsN__(arg__1Name i_RP_GET_DEFAULT_ARG(RP_SUB(maxArgsN__,1),maxArgsN__)(defArgsN__,__VA_ARGS__));\
}\
i_RP_DEFINE_FUNC0(funcNarf__,retType__,maxArgsN__,defArgsN__,__VA_ARGS__)
#define i_RP_DEFINE_FUNC1_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,...)
#define i_RP_DEFINE_FUNC1_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,arg__1Type,arg__1Name,...)



/**
 ** Function definition macros for 0 arguments functions
 **
 **/
#define i_RP_DEFINE_FUNC0(funcNarf__,retType__,maxArgsN__,defArgsN__,...)\
i_RP_PICK_FUNC_DEF(i_RP_DEFINE_FUNC0_IMP,i_RP_DEF_MACRO_CHECK1(maxArgsN__,defArgsN__,0),i_RP_DEF_MACRO_CHECK2(maxArgsN__,defArgsN__,0))(funcNarf__,retType__,maxArgsN__,defArgsN__,__VA_ARGS__)

#define i_RP_DEFINE_FUNC0_IMP00(funcNarf__,retType__,maxArgsN__,defArgsN__,...)\
retType__  funcNarf__##0()\
{\
	 funcNarf__##maxArgsN__(__VA_ARGS__);\
}
#define i_RP_DEFINE_FUNC0_IMP01(funcNarf__,retType__,maxArgsN__,defArgsN__,...)
#define i_RP_DEFINE_FUNC0_IMP10(funcNarf__,retType__,maxArgsN__,defArgsN__,...)
#define i_RP_DEFINE_FUNC0_IMP11(funcNarf__,retType__,maxArgsN__,defArgsN__,...)
