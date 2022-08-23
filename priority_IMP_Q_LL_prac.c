#include <stdio.h>
#include <malloc.h>
#include <conio.h>

struct node
{
	int data;
	int prio;
	struct node *next;
};

struct node *start=NULL;

void insert()
{
	int val,pri;
	struct node *new1,*ptr;
	
	printf("\nEnter value:");
	scanf("%d",&val);
	printf("\nEnter Priority:");
	scanf("%d",&pri);
	
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data =val;
	new1->prio=pri;
	
	if(start == NULL || pri < start->prio)
	{
		new1->next=start;
		start = new1;	
	}
	else
	{
		ptr= start;
		while(ptr->next != NULL && ptr->next->prio <= pri)
			ptr= ptr->next;
			
		new1->next = ptr->next;
		ptr->next = new1;
	}
}

void delete()
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
}

void display()
{
	struct node *ptr;
	
	ptr= start;
	printf("\n PRIORITY QUEUE IS : " );
	while(ptr != NULL)
	{
		printf("\n %d pri-> %d",ptr->data,ptr->prio);
		ptr = ptr->next;
	}
}

void main()
{
	int ch;
	
	do
	{
		 printf("\n *****MAIN MENU*****");
		 printf("\n 1. INSERT");
		 printf("\n 2. DELETE");
		 printf("\n 3. DISPLAY");
		 printf("\n 4. EXIT");
		 printf("\n Enter your choice : ");
		 scanf( "%d", &ch);
		switch(ch)
		 {
			 case 1:
			 	insert();
				break;
			 case 2:
			 	delete();
				break;
			 case 3:
			 	display();
				break;
		  	}
	}while(ch!=4);
}


