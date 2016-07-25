#include <stdio.h>
#include <string.h>
#include "minunit.h"

#include "../errors.h"

int tests_run = 0;
char error_buf[256];


static char *test_error_messages_exist(void) {
	int i = -1;
	for (; i > MH_E_LAST; i--) {
		sprintf(error_buf, "error: code %d has no message", i);
		mu_assert(error_buf, strlen(mh_error_string((mh_error) i)));
	}

	return 0;
}

static char *all_tests(void) {
	mu_run_test(test_error_messages_exist);
	return 0;
}

int main(void) {
	char *result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	}
	else {
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}

