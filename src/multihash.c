#include "mh/multihash.h"

#include "mh/hashes.h"
#include "mh/errors.h"

#define VARINT_MASK (1 << 7)

static int check_multihash(const unsigned char mh[], int len) {
	if (len < 3) {
		return MH_E_TOO_SHORT;
	} else if (len >= 129) {
		return MH_E_TOO_LONG;
	} else if (mh[0] & VARINT_MASK) {
		// In near future multihash format will be
		// extended with varints, this is how we are protecting
		// against it.
		return MH_E_VARINT_NOT_SUPPORTED;
	} else if (mh[1] & VARINT_MASK) {
		return MH_E_VARINT_NOT_SUPPORTED;
	}
	return MH_E_NO_ERROR;
}


// returns hash code or error (which is < 0)
int mh_multihash_hash(const unsigned char mh[], int len) {
	if (check_multihash(mh, len))
		return check_multihash(mh, len);
	return (int) mh[0];
}


// returns length of multihash or error (which is < 0)
int mh_multihash_length(const unsigned char mh[], int len) {
	if (check_multihash(mh, len))
		return check_multihash(mh, len);
	return (int) mh[1];
}

