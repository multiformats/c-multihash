#ifndef MH_HULTIHASH_H
#define MH_HULTIHASH_H

// returns hash code or error (which is < 0)
int mh_multihash_hash(const unsigned char multihash[], int len);

// returns length of multihash or error (which is < 0)
int mh_multihash_length(const unsigned char multihash[], int len);

#endif /* end of include guard */
