#include <string.h>
#include "minunit.h"

#include "errors.h"

char error_buf[256];

static char *test_error_messages_exist(void) {
	int i = -1;
	for (; i > MH_E_LAST; i--) {
		sprintf(error_buf, "error: code %d has no message", i);
		mu_assert(error_buf, strlen(mh_error_string((mh_error) i)));
	}

	return 0;
}

static char *mu_all_tests(void) {
	mu_run_test(test_error_messages_exist);
	return 0;
}
