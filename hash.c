#include<stdio.h>
#include<math.h>
#define MAX_SIZE 10
int hash(int k){
	return k%MAX_SIZE;
}
int linear_probe(int h){
	return ++h%MAX_SIZE;
}
int quadratic_probe(int h,int i){
	return (int)(h+pow(i,2))%MAX_SIZE;
}
int double_hash(int h, int i){
	return (h+i*linear_probe(h))%MAX_SIZE;
}
void display(int a[]){
	int i;
	printf("\nThe Elements of Array are\n");
	for(i=0;i<MAX_SIZE;i++)
		printf("%d\t",a[i]);	
}
int main(){
	int a[MAX_SIZE],i,ch,h,e,count;
	for(i=0;i<MAX_SIZE;i++)
		a[i]=-1;
	do{	
		count=0;
		printf("\nEnter the Number to be stored: ");
		scanf("%d",&e);
		h=hash(e);
		if(a[h]==-1){
			a[h]=e;
			display(a);
		}
		else
		{
			while(count<MAX_SIZE){
				count++;
				printf("\nCollission Occured at %d",h);
				printf("\nPlease Enter Your Choice for Resolution:");
				printf("\n1.Linear Probing\n2.Quadratic Probing\n3.DoubleHashing\n");
				scanf("%d",&ch);
				switch(ch){
					case 1:
						h=linear_probe(h);
						break;
					case 2:
						h=quadratic_probe(h,count);
						break;
					case 3:
						h=double_hash(h,count);
						break;
					default:
						printf("\nInvalid Choice");
						count--;
						break; 			
				}
				if(a[h]==-1)
				{
					a[h]=e;
					display(a);
					break;
				}
			 }
				
		}
		if(count==MAX_SIZE)
		{
			printf("\nArray is Full or Collision Resolution not successful");
			return 0;
		}	
				
	}while(1);
}
