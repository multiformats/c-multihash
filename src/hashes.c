#include <stdlib.h>
#include "mh/hashes.h"

#include "mh/errors.h"
#include "mh/assert.h"


static const struct hash_name {
	int hash;
	const char *name;
} hash_names[] = {
	{ MH_H_SHA1, "sha1" },
	{ MH_H_SHA2_256, "sha2-256" },
	{ MH_H_SHA2_512, "sha2-512" },
	{ MH_H_SHA3_512, "sha3-512" },
	{ MH_H_SHA3_384, "sha3-384" },
	{ MH_H_SHA3_256, "sha3-256" },
	{ MH_H_SHA3_224, "sha3-224" },
	{ MH_H_SHAKE_128, "shake-128" },
	{ MH_H_SHAKE_256, "shake-256" },
	{ MH_H_BLAKE2B, "blake2b" },
	{ MH_H_BLAKE2S, "blake2s" }
};

mh_assert_static(sizeof(hash_names) / sizeof(hash_names[0]) == MH_H_COUNT);

const char *mh_hash_name(int hash) {
	unsigned int i = 0;
	for (; i < sizeof(mh_all_hashes) / sizeof(mh_all_hashes[0]); i++) {
		if (hash_names[i].hash == hash)
			return hash_names[i].name;

	}

	return NULL;
}


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

mh_assert_static(sizeof(hash_lengths)/sizeof(hash_lengths[0]) == MH_H_COUNT);

int mh_hash_default_length(int hash) {
	if (hash < 0 || hash >= MH_H_COUNT)
		return MH_E_UNKNOWN_CODE;

	return hash_lengths[hash];
}

int mh_hash_length(const unsigned char multihash[], int len, int *hash_length);


int mh_hash_function(const unsigned char multihash[], int len, int *hash);
