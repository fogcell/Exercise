#include <stdio.h>
void MergeArray(int a[], char fist, char mid, char last, int temp[])
{
    int i = fist, j = mid +1; // i 为二分数组中的第一个的首位。 j 为二分数组的第二个的首位。
    int m = mid , l = last;   // m 为二分数组中的第一个的末位。 l 为二分数组的第二个的末位。
    int k = 0;                //遍历temp中的位
    while (i <= m && j <= l)  //逻辑与&&的优先级低
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];// 前面的首个元素比后一个的首位元素小则放在临时数组中的第一位。然后使计数值加1
        else
            temp[k++] = a[j++];
    }
    while (i <= m)             //前数组和后数组长度不相等时候可能i或者j还没有遍历完。a[]必须为已经排序好的数组。
        temp[k++] = a[i++];

    while (j <= l)
        temp[k++] = a[j++];
    //输出到a中去

    for (i = 0; i < k; i++)
        a[fist+i] = temp[i];

}
void MergeSort(int a[], int fist, int last, int temp[])
{
    int mid = 0;
    if (fist < last)
    {
        mid = (fist + last)/2;
        MergeSort(a, fist, mid, temp);//左边有序
        MergeSort(a, mid + 1, last,temp);//右边有序
        MergeArray(a, fist, mid, last, temp);

    }

}
int main(void)
{
    int a[] = {1,25,15,18,36,25,14,16,19,96,852,1489,15454,555,554,222,333,222};
    int b[120] = {0};
    int i = 0;
    char n = sizeof(a)/sizeof(a[0]);
    MergeSort(a,0,n-1,b);
    for(i = 0; i < n; i++)
        printf("%d\n",a[i]);
    return 0;
}
