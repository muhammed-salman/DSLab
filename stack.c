#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int stack[MAX_SIZE],top=-1;

int isFull(){
	//returns 1 if stack is full else returns -1
	return top==MAX_SIZE-1;
	
}

int isEmpty(){
//returns 1 if stack is empty else returns -1
	return top==-1;
	
}

int peek(){
//return element at the top of stack
	return stack[top];
}

void push(int e){
//inserts an element into stack
	if(!isFull())
	{
		top++;//increment the top
		stack[top]=e;//set top of stack equal e
		printf("\nYour element %d is successfully inserted",e);//msg element e successfully inserted
	}
	else{
		//msg stack overflow
		printf("\nElement cannot be inserted. Stack Overflow!");
	}
}

void pop(){
//deletes an element from top of stack
	int d;
	if(!isEmpty())
	{
		d=stack[top];//d=top of stack
		top--;//decrement the top
		printf("\nYour element %d is successfully deleted",d);//msg element d successfully deleted
	}
	else{
		printf("\nElement cannot be deleted. Stack Underflow!");//msg stack underflow
	}
}

int main(){
	int choice,e;
	do
	{
		//display menu 1.peek 2.push 3.pop 4.exit
		printf("\nEnter\n1.Peek\n2.Push\n3.Pop\n4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);	//take input in choice variable
		switch(choice){
			case 1:
				e=peek();//call peek function
				printf("\nElement at the top of stack is : %d",e);
				break;
			case 2:
				printf("\nEnter the elment to be inserted: ");
				scanf("%d",&e);
				push(e);//call push function
				break;
			case 3:
				pop();//call pop function
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
