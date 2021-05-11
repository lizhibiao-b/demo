/*
希尔排序
*/

#include <stdio.h>

void shell_sort(int *arr, int len);

int main (void)
{
    int arr[]={21,3,5,34,25,56,7,8,10};
    int len=9;
    shell_sort(arr,len);
    for(int i=0;i<len;i++)
        printf("%d,",arr[i]);
    putchar('\n');
    return 0;
}

void shell_sort(int *arr, int len)
{
    int i,j,Increment;
    for(Increment=len/2;Increment>0;Increment/=2)
    {
        for(i=Increment;i<len;i++)  // 组内采用插入排序
        {
            for(j=i;j>=Increment;j-=Increment)
            {
                if(arr[j]>arr[j-1])
                    break;
                int t=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=t;
            }
            // arr[j]=t;
        }
    }
}