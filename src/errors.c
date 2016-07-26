/* vim: set ts=8 sw=8 noexpandtab: */
#include "mh/errors.h"

static const struct mh_error_desc {
	int code;
	const char *message;
} mh_errordesc[] = {
	{ MH_E_UNKNOWN_CODE, "unknown multihash code" },
	{ MH_E_TOO_SHORT, "multihash too short. must be > 3 bytes" },
	{ MH_E_TOO_LONG, "multihash too long. must be < 129 bytes" },
	{ MH_E_LEN_NOT_SUPPORTED, "multihash does not yet support"
		" digests longer than 127 bytes" }
};

const char *mh_error_string(mh_error code) {
	unsigned int i = 0;
	for (; i < sizeof(mh_errordesc); i++) {
		if (mh_errordesc[i].code == code)
			return mh_errordesc->message;
	}

	return "unknown error code";
}
