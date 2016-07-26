/* vim: set ts=8 sw=8 noexpandtab: */
#include <stdio.h>


#include "mh/errors.h"

int main(void) {
	printf("%s\n", mh_error_string(MH_E_TOO_LONG));
	printf("Hello World\n");
	return 0;
}
