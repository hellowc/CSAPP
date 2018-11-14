test:
	mov		0x120(%rsi), %ecx       # 将bp->last读入到%ecx
	add		(%rsi),	%ecx	        # 执行n = bp->first + bp->last
	lea		(%rdi,%rdi,4),%rax      # i*5
	lea		(%rsi,%rax,8),%rax	# bp + i*40 次处%rax中的值并不是&bp->a[i],
						# 因为i是随机值且b_struct的第一个元素是整数first
	mov		0x8(%rax),%rdx		# 取出ap->idx放到%rbx中, 由此可以看出0x8(%rax)是ap
						# a_struct的大小是40，并且8位对齐，ap->%idx是a_struct中的第一个元素
	movslq		%ecx,%rcx		# 将int n扩展为long n, 所以ap->idx是long类型
	mov		%rcx,0x10(%rax,%rdx,8)	# 执行ap->x[ap->idx]
						# %rax + 0x8 = ap; ap + 0x8 = ap->x;
						# 因此%rax + 0x10 = ap->x; 
						# ap->x + %rdx*8 = ap->x[a->idx], 所以ap->x[]是long数组
/*	
	A:	因为a_struct 8位对齐，因此a[CNT]大小为0x120-0x8， CNT = 0x118 / 40 = 7

	B:	typedef struct {
			long idx;
			long x[4];
		} a_struct;
*/
