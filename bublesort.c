#include <stdio.h>
void main(void)
{
   int a[] ={14, 18, 16, 13, 15, 17};
   int i,j,t;
   int n = 0;

   for (i=0;i<5;i++)
   {
       for (j=0;j<5-i;j++)
       {
           if (a[j]>a[j+1])
           {
               t=a[j];
               a[j]=a[j+1];
               a[j+1]=t;
               ++n;
           }
       }
   }
   printf("%d",n);

}
