#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int queue[MAX_SIZE],front=-1,rear=-1;

int isFull(){
	return rear==MAX_SIZE-1;	
}

int isEmpty(){
	return front==-1&&rear==-1;	
}

void display(){
	int i;
	if(!isEmpty())
		for(i=front;i<=rear;i++)
			printf("%d\t",queue[i]);
	else{
		printf("\nQueue is Empty");
	}	
			
}

void insertqueue(int e){
	if(!isFull()){
		queue[++rear]=e;
		if(front==-1)
			front++;
		printf("\nElement %d is successfully Inserted",e);
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
			front++;
		printf("\nThe element deleted is %d",d);	
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
