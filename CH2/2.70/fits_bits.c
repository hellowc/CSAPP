#include<stdio.h>

/*
 * Return 1 when x can be represented as an n-bit, 2's-complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 */
int fits_bits(int x, int n){
	return x == (x << (sizeof(int) << 3) - n) >> ((sizeof(int) << 3) - n);
}

int main() {
	int x = -128;
	int n = 8;
	printf("%d\n", fits_bits(x, n));
	return 0;
}
