/* vim: set ts=8 sw=8 noexpandtab: */
#include "mh/errors.h"

const char *mh_error_string(int code) {
	switch (code) {
		case MH_E_NO_ERROR:
			return "no error";
		case MH_E_UNKNOWN_CODE:
			return "unknown multihash code";
		case MH_E_TOO_SHORT:
			return "multihash too short. must be > 3 bytes";
		case MH_E_TOO_LONG:
			return "multihash too long. must be < 129 bytes";
		case MH_E_LEN_NOT_SUPPORTED:
			return "multihash does not yet support"
				" digsets linger than 127 bytes";
		default:
			return "unknown error code";
	}
}
