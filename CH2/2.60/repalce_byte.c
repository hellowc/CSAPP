#include<stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b){
	if(sizeof(unsigned) - 1 < i || i < 0)  //�淶i��ȡֵ 
		return 0;
	return (x & ~(0xff << (i<<3))) | ((unsigned)b << (i<<3));
}
 
int main(){
	printf("%x", replace_byte(0x12345678, 0, 0xab));
	return 0;
} 
