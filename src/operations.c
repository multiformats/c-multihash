#include <mh/operations.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void xor_bin(const unsigned char* bin1, const unsigned char* bin2, unsigned char* dest)
{
    size_t length1 = strlen((const char*) bin1);
    size_t length2 = strlen((const char*) bin2);

    unsigned char* in1 = malloc(length1);
    unsigned char* in2 = malloc(length2);

    memcpy(in1, bin1, length1);
    memcpy(in2, bin2, length2);

    size_t longest = length1 < length2 ? length2 : length1;
    /* TODO: Add non-equal support */
    /* unsigned char** shortest = length1 < length2 ? &in1 : &in2; */


    for (int i = 0; i < longest; i++) {
        dest[i] = (unsigned char)(in1[i] != in2[i] ? '1' : '0');
    }

    dest[longest + 1] = '\0';
}