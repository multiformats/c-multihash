/* vim: set ts=8 sw=8 noexpandtab: */
#include "mh/hashes.h"
#include "mh/errors.h"


static const int hash_lengths[] = {
	20, // sha1
	32, // sha2-256
	64, // sha2-512
	64, // sha3-512
	45, // sha3-364
	32, // sha3-256
	28, // sha3-224
	16, // shake-128
	32, // shake-256
	64, // blake2b
	32, // blake2s
};


int mh_hash_default_length(mh_hash hash) {
	if (hash < 0 || hash >= MH_H_COUNT)
		return MH_;

	return hash_lengths[hash];
}






/*
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

	HM_H_COUNT // number of hash functions
 */
