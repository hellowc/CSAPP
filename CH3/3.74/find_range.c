#include <stdio.h>

typedef enum{NEG, ZERO, POS, OTHER} range_t;


range_t find_range(float x) {
    __asm__(
    	"movl	$0, %eax\n\t"
	"movl	$1, %r8d\n\t"
	"movl	$2, %r9d\n\t"
	"movl	$3, %r10d\n\t"
	"vxorps	%xmm1, %xmm1, %xmm1\n\t"
	"vucomiss	%xmm1, %xmm0\n\t"
	"cmove	%r8d, %eax\n\t"
	"cmova	%r9d, %eax\n\t"
	"cmovp	%r10d, %eax\n\t"
   );
}

int main() {
	printf("nan  -> %d\n", find_range(0.0/0.0));
	printf("pos  -> %d\n", find_range(1.0));
	printf("-zero -> %d\n", find_range(-0.0));
	printf("+zero -> %d\n", find_range(0.0));
	printf("neg  -> %d\n", find_range(-10.0));
	return 0;
}
