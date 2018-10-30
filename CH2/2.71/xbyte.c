#include<stdio.h>

/* Declaration of data type where 4 byte are packed
   into an unsigned */
typedef unsigned packed_t;

/* Extract byte from word. Return as signed integer */
int xbyte(packed_t word, int bytenum) {
	int shift = (3 - bytenum) << 3;
	return (int)(word << shift) >> 24;
} 

int main() {
	packed_t word = 0x12345678;
	int bytenum = 1;
	printf("%x", xbyte(word, bytenum));
	return 0;
}
