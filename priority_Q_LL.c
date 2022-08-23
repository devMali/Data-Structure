#include <stdio.h>
#include <malloc.h>
#include <conio.h>
struct node
{
	int data;
	int priority;
	struct node *next;
};

struct node *start=NULL;
struct node *insert(struct node *);
struct node *delete(struct node *);
void display(struct node *);

int main()
{
	int option;
	
	do
	{
		 printf("\n *****MAIN MENU*****");
		 printf("\n 1. INSERT");
		 printf("\n 2. DELETE");
		 printf("\n 3. DISPLAY");
		 printf("\n 4. EXIT");
		 printf("\n Enter your option : ");
		 scanf( "%d", &option);
		switch(option)
		 {
			 case 1:
			 start=insert(start);
			break;
			 case 2:
			 start = delete(start);
			break;
			 case 3:
			 display(start);
			break;
		  	}
	}while(option!=4);
}

struct node *insert(struct node *start)
{
	int val, pri;
	struct node *new1, *ptr;
	
	new1 = (struct node *)malloc(sizeof(struct node));
	printf("\n Enter the value and its priority : " );
	scanf( "%d %d", &val, &pri);
	
	new1->data = val;
	new1->priority = pri;
	
	if(start==NULL || pri < start->priority )
	{
	 new1->next = start;
	 start = new1;
	}
	else
	{
	 ptr = start;
	 while(ptr->next != NULL && ptr->next->priority <= pri)
		 ptr = ptr->next;
	 new1->next = ptr->next;
	 ptr->next = new1;
	}
	return start;
}
struct node *delete(struct node *start)
{
	struct node *ptr;
	if(start == NULL)
	{
	 printf("\n UNDERFLOW" );
	 return;
	}
	else
	{
	 ptr = start;
	 printf("\n Deleted item is: %d", ptr->data);
	 start = start->next;
	 free(ptr);
	}
	return start;
}
void display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	if(start == NULL)
	 printf("\nQUEUE IS EMPTY" );
	else
	{
	 printf("\n PRIORITY QUEUE IS : " );
		while(ptr != NULL)
		 {
			 printf( "\t%d[priority=%d]", ptr->data, ptr->priority );
			 ptr=ptr->next;
		 }
	}
}
