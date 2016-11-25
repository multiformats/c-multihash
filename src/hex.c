#include <mh/hex.h>
#include <mh/dec.h>
#include <string.h>
#include <stdlib.h>

unsigned const char bin_value[][4] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
unsigned const char hex_value[]    = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void hex_to_bin(unsigned const char* hex, unsigned char* dest)
{
	unsigned char* value = dest;
	char ch = *hex;

	int length = (int) strlen((const char*) hex);

	for(int i = 0; i < length; i++) {
		if (ch >= '0' && ch <= '9')
			strncat((char*) value, (const char*) bin_value[ch - '0'], 4);
		if (ch >= 'A' && ch <= 'F')
			strncat((char*) value, (const char*) bin_value[10 + ch - 'A'], 4);
		if (ch >= 'a' && ch <= 'f')
			strncat((char*) value, (const char*) bin_value[10 + ch - 'a'], 4);
		ch = *(++hex);
	}
}

void bin_to_hex(unsigned const char* bin, unsigned char* dest)
{
	size_t length = strlen((const char*) bin);
	size_t nibbles = length / 4;

	for (int i = 0; i < nibbles; i++) {
		unsigned char* nibble = malloc(4);
		for (int j = 0; j < 4; j++) {
			nibble[j] = bin[(i * 4) + j];
		}

		unsigned long long dec = bin_to_dec(nibble);
		unsigned char *buffer = malloc(1);
		dec_to_hex(&dec, buffer);
		strcat((char*) dest, (const char*) buffer);
	}
}

void dec_to_hex(const unsigned long long* dec, unsigned char* dest)
{
	unsigned long long value = *dec;
	unsigned char hex;

	if(!value) {
		*dest = '0';
		return;
	}
	while (value != 0) {
		unsigned long long remainder = value % 16;
		hex = hex_value[remainder];
		value /= 16;
		*dest++ = hex;
	}
}