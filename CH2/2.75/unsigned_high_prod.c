#include<stdio.h>
int signed_high_prod(int x, int y) {
	long long ans = (long long)x * (long long)y;
	printf("ans = %llx\n", ans);
	return ans >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
	int signed_high = signed_high_prod(x, y);
	int w = sizeof(int) << 3;
	int xw = (int)x >> (w -1); 
	int yw = (int)y >> (w -1);
//	printf("%x\n", signed_high_prod(x, y));
	return signed_high_prod(x, y) + x&yw + y&xw;
}

int main() {
	int x = 0x80000000;
	int y = 0x70000000;
	signed_high_prod(x, y);
	printf("%x", unsigned_high_prod(x, y));
	return 0;
}
