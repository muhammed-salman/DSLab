#include<stdio.h>
#include<ctype.h>
#define MAX 100

typedef struct stack
{
	char a[MAX];
	int top;
}stack;

void push(struct stack *ps,char n)
{
	if(ps->top!=MAX-1)
	{
		ps->top++;
		ps->a[ps->top]=n;
	}
	else
		printf("\nSTACK IS FULL");
}

char pop(struct stack *ps)
{
	return(ps->a[ps->top--]);
}

int ismatchingpair(char left,char right)
{
	switch(left)
	{
		case '(':
			if(right==')')
				return 1;
			else
				return 0;
		case '{':
			if(right=='}')
				return 1;
			else
				return 0;
		case '[':
			if(right==']')
				return 1;
			else
				return 0;
		default:
				return 0;			
	}
}

void checkedbalanced(char exp[])
{
	stack s;
	int i,c;
	s.top=-1;
	for(i=0;exp[i]!='\0';i++){
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
			push(&s,exp[i]);
		else
		{
			if(s.top==-1)
			{
				printf("\nInvalid Expression");
				return;
			}
			c=pop(&s);
			if(ismatchingpair(c,exp[i]))
				continue;
			else{
				printf("\nInvalid Expression");
				return;
			}	
		}	
	}
	if(s.top==-1)
		printf("\nExpression is valid");
	else
		printf("\nInvalid Expression");	
}

int main()
{
	char exp[MAX];
	printf("ENTER THE EXPRESSION CONTAINING PARENTHESES\n");
	scanf("%s",exp);
	checkedbalanced(exp);
	return 0;
}
