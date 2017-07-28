#include<stdio.h>
#include<ctype.h>
#define MAX 100

typedef struct stack
{
	int a[MAX];
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

int pop(struct stack *ps)
{
	return(ps->a[ps->top--]);
}

int operation(int n1,int n2,char opr)
{
	int ans;
	switch(opr)
	{
		case '+':
			ans=n1+n2;
			break;
		case '*':
			ans=n1*n2;
			break;
		case '-':
			ans=n1-n2;
			break;
		case '/':
			ans=n1/n2;
		break;
	}
	return(ans);
}

int evaluate(char post[])
{
	stack s1;
	int i,num1,num2,eval;
	s1.top=-1;
	for(i=0;post[i]!='\0';i++)
	{
		if(isdigit(post[i])){
			push(&s1,post[i]-'0');
			printf("\n%c-%c",post[i]-'0',post[i]);
		}
		else
		{
			num2=pop(&s1);
			num1=pop(&s1);
			eval=operation(num1,num2,post[i]);
			push(&s1,eval);
		}
	}
	return pop(&s1);
}

int main()
{
	char postfix[30];
	int result;
	printf("ENTER THE POSTFIX EXPRESSION\n");
	scanf("%s",postfix);
	result=evaluate(postfix);
	printf("\nANS= %d",result);
	return 0;
}
