#include <stdio.h>
void main(void)
{
   int a[11],i,j,t;
   for (i = 0;i < 11;i++)
   {
       a[i] = 0;
   }//简单排序
   for (i = 0;i < 5;i++)
   {
       scanf("%d",&t);
       a[t]++;
   }
   for (i = 10;i >= 0;i--)
    for (j = 1;j <= a[i];j++)
   {
       printf("%d ",i);
   }
}
