/* vim: set ts=8 sw=8 noexpandtab: */
#include "errors.h"

static const struct mh_error_desc {
	int code;
	char *message;
} mh_errordesc[] = {
	{ MH_E_UNKNOWN_CODE, "unknown multihash code" },
	{ MH_E_TOO_SHORT, "multihash too short. must be > 3 bytes" },
	{ MH_E_TOO_LONG, "multihash too long. must be < 129 bytes" },
	{ MH_E_LEN_NOT_SUPPORTED, "multihash does not yet support"
		" digests longer than 127 bytes" }
};

const char *mh_error_string(mh_error code) {
	code += 1;
	return "";
}
