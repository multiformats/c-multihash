/* vim: set ts=8 sw=8 noexpandtab: */
#include <stdio.h>

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
	if (message) return message; } while (0)
int tests_run = 0;
static char *mu_all_tests(void);

int main(void) {
	char *result = mu_all_tests();
	if (result != NULL) {
		printf("error: %s\n", result);
	}
	else {
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}

