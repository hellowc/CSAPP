#include<stdio.h>

/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y) {
	int w = sizeof(int) << 3;
	int t = x + y;
	int ans = t;
	x >>= (w - 1);
	y >>= (w - 1);
	t >>= (w - 1);
	int pos_ovf = ~x & ~y & t;
	int neg_ovf = x & y & ~t;
	int non_ovf = ~(pos_ovf | neg_ovf);
	return (pos_ovf & ((1 << (w - 1)) - 1)) | (neg_ovf & (1 << (w-1))) | (non_ovf & ans);
}

int main() {
	int x = 0x7fffffff;
	int y = 0x7fffffff;
	printf("%d", saturating_add(x, y));
	return 0;
}
