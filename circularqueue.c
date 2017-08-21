/*Description: Implementation of circular queue using array
 * Learner: Muhammed Salman Shamsi
 * */
 
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int queue[MAX_SIZE],front=-1,rear=-1;

int isFull(){
	return ((rear==MAX_SIZE-1 && front==0)||(rear+1==front));	
}

int isEmpty(){
	return front==-1&&rear==-1;	
}

void display(){
	int i=front;
	if(!isEmpty()){
		while(i!=rear){
			printf("%d\t",queue[i]);
			i=(i+1)%MAX_SIZE;
		}
		printf("%d\t",queue[i]);
	}
	else{
		printf("\nQueue is Empty.");
	}	
			
}

void insertqueue(int e){
	if(!isFull()){
		rear=(rear+1)%(MAX_SIZE);
		queue[rear]=e;
		if(front==-1)
			front++;
		printf("\nElement %d is successfully Inserted",e);
		printf("\n%d-%d",front,rear);
	}
	else
		printf("\nQueue is Full Element cannot be inserted.");	
}

void deletequeue(){
	int d;
	if(!isEmpty()){
		d=queue[front];
		if(front==rear)
			front=rear=-1;
		else
			front=(front+1)%(MAX_SIZE);
		printf("\nThe element deleted is %d",d);
		printf("\n%d-%d",front,rear);	
	}
	else
		printf("\nQueue is Empty");	
}

int main(){
	int choice,e;
	do
	{
		printf("\n\nEnter\n1.Display\n2.Insert\n3.Delete\n4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);	//take input in choice variable
		switch(choice){
			case 1:
				printf("\nElements of queue are");
				display();
				break;
			case 2:
				printf("\nEnter the elment to be inserted: ");
				scanf("%d",&e);
				insertqueue(e);//call insertqueue function
				break;
			case 3:
				deletequeue();//call deletequeue function
				break;
			case 4:
				exit(0);//call exit(0) function or return 0
				break;
			default:
				printf("\nInvalid Choice");//invalid choice
				break;				
		}
	}while(1);
	return 0;
}
