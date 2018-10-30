#include<stdio.h> 

/*
 *Generate mask indicating leftmost 1 in x, Assume w=32.
 *For example, 0xFF00 -> 0x800, and 0x6600 -->0x4000.
 *If a = 0, then return 0. 
*/
int leftmost_one(unsigned x){
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return x ^ (x >> 1); 
}

int main(){
	int a = 0x11011000;
	printf("%x", leftmost_one(a));
	return 0;
}
