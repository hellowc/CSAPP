#include<stdio.h>

int check(int x){
	return !((x & 0xff) ^ (0xff)) || !(x & (0xff << ((sizeof(int) - 1) << 3)));  //���λȫ1��������λȫ0 
}

int main(){
	int a = 0x01ffff10;
	printf("%d", check(a));
	return 0;
}
