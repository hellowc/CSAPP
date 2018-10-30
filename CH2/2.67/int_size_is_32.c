#include<stdio.h>

//int 至少位32位的机器能正常运行 
int bit32_int_size_is_32(){
	int set_msb = 1 <<	31;
	int temp_msb = 1<< 16;
	int beyond_msb = temp_msb << 16;
	
	return set_msb && !beyond_msb;
}

//int 至少位16位的机器能正常运行 
int bit16_int_size_is_32(){
	int temp_msb_1 = 1 << 15;
	int temp_msb_2 = temp_msb_1 << 15;
	int set_msb = temp_msb_2 << 1;
	int beyond_msb = temp_msb_2 << 2;
	
	return set_msb && !beyond_msb;
}

int main(){
	printf("%d", bit32_int_size_is_32());
	return 0;
}
