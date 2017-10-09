#include<stdio.h>
#define MAX_SIZE 100
int binary_search(int a[],int num,int n){
	int low=0,high=n-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(a[mid]==num)
			return mid;
		else{
			if(num>a[mid])
				low=mid+1;
			else
				high=mid-1;
		}
	}
	return -1;				
}

int main(){
	int a[MAX_SIZE],i,pos,n,e;
	printf("\nEnter the size of array(1 to 100): ");
	scanf("%d",&n);	
	if(n<0 || n>100)
	{
		printf("\nInvalid Array Size");
		return 0;
	}
	printf("\nEnter the elements of array in ascending order: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nEnter the element to be searched: ");
	scanf("%d",&e);
	pos=binary_search(a,e,n);
	if(pos==-1)
		printf("\nThe Element is not found");
	else
		printf("\nThe Element is found at %d position",pos);
	return 0;		
}
