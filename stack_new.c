#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *top=NULL;

void push()
{
	int val;
	struct node *new1;
	new1=(struct node *)malloc(sizeof(struct node));
	
	printf("\nEnter data:");
	scanf("%d",&val);
	
	if(top == NULL)
	{
		new1->data=val;
		new1->next=NULL;
		top=new1;
	}
	else
	{
		new1->data=val;
		new1->next=top;
		top=new1;
	}
	
	printf("\nValue pushed");
}

void pop()
{
	struct node *ptr;
	int val;
	
	ptr=top;
	val=ptr->data;
	top = top->next;
	free(ptr);
	
	printf("\n%d value popped",val);
	
}

void display()
{
	struct node *ptr;
	
	ptr=top;
	
	if(ptr == NULL)
	{
		printf("\nStack is empty");
	}
	else
	{
		printf("\nPrinting stack elements...\n");
		
		while(ptr != NULL)
		{
			printf("%d\n",ptr->data);
			ptr = ptr->next;
		}
	}
}

void main()
{
	int ch =0;
	
	do
	{
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
		
	}while(ch != 4);
}



