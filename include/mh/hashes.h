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

	HM_H_COUNT // number of hash functions
} mh_hash;

// returns default size in bytes of given hash function
int mh_hash_default_size(mh_hash hash);

// returns wire format code of given hash function
int mh_hash_code(mh_hash hash);

typedef struct {
	mh_hash hash;
	int code;
	int length;
} mh_hashinfo;

// decodes code info hash info, leaves length field zeroed
mh_error mh_hashinfo_from_code(int code, mh_hashinfo *hinfo);

// decodes bytes into hashinfo
mh_error mh_hashinfo_from_bytes(char bytes[2], mh_hashinfo *hinfo);






