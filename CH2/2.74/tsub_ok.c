#include<stdio.h>

/* Determine whether arguments can be subtracted without overflow */
int tsub_ok(int x, int y) {
	int w = sizeof(int) << 3;
	int t = x - y;
	x >>= (w -1);
	y >>= (w -1);
	t >>= (w -1);
	int pos_ovf = ~x & y & t;
	int non_ovf = x & ~y & ~t;
	return ~(pos_ovf | non_ovf);
}

//´óÀÐ½â´ð
int tsub_ok0(int x, int y) {
	int w = sizeof(int) << 3;
	int t = x - y;
	x >>= (w -1);
	y >>= (w -1);
	t >>= (w -1);
	return !((x != y) && (y == t));
} 

int main() {
	printf("%d", tsub_ok0(0x7fffffff, 0x000fffff));
	return 0; 
} 
