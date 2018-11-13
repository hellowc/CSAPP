long cread_alt(long *xp) {
	long t = 0;
	long *p = xp ? xp : &t;
	return *p;
}
