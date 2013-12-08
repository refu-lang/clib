/* just some additional macros to help with unit testing*/


/* RFstring/x related macros */
#define ck_assert_rf_str_eq_cstr(rfstr_, cstr_) \
    ck_assert_int_eq(0, memcmp(rf_string_data(rfstr_), cstr_, strlen(cstr_)))

#define ck_assert_rf_strx_eq_cstr(str_, lit_)                          \
    do{                                                                 \
        ck_assert_uint_gt(((struct RFstringx*)str_)->bSize, strlen(lit_) + 1); \
        ck_assert_int_eq(0, memcmp(rf_string_data(str_), lit_, strlen(lit_))); \
        ck_assert_int_eq(rf_string_data(str_)[((struct RFstringx*)str_)->bIndex], \
                         lit_[0]);                                      \
    }while(0)