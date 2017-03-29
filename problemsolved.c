int cal(int a,int b)//Calculate that the two numbers have several binary bits different
{
	int M = a ^ b;
	int num = 0;
	while (M) {
	    M &= (M-1);
	    num++;
	}
	return num;
}
int bit_count0(unsigned int n)
{
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);

	return n;
}
struct _byte {
	unsigned a:1;
	unsigned b:1;
	unsigned c:1;
	unsigned d:1;
	unsigned e:1;
	unsigned f:1;
	unsigned g:1;
	unsigned h:1;
};
long get_bit_count(unsigned char b)
{
	struct _byte *by = (struct _byte*)&b;
	return (by->a + by->b + by->c + by->d + by->e +by->f + by->g + by->h);
}
