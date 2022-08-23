#include <stdio.h>
#define MAX 5
int top =-1;
int st[MAX];

void push()
{
	int val;
	
	if(top == MAX-1)
		printf("\nstack is full");
	else
	{
		printf("\nENter value:")	;
		scanf("%d",&val);
		
		top++;
		st[top]= val;
	}
}
void pop()
{
	int val;
	if(top == -1)
		printf("\nStack is empty");
	else
	{
		val=st[top];
		printf("\n%d value popped",val);
		top--;
	}
}

void display()
{
	int i;
	if(top == -1)
		printf("\nStack is empty");
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%d ",st[i]);
		}
	}
}

void main()
{
   int ch=0;
    do
    {
    	printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
        printf("\n Enter the Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    while(ch!=4);
}

