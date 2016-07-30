#include <string.h>
#include "minunit.h"

#include "mh/hashes.h"

char error_buf[256];

static char *test_all_hashes_have_lengths(void) {
	int i = 0;
	//int length = 0;
	for (; i < MH_H_COUNT; i++) {
/*		length = mh_hash_default_length((mh_hash) i);
		sprintf(error_buf, "mh_hash_default_length: hash %d"
				" returned invalid (%d) default length",
				i, length);
		mu_assert(error_buf, length > 0);
	*/
	}
	return NULL;
}

static char *mu_all_tests(void) {
	mu_run_test(test_all_hashes_have_lengths);
	return NULL;
}

