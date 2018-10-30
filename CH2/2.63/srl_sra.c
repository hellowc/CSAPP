#include<stdio.h>
unsigned srl(unsigned x, int k){
	/*proform shift arithmetic*/
	unsigned xsra = (int) x>> k;
	return xsra & ~(((1 << k) - 1) << ((sizeof(int) << 3) - k));
}

int sra(int x, int k){
	/*perform shift logically*/
	int xsrl = (unsigned) x >> k;
	return xsrl & (-1);
}

int main(){
	int a = 0xe0000000;
	printf("%x", sra(a, 2));
	return 0;
}
