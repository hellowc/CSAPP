#include<stdio.h>

int check(int x){
	return !((x & 0xff) ^ (0xff)) || !(x & (0xff << ((sizeof(int) - 1) << 3)));  //最低位全1，或做高位全0 
}

int main(){
	int a = 0x01ffff10;
	printf("%d", check(a));
	return 0;
}
