/*Description: Prefix to postfix conversion
 * Author: Muhammed Salman Shamsi
 */
#include<stdio.h>
#include<ctype.h> //for isaplha() & isdigit()
#include<string.h>
#define MAX_SIZE 30
typedef struct char_stack
{
	char a[MAX_SIZE][MAX_SIZE];//array of strings
	int top;
}stack;

void push(stack*,char*);

char *pop(stack*);

void convert(char[],char[]);


int main()
{
	char prefix[MAX_SIZE],postfix[MAX_SIZE];
	printf("\nENTER PREFIX EXPRESSION\n");
	scanf("%s",prefix);
	convert(prefix,postfix);
	printf("\n\nPOSTFIX EXPRESSION\n%s",postfix);
	return 0;
}

void convert(char pre[],char post[])
{
	stack s1;
	char opr1[MAX_SIZE],opr2[MAX_SIZE],opr[MAX_SIZE];
	int i;
	int len=strlen(pre);
	s1.top=-1;
	//step1: scan prefix expression from right to left
	for(i=len-1;i>=0;i--) 
	{
		//step2:if current symbol is a operand than push it into stack
		if(isalpha(pre[i])||isdigit(pre[i])){ 
			//storing current symbol as string
			opr[0]=pre[i];
			opr[1]='\0';
			//push the curren symbol as a string onto stack
			push(&s1,opr);
		}
		//step 3: if the current symbol is a operator than pop two string from stack
		//concatenate them as {operand1,operand2,operator} and 
		//push the resulting string onto the stack 
		if(pre[i]=='+'||pre[i]=='-'||pre[i]=='/'||pre[i]=='*')
		{
				if(s1.top!=-1){
					strcpy(opr1,pop(&s1));//poping first string
					strcpy(opr2,pop(&s1)); //poping second string
					opr[0]=pre[i]; //storing operator as string
					opr[1]='\0';
					strcat(opr1,opr2); //opr1=opr1(concat)opr2
					strcat(opr1,opr); //op1=opr1(concat)opr
					push(&s1,opr1); //push the resultant sting onto stack
				}
				else{
					printf("\nInvalid Prefix Expression");
				}	
		}
	}
	//step4: string at the top of stack is the postfix expression
	while(s1.top!=-1)
		strcpy(post,pop(&s1));//remove the string from top of stack and put it in postfix
 }


void push(stack *s,char *opr)
{
	if(s->top==MAX_SIZE-1)
		printf("\nStack Overflow\n");
	else{	
		strcpy(s->a[++s->top],opr);
	}
}

char* pop(stack *s)
{
	if (s->top==-1)
	{
		printf("Stack Underflow\n");
		return 0;
    }
    else
    {
		char * data=s->a[s->top--];
		return data;
    }
}

/*
 Outputs:

 ENTER PREFIX EXPRESSION
-*+ABC*-DE+FG


POSTFIX EXPRESSION
AB+C*DE-FG+*-

---------------------
ENTER PREFIX EXPRESSION
++A*BCD          


POSTFIX EXPRESSION
ABC*+D+
------------------------
ENTER PREFIX EXPRESSION
*+AB+CD


POSTFIX EXPRESSION
AB+CD+*
*/
