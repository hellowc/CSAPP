#include<stdio.h>

/*Return 1 when x contains an odd number of 1s; 0 otherwise
Assume w=32*/
//´óÀĞ½â´ğ 
int odd_ones(int x){
	x ^= x>>1;
	x ^= x>>2;
	x ^= x>>4;
	x ^= x>>8;
	x ^= x>>16;
	return x & 1£» 
}

int main(){
	int a = 3;
	printf("%d", odd_ones(a));
	return 0;
} 
