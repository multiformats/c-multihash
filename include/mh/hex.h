#ifndef HEX_H
#define HEX_H

void hex_to_bin(unsigned const char* hex, unsigned char* dest);

void bin_to_hex(unsigned const char* bin, unsigned char* dest);

void dec_to_hex(const unsigned long long* dec, unsigned char* dest);
#endif
