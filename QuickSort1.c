#include <stdio.h>

void QuickSort(int s[], char l, char r)
{
    int i = l, j = r, num = s[l];
    if (l < r) //递归满足条件
    {

        while (i < j)
        {
            while (i < j && s[j] >= num)//从右向左找
                    j--;
            // if find
            if (i < j)
                s[i++] = s[j];//填坑

            while (i < j && s[i] < num)//左向右查找
                    i++;
            if (i < j)
                s[j--] = s[i];
        }
        //退出时，i=j
        s[i] = num;
        QuickSort(s, l, i-1);
        QuickSort(s, i+1, r);

    }
}
int main(void)
{
    int s[] = {245,25,15,16,15,323,52,145,123,555,112,9,38};
    char len = sizeof(s)/sizeof(s[0]);

    QuickSort(s,0,len-1);
    char i = 0;
    for (;i < len; i++)
        printf("%d ",s[i]);
    return 0;
}
