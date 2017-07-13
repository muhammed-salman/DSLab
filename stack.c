#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int stack[MAX_SIZE],top=-1;

int isFull(){
	//returns 1 if stack is full else returns -1
	return (top==MAX_SIZE-1)?1:-1;
}

int isEmpty(){
//returns 1 if stack is empty else returns -1
}

int peek(){
//return element at the top of stack
}

void push(int e){
//inserts an element into stack
	if(whether the stack is not full)
	{
		//increment the top
		//set top of stack equal e
		//msg element e successfully inserted
	}
	else{
		//msg stack overflow
	}
}

void pop(){
//deletes an element from top of stack
	int d;
	if(whether the stack is not empty)
	{
		//d=top of stack
		//decrement the top
		//msg element d successfully deleted
	}
	else{
		//msg stack underflow
	}
}

int main(){
	int choice,e;
	do
	{
		//display menu 1.peek 2.push 3.pop 4.exit
		printf("enter your choice");
		//take input in choice variable
		switch(choice){
			case 1:
				//call peek function
				break;
			case 2:
				//call push function
				break;
			case 3:
				//call pop function
				break;
			case 4:
				//call exit(0) function or return 0
				break;
			default:
				//invalid choice				
		}
	}while(1);
	return 0;
}
