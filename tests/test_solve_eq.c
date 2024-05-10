#include "test_quadratic_eq.h"

START_TEST(eq_positive_discriminant) {
  QuadraticEquationRoots rsq = solve_equation(1, -3, 2);
  ck_assert_int_eq(rsq.num_roots, 2);
  ck_assert_double_eq(rsq.x1, 1);
  ck_assert_double_eq(rsq.x2, 2);
}
END_TEST

START_TEST(eq_zero_discriminant) {
  QuadraticEquationRoots rsq = solve_equation(1, -2, 1);
  ck_assert_int_eq(rsq.num_roots, 1);
  ck_assert_double_eq(rsq.x1, 1);
  ck_assert_double_eq(rsq.x2, 1);
}
END_TEST

START_TEST(eq_negative_discriminant) {
  QuadraticEquationRoots rsq = solve_equation(1, 1, 1);
  ck_assert_int_eq(rsq.num_roots, 0);
}
END_TEST

START_TEST(eq_zero_first_arg) {
  QuadraticEquationRoots rsq = solve_equation(0, 1, 1);
  ck_assert_int_eq(rsq.num_roots, 0);
}
END_TEST

START_TEST(eq_zero_all_args) {
  QuadraticEquationRoots rsq = solve_equation(0, 0, 0);
  ck_assert_int_eq(rsq.num_roots, 0);
}
END_TEST

START_TEST(eq_nan) {
  QuadraticEquationRoots rsq = solve_equation(NAN, NAN, 0);
  ck_assert_int_eq(rsq.num_roots, 0);
}
END_TEST

START_TEST(eq_small) {
  QuadraticEquationRoots rsq = solve_equation(1, 1.999999997, 1);
  ck_assert_int_eq(rsq.num_roots, 1);
}
END_TEST

Suite *test_quadratic_eq(void) {
  Suite *s = suite_create("\033[45m-=test_quadratic_eq=-\033[0m");
  TCase *tc = tcase_create("eq_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, eq_positive_discriminant);
  tcase_add_test(tc, eq_zero_discriminant);
  tcase_add_test(tc, eq_negative_discriminant);
  tcase_add_test(tc, eq_zero_first_arg);
  tcase_add_test(tc, eq_zero_all_args);
  tcase_add_test(tc, eq_nan);
  tcase_add_test(tc, eq_small);

  return s;
}
