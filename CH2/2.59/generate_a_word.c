#include <stdio.h>

int generate_a_word(int x, int y){
	return (x & 0xff) | (y & 0xffffff00);
}

//���н��
int generate_a_word(int x, int y){
	return (x & 0xff) | (y & ~0xff);
}

int main(){
	int a = 0x89abcdef;
	int b = 0x76543210;
	printf("%x", generate_a_word(a, b));
	return 0;	
} 
