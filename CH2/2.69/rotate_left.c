#include<stdio.h>

/*
 * Do rotating left shift. Assume 0 <= n < w
 * Exampls when x = 0x12345678 and w = 32:
 * 	n=4 -> 0x23456781, n=20 -> 0x67812345
 */
unsigned rotate_left(unsigned x, int n){
	unsigned y = x;
	y = y >> (sizeof(unsigned) >> 3) - n;
	x = x << n;
	return x | y;
}

//大佬解答
unsigned rotate_left0(unsigned x, int n){
	return (x << n) | (x >> ((sizeof(unsigned) >> 3) - n));
}

int main() {
	unsigned x = 0x12345678;
	int n = 2;
	printf("%x\n", rotate_left0(x, n));
	return 0;
}

