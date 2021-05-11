/*
插入排序
*/

#include <stdio.h>
#include <string.h>

void insert_sort(int *array, int len);

int main (void)
{
    int arr[]={21,3,5,34,25,56,7,8,10};
    int len=9;
    insert_sort(arr,len);
    return 0;
}

void insert_sort(int *array, int len)
{
    for(int i=1;i<len;i++)
    {
        int j=i;
        for(;j>=1;j--)
        {
            if(array[j]>array[j-1])     // 升序排序，降序排序则为<
                break;
            int t=array[j];         // 如果小于，与前一个交换位置，直到大于前一个元素
            array[j]=array[j-1];
            array[j-1]=t;
        }
    }

    for(int i=0;i<len;i++)
        printf("%d,",array[i]);
    printf("\n");
}