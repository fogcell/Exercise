#include <stdio.h>
int n;
int a[6] ={14, 18, 16, 13, 15, 17};

void quicksort(int left,int right)
{
    int i,j,t,temp;
    if(left>right)//递归结束条件
        return;
    temp=a[left];
    i=left;
    j=right;
    while(i!=j)
    {
        while(a[j]>=temp && i<j)
            j--;
        while(a[i]<temp && i<j)
            i++;
        if(i<j)//严格检查是否相遇
        {
            t = a[i];
            a[i]=a[j];
            a[j] = t;
        }
    }
        a[left]=a[i];
        a[i]=temp;
        quicksort(left,i-1);
        quicksort(i+1,right);

}
void main(void)
{

   int i;
   quicksort(0,5);
   for (i=0;i<6;i++)
   {
       printf("%d ",a[i]);
   }



}
