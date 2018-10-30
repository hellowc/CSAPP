#include <stdio.h>

int is_little_endain(){
	int num = 33;
	unsigned char * byte_pointer =  (unsigned char *)(&num);
	char c = byte_pointer[0];
	return c == '!';
}

//´óÀĞ½â´ğ
int is_little_endain_1(){
	int a = 1;
	return *((unsigned char *)(&a));
} 

int main(){
	printf("%d",is_little_endain_1());
	return 0;
} 
