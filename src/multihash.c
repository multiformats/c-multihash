#include "mh/multihash.h"

#include "mh/hashes.h"
#include "mh/errors.h"
#include "mh/generic.h"

#include <string.h>
#include <stdlib.h>

#define VARINT_MASK (1 << 7)

static int check_len(size_t len) {
	if (len < 1) {
		return MH_E_TOO_SHORT;
	} else if (len >= 128) {
		return MH_E_TOO_LONG;
	}

	return MH_E_NO_ERROR;
}

static int check_multihash(const unsigned char mh[], size_t len) {
	int error;

	if (len < 3)
		return MH_E_TOO_SHORT;

	if (mh[0] & VARINT_MASK) {
		// In near future multihash format will be
		// extended with varints, this is how we are protecting
		// against it.
		return MH_E_VARINT_NOT_SUPPORTED;
	} else if (mh[1] & VARINT_MASK) {
		return MH_E_VARINT_NOT_SUPPORTED;
	}

	error = check_len(mh[1]);
	if (error)
		return error;


	return MH_E_NO_ERROR;
}


// returns hash code or error (which is < 0)
int mh_multihash_hash(const unsigned char *mh, size_t len) {
	if (check_multihash(mh, len))
		return check_multihash(mh, len);
	return (int) mh[0];
}


// returns length of multihash or error (which is < 0)
int mh_multihash_length(const unsigned char *mh, size_t len) {
	if (check_multihash(mh, len))
		return check_multihash(mh, len);
	return (int) mh[1];
}

// gives access to raw digset inside multihash buffer
// returns 0 or negative error
int mh_multihash_digset(unsigned char *multihash, size_t len, unsigned char **digset,
		size_t *digset_len) {
	int error = check_multihash(multihash, len);
	if (error)
		return error;

	(*digset_len) = (size_t) mh_multihash_length(multihash, len);
	(*digset) = multihash + 2; // Always true without varint

	return MH_E_NO_ERROR;
}

int mh_new_length(int code, size_t hash_len) {
	// right now there is no varint support
	// so length required is 2 + hash_len
	UNUSED(code);
	return 2 + hash_len;
}

int mh_new(unsigned char *buffer, int code, const unsigned char *digset,
	size_t digset_len) {
	if (code & VARINT_MASK)
		return MH_E_VARINT_NOT_SUPPORTED;
	if (digset_len > 127)
		return MH_E_DIGSET_TOO_LONG;

	buffer[0] = (unsigned char) ((unsigned int) code) & 255;
	buffer[1] = (unsigned char) digset_len;
	memcpy(buffer + 2, digset, digset_len);

	return MH_E_NO_ERROR;
}

