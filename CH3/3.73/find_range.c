#include <stdio.h>

typedef enum{NEG, ZERO, POS, OTHER} range_t;


range_t find_range(float x) {
    __asm__(
	"vxorps	%xmm1, %xmm1, %xmm1\n\t"
	"vucomiss	%xmm1, %xmm0\n\t"
	"jp	.L5\n\t"
	"jb	.L4\n\t"
	"je	.L3\n\t"
	"movl	$2, %eax\n\t"
	"jmp 	.DONE\n\t"
      ".L3:\n\t"
	"movl	$1, %eax\n\t"
	"jmp	.DONE\n\t"
      ".L4:\n\t"
	"movl	$0, %eax\n\t"
	"jmp 	.DONE\n\t"
      ".L5:\n\t"
	"movl	$3, %eax\n\t"
      ".DONE:\n\t"
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
