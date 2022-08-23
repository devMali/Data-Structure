#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start;

void create()
{
	struct node *ptr,*new1;
	int num;
	
	printf("\n Enter -1 to end");
	printf("\n Enter the data : ");
	scanf("%d", &num);

	while(num != -1)
	{
		new1=(struct node *)malloc(sizeof(struct node));
		new1->data=num;
		
		if(start == NULL)
		{
			new1->next=NULL;
			start=new1;
		}
		else
		{
			ptr=start;
			while(ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next=new1;
			new1->next=NULL;
		}
		printf("\nEnter data:");
		scanf("%d",&num);
	}
}

void beginsert()
{
	struct node *new1;
	int val;
	new1=(struct node *)malloc(sizeof(struct node));
	
	if(new1==NULL)
		printf("\nOverflow");
	else
	{
		printf("\nEnter value:");
		scanf("%d",&val);
		new1->data=val;
		new1->next=start;
		start=new1;
		printf("\nNode inserted");
	}
}

void lastinsert()
{
	struct node *tmp,*new1;
	int val;
	new1=(struct node *)malloc(sizeof(struct node));
	
	printf("\nEnter value:");
	scanf("%d",&val);
	new1->data=val;
	
	if(start==NULL)
	{
		new1->next=NULL;
		start=new1;	
	}
	else
	{
		tmp=start;
		while(tmp->next != NULL)
			tmp=tmp->next;
		
		tmp->next=new1;
		new1->next=NULL;
	}
	printf("\nNode inserted");
}

void insaft()
{
	struct node *new1,*tmp;
	int val,key;
	
	printf("\nEnter value:");
	scanf("%d",&val);
	printf("\nEnter value after you want to insert");
	scanf("%d",&key);
	
	tmp=start;
	while(tmp->data != key && tmp != NULL)
		tmp=tmp->next;
	
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=val;
	new1->next=tmp->next;
	tmp->next=new1;
	
	printf("\nNode inserted");
}

void insbfr()
{
	struct node *new1,*ptr,*preptr;
	int val,key;
	
	printf("\nEnter value:");
	scanf("%d",&val);
	printf("\nEnter value before you want to insert");
	scanf("%d",&key);
	
	ptr=preptr=start;
	while(ptr->data != key && ptr != NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=val;
	preptr->next=new1;
	new1->next=ptr;
	
	printf("\nNode inserted");
}

void delfirst()
{
	struct node *ptr;
	
	if(start==NULL)	
		printf("\nLinked list is empty");
	else
	{
		ptr=start;
		start=start->next;
		free(ptr);
		printf("\nFirst Node deleted");
	}
}

void delast()
{
	struct node *ptr,*preptr;
	
	if(start==NULL)
		printf("\nLinked list is empty");
	else
	{
		ptr=start;
		
		while(ptr->next != NULL)
			{
				preptr=ptr;
				ptr= ptr->next;
			}

		preptr->next=NULL;
		free(ptr);
		printf("\nLast Node deleted");
	}
}
void delnode()
{
	struct node *ptr,*preptr;
	int val;
	
	printf("\nEnter number to be delete:");
	scanf("%d",&val);
	
	ptr=start;
	while(ptr->data != val && ptr->next != NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	
	preptr->next=ptr->next;
	free(ptr);
	printf("\nNode value %d deleted..",val);
}

void display()
{
	struct node *ptr;
	if(start==NULL)
		printf("\nLinked list is empty");
	else
	{
		ptr=start;
		printf("\nPrinting Values\n");
		while(ptr->next != NULL)
		{
			printf("%d ",ptr->data);
			ptr= ptr->next;
		}
	}
}







