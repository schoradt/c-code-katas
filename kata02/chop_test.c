/*
 * C Code Katas 
 *
 * Kata 02
 *
 * Author  : S. Schoradt <sven.schoradt@googlemail.com>
 * Created : 10.07.2014
 * 
 * Copyright (c) 2014 by Sven Schoradt.
 *
**/

/**
 * @file 
 * Unit test file inspired by test cases from requirements
 *
 * @author Sven Schoradt S. Schoradt <sven.schoradt@googlemail.com>
 *
 * @version 1.0
 *
 * @date 10.07.2014
 */

#include <stdlib.h>
#include <check.h>

#include "chop.h"

START_TEST (test_chop)
{
    int a1[0] = {}; 
    int a2[1] = {1}; 
    int a3[3] = {1, 3, 5};
    int a4[4] = {1, 3, 5, 7};  

    ck_assert_int_eq (chop(3, a1, 0), -1);

    ck_assert_int_eq (chop(3, a2, 1), -1);
    ck_assert_int_eq (chop(1, a2, 1), 0);

    ck_assert_int_eq (chop(1, a3, 3), 0);
    ck_assert_int_eq (chop(3, a3, 3), 1);
    ck_assert_int_eq (chop(5, a3, 3), 2);
    ck_assert_int_eq (chop(0, a3, 3), -1);
    ck_assert_int_eq (chop(2, a3, 3), -1);
    ck_assert_int_eq (chop(4, a3, 3), -1);
    ck_assert_int_eq (chop(6, a3, 3), -1);

    ck_assert_int_eq (chop(1, a4, 4), 0);
    ck_assert_int_eq (chop(3, a4, 4), 1);
    ck_assert_int_eq (chop(5, a4, 4), 2);
    ck_assert_int_eq (chop(7, a4, 4), 3);
    ck_assert_int_eq (chop(0, a4, 4), -1);
    ck_assert_int_eq (chop(2, a4, 4), -1);
    ck_assert_int_eq (chop(4, a4, 4), -1);
    ck_assert_int_eq (chop(6, a4, 4), -1);
    ck_assert_int_eq (chop(8, a4, 4), -1);
}
END_TEST

Suite *
money_suite (void)
{
    Suite *s = suite_create ("Kata02 - Chop");

    /* Core test case */
    TCase *tc_core = tcase_create ("Core");
    tcase_add_test (tc_core, test_chop);
    suite_add_tcase (s, tc_core);

    return s;
}

int
main (void)
{
    int number_failed;
    Suite *s = money_suite ();
    SRunner *sr = srunner_create (s);

    srunner_run_all (sr, CK_NORMAL);
    number_failed = srunner_ntests_failed (sr);
    srunner_free (sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
 }