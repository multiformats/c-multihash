/* vim: set ts=8 sw=8 noexpandtab: */
#ifndef ERROR_H
#define ERROR_H

typedef enum {
	MH_E_UNKNOWN_CODE = -1,
	MH_E_TOO_SHORT = -2,
	MH_E_TOO_LONG = -3,
	MH_E_LEN_NOT_SUPPORTED = -4
} mh_error;

const char *mh_error_string(mh_error code);

#endif /* end of include guard */
