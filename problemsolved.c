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
