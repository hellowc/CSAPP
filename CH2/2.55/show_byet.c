#include<stdio.h>

typedef unsigned char *byte_pointer;
	
void show_byte(byte_pointer start, size_t len){
	size_t i;
	for(i = 0; i < len; i++)
		printf("%.2x ", start[i]);
	printf("\n");
}

void show_int(int x){
	show_byte((byte_pointer)&x, sizeof(int));
}

void show_float(float x){
	show_byte((byte_pointer)&x, sizeof(float));
}

void show_poniter(void *x){
	show_byte((byte_pointer)&x, sizeof(void *));
}

int main(){
//	int val = 0;
//	show_int(val);
//	printf("%f", *(float *)(&val));
	float a = ;
	show_byte((byte_pointer)&a, sizeof(float));
	return 0;
} 
