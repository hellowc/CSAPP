long decode2(long x, long y, long z) {
	long a = y - z;
	long b = x * a;
	unsigned long c = ((unsigned long)a) << 63;
	c = c >> 63;
	return b ^ c;
}
