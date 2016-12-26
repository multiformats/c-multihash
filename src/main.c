#include <mh/multihash.h>
#include <stdio.h>

int main(void)
{
	printf("%i", mh_multihash_hash((const unsigned char*) "11", 2));
}

