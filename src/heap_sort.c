/*
堆排序
*/

#include <stdio.h>

void Swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

//堆调整 大堆顶，将最大值放在根结点
void BigHeadAdjust(int *arr,int index,int length)
{
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	int max = index;
	if (lchild<length&&arr[lchild]>arr[max])
	{
		max = lchild;
	}
	if (rchild<length&&arr[rchild]>arr[max])
	{
		max = rchild;
	}
	if (max != index)
	{
		Swap(&arr[max], &arr[index]);
		BigHeadAdjust(arr, max, length);
	}
	return;
}
 
//堆排序，采用大顶堆 升序
void HeapSort_Up(int *arr, int length)
{
	//初始化堆，将每个非叶子结点倒叙进行大顶堆调整。
	//循环完毕 初始大顶堆（每个根结点都比它孩子结点值大）形成
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		BigHeadAdjust(arr, i, length);
	}
	// printf("大堆顶初始化顺序：");
	// PrintArr(arr, length);
	//将堆顶值放到数组尾部，然后又进行大堆顶调整，一次堆调整最值就到堆顶了。 
	for (int i = length - 1; i >= 0; i--)
	{
		Swap(&arr[0], &arr[i]);
		BigHeadAdjust(arr, 0, i);
	}
	return;

}

int main(void)
{
    int arr[]={10,23,43,2,4,7,11,78,9,15,22};
    int len=sizeof(arr)/sizeof(int);
    HeapSort_Up(arr,len);
    for(int i=0;i<len;i++)
        printf("%d,",arr[i]);
    return 0;
}