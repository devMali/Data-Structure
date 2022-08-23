#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *start;

void insbeg()
{
	struct node *new1,*ptr;
	int val;
	
	printf("\nEnter value to insert:");
	scanf("%d",&val);
	
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=val;
	
	if(start == NULL)
	{
		new1->next=new1;
		start=new1;
	}
	else
	{
		ptr=start;
		
		while(ptr->next != start)
			ptr = ptr->next;
		
		ptr->next=new1;
		new1->next=start;
		start=new1;
	}
	printf("\nNode inserted...\n");
}

void display()
{
	struct node *ptr;
	ptr=start;
	
	if(ptr==NULL)
		printf("\nLinked list is empty\n");
	else
	{
		printf("\nPrinting linked list elements\n");
			
		while(ptr->next != start)
		{
			printf("%d ",ptr->data);
			ptr= ptr->next;	
		}
		printf("%d ",ptr->data);
		printf("\n");
	}
}

void main()
{
	int ch=0;
	
	while(ch != 3)
	{
		printf("\n------operations of circular Linked list--------");
		printf("\n1.Insert at beginning\n2.Display\n3.Exit");
		printf("\nEnter choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				insbeg();
				break;
			case 2:
				display();
				break;
			case 3:
				printf("\nGood Bye");
				exit(0);
				break;
		}
	}
}






