#include <stdio.h>
#include <ctype.h>
#define MAX 100

float str[MAX];
int top =-1;

void push(float val)
{
	if(top == MAX-1)
	{
		printf("\nStack Overflow");
		return;
	}
	top++;
	str[top]=val;
}

float pop()
{
	float val;
	
	if(top == -1)
	{
		printf("\nStack Underflow");
		return;
	}
	val=str[top];
	top--;
	return val;
}

float evalExpr(char *exp)
{
	int i=0;
	float op1,op2,val;
	
	while(exp[i] != '\0')
	{
		if(isdigit(exp[i]))
		{
			push((float)(exp[i] - '0'));
		}
		else
		{
			op2 = pop();
			op1 = pop();
			
			switch(exp[i])
			{
				case '+':
					val=op1+op2;
					break;
				case '-':
					val=op1-op2;
					break;
				case '*':
					val=op1*op2;
					break;
				case '/':
					val=op1/op2;
					break;
				case '%':
					val=(int)op1 % (int)op2;
					break;	
			}
			push(val);
		}
		i++;
	}
	return (pop());
}

void main()
{
	float result;
	char expr[MAX];
	
	printf("\nEnter Any Postfix Expression:");
	gets(expr);
	
	printf("\nValue of the Postfix Expression is:");
	result=evalExpr(expr);
	printf("%f",result);
}
