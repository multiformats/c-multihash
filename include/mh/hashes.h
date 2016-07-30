/* vim: set ts=8 sw=8 noexpandtab: */
#include "errors.h"

// list of avaliable hash functions.
typedef enum {
	MH_H_SHA1,
	MH_H_SHA2_256,
	MH_H_SHA2_512,
	MH_H_SHA3_512,
	MH_H_SHA3_384,
	MH_H_SHA3_256,
	MH_H_SHA3_224,
	MH_H_SHAKE_128,
	MH_H_SHAKE_256,
	MH_H_BLAKE2B,
	MH_H_BLAKE2S,

	MH_H_COUNT // number of hash functions
} mh_hash;

// returns length in bytes or if returns is < 0 it is an error
int mh_hash_default_length(mh_hash hash);

int mh_hash_length(const unsigned char multihash[], int len, int *hash_length);

int mh_hash_function(const unsigned char multihash[], int len, mh_hash *hash);





