#include <stdio.h>
#include <string.h>
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
int parition(int arr[],int l,int h)
{
	int pivot=arr[h];
	int i=l-1;
	int j;
	for(j=l;j<=h-1;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[j],&arr[i]);
		}
	}
	swap(&arr[i+1],&arr[h]);
	return (i+1);
}
void quicksort(int arr[],int l,int h)
{
	if(l<h)
	{
		int pi=parition(arr,l,h);
		quicksort(arr,l,pi-1);
		quicksort(arr,pi+1,h);
	}
}
/*int quickselect(int arr[],int left,int right,int k)
{
	if(left==right)
		return arr[left];
	int split=parition(arr,left,right);
	int p=split-left+1;
	if(k==p)
		return arr[split];
	else if(k<p)
		return quickselect(arr,left,split-1,k);
	else
		return quickselect(arr,split+1,right,k-p);
}*/
int main()
{
	int n;
	printf("Enter how many numbers to sort : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter numbers\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,n-1);
	printf("Sorted Numbers are : \n");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
