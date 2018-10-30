#include<stdio.h>

/* Copy integer into buffer if space is available */
//void copy_int(int val, void *buf, int maxbytes) {
//	if(maxbytes - sizeof(val) >= 0) {
//		memcpy(buf, (void *) &val, sizeof(val));
//	}
//} 

int main() {
	int val = 0x12345678;
	int maxbytes = 2;
	if(maxbytes - (int)sizeof(val) >= 0) {
		printf("%d", maxbytes - sizeof(val));
	} else {
		printf("0");
	}
}
