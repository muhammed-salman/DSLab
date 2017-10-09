#include<stdio.h>
#define MAX_SIZE 100

int split(int arr[],int lower,int upper){
	int pivot=lower,a=lower+1,b=upper,temp;
	while(b>a){
		while(arr[a]<arr[pivot])
			a++;
		while(arr[b]>arr[pivot])
			b--;
		if(b>a)
		{
			temp=arr[a];
			arr[a]=arr[b];
			arr[b]=temp;
		}
	}
	temp=arr[pivot];
	arr[pivot]=arr[b];
	arr[b]=temp;
	return b;			
}

void quick_sort(int a[],int lower,int upper){
	int i;
	if(lower<upper){
		i=split(a,lower,upper);
		quick_sort(a,lower,i-1);
		quick_sort(a,i+1,upper);
	}				
}


int main(){
	int a[MAX_SIZE],i,n;
	printf("\nEnter the size of array(1 to 100): ");
	scanf("%d",&n);	
	if(n<0 || n>100)
	{
		printf("\nInvalid Array Size");
		return 0;
	}
	printf("\nEnter the elements of array:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quick_sort(a,0,n-1);	
	printf("\nSorted Array:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	return 0;		
}
