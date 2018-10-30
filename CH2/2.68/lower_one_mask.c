#include<stdio.h>

/*
 *Mask with least signficaant n bits set to 1
 *Examples: n = 6 -->0x3F, n = 17 -->0x1FFFF
 *Assume 1 <= n <= w
 */
int lower_one_mask(int n){
	return (2<<(n-1))-1;
}
 
int main(){
	int x = 2;
	printf("%x", lower_one_mask(x));
//	printf("%x", (1<<32)-1);
	return 0;
}
