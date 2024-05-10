#include "test_quadratic_eq.h"

int main(void) {
  int failed = 0;
  Suite *quadratic_eq_test[] = {test_quadratic_eq(), NULL};

  for (int i = 0; quadratic_eq_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(quadratic_eq_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}