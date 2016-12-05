//#define max(a,b) ((a) > (b) ? (a) :(b))
//#define min(a,b) ((a) > (b) ? (b) :(a))
//数组中最大值与最小值。将数组分成左右两部分，先求出左半部份的最大值和最小值，
//再求出右半部份的最大值和最小值，
//然后综合起来求总体的最大值及最小值。这是个递归过程，对于划分后的左右两部分，
//同样重复这个过程，直到划分区间内只剩一个元素或者两个元素。
void MaxandMin(int *a, int l, int r, int *maxValue, int *minValue)
{
	int m = (l + r) / 2;
	int lmax;//左半部分最大值
	int lmin;//右半部份最大值
	int rmax;
	int rmin;//左右部分
	printf("m:%d\n",m);
	if (l == r)//l与r之间只有一个元素
	{
		*maxValue = a[l];
		*minValue = a[l];
		return;
	}
	if (l + 1 == r)//l与r之间只有两个元素
	{
		if (a[l] >= a[r])
		{
			*maxValue = a[l];
			*minValue = a[r];
		} 
		else
		{
			*maxValue = a[r];
			*minValue = a[l];
		}
		return;
	} 
	
	MaxandMin(a, l, m, &lmax, &lmin); //递归计算左半部分

	
	MaxandMin(a, m + 1, r, &rmax, &rmin);//

	*maxValue = max(lmax, rmax);//总的最大值
	*minValue = min(lmin, rmin);
	
}
