#include<stdio.h>
#include<ctype.h>
#define MAX 100
float str[MAX];
int top=-1;

void push(float val)
{
	if(top==MAX-1)
	{
		printf("\nStack Overflow:");
		return;
	}
	top++;
	str[top]=val;
}

float pop()
{
	float tmp;
	if(top==-1)
	{
		printf("\nStack Underflow:");
		return '0';
	}
	tmp=str[top];
	top--;
	return tmp;
}

float evalPostfixExpression(char *exp)
{
	int i=0;
	float op1, op2, value;
	
	while(exp[i]!='\0')
	{
		if(isdigit(exp[i]))
		{
			push((float)(exp[i]-'0'));
		}
		else	
		{
			op2=pop();
			op1=pop();
			
			switch(exp[i])
			{
				case '+':
				value=op1+op2;
				break;
				
				case '-':
				value=op1-op2;
				break;
				
				case '*':
				value=op1*op2;
				break;
				
				case '/':
				value=op1/op2;
				break;
				
				case '%':
				value=(int)op1%(int)op2;
				break;
			}
			push(value);
		}
		
		i++;
	}
	
	return(pop());
}

void main()
{
	float result;
	char expr[MAX];
	
	printf("\nEnter Any Postfix Expression:");
	gets(expr);
	
	printf("\nValue of the Postfix Expression is:");
	result=evalPostfixExpression(expr);
	printf("%.2f",result);
}
