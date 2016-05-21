#include <check.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "test_helpers.h"
#include "utilities_for_testing.h"

#include <rfbase/datastructs/darray.h>

struct foo {
    uint64_t x;
    double y;
};

static struct foo *foo_create(uint64_t x, double y)
{
    struct foo *ret;
    RF_MALLOC(ret, sizeof(*ret), NULL);
    ret->x = x;
    ret->y = y;
    return ret;
}

static void foo_destroy(struct foo *f)
{
    free(f);
}

struct foo_arr {darray(struct foo*);};

struct foo expectarr[] = {
    {.x = 42,  .y = 3.14},
    {.x = 55,  .y = 0.21},
    {.x = 194, .y = 3.21},
    {.x = 74,  .y = 0.01}
};

#define ARR_SIZE (sizeof(expectarr) / sizeof(struct foo))

START_TEST (test_darray_prepend) {
    struct foo_arr arr;
    struct foo *f;
    darray_init(arr);
    unsigned i;
    for (i = 1; i < ARR_SIZE; ++i) {
        f = foo_create(expectarr[i].x, expectarr[i].y);
        darray_append(arr, f);
    }
    darray_prepend(arr, foo_create(expectarr[0].x, expectarr[0].y));

    struct foo **itf;
    i = 0;
    darray_foreach(itf, arr) {
        ck_assert_int_eq((*itf)->x, expectarr[i].x);
        ck_assert((*itf)->y == expectarr[i].y);
        ++i;
        foo_destroy(*itf);
    }
    darray_free(arr);
} END_TEST

START_TEST (test_darray_prepend_empty) {
    struct foo_arr arr;
    struct foo *f;
    darray_init(arr);

    f = foo_create(expectarr[0].x, expectarr[0].y);
    darray_prepend(arr, f);
    foo_destroy(f);

    darray_free(arr);
} END_TEST

START_TEST (test_darray_foreach_reverse) {
    struct foo_arr arr;
    struct foo *f;
    unsigned int i;
    darray_init(arr);
    for (i = 1; i < ARR_SIZE; ++i) {
        f = foo_create(expectarr[i].x, expectarr[i].y);
        darray_append(arr, f);
    }

    struct foo **itf;
    i = ARR_SIZE - 1;
    darray_foreach_reverse(itf, arr) {
        ck_assert_int_eq((*itf)->x, expectarr[i].x);
        ck_assert((*itf)->y == expectarr[i].y);
        --i;
        foo_destroy(*itf);
    }
    darray_free(arr);
} END_TEST

struct boo {
    struct foo_arr arr;
    int x;
};

START_TEST (test_darray_shallow_copy) {
    struct boo *b1;
    struct boo *b2;
    RF_MALLOC(b1, sizeof(*b1), ;);
    b1->x = 1;
    darray_init(b1->arr);

    struct foo *f;
    unsigned i;
    for (i = 0; i < ARR_SIZE; ++i) {
        f = foo_create(expectarr[i].x, expectarr[i].y);
        darray_append(b1->arr, f);
    }

    RF_MALLOC(b2, sizeof(*b2), ;);
    b2->x = 2;
    darray_init(b2->arr);
    darray_shallow_copy(b2->arr, b1->arr);
    free(b1);

    struct foo **itf;
    i = 0;
    darray_foreach(itf, b2->arr) {
        ck_assert_int_eq((*itf)->x, expectarr[i].x);
        ck_assert((*itf)->y == expectarr[i].y);
        ++i;
        foo_destroy(*itf);
    }
    darray_free(b2->arr);
    free(b2);
} END_TEST

struct foo_arr_np {darray(struct foo);};

START_TEST (test_darray_raw_copy) {
    struct foo_arr_np arr1;
    darray_raw_copy(arr1, expectarr, sizeof(expectarr) / sizeof(struct foo));

    struct foo *itf;
    unsigned int i = 0;
    darray_foreach(itf, arr1) {
        ck_assert_int_eq(itf->x, expectarr[i].x);
        ck_assert(itf->y == expectarr[i].y);
        ++i;
    }
} END_TEST


Suite *datastructs_darray_suite_create(void)
{
    Suite *s = suite_create("data_structures_darray");

    TCase *tc1 = tcase_create("darray_prepend");
    tcase_add_test(tc1, test_darray_prepend);
    tcase_add_test(tc1, test_darray_prepend_empty);

    TCase *tc2 = tcase_create("darray_foreach");
    tcase_add_test(tc2, test_darray_foreach_reverse);

    TCase *tc3 = tcase_create("darray_copy");
    tcase_add_test(tc3, test_darray_shallow_copy);
    tcase_add_test(tc3, test_darray_raw_copy);

    suite_add_tcase(s, tc1);
    suite_add_tcase(s, tc2);
    suite_add_tcase(s, tc3);

    return s;
}
