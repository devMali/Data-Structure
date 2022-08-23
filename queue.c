    #include <stdio.h>
	#include <stdlib.h>
	
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *start=NULL;
	
	void enqueue()
	{
		int val;
		struct node *new1,*ptr;
		new1= (struct node *)malloc(sizeof(struct node));
		printf("\nEnter value:");
		scanf("%d",&val);
		
		if(start == NULL)
		{
			new1->data=val;
			new1->next=NULL;
			start=new1;
		}
		else
		{
			ptr=start;
			
			while(ptr->next != NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new1;
			new1->data=val;
			new1->next=NULL;
		}
		printf("\nNode inserted");
	}
	
	
	void dequeue()
	{
		int val;
		struct node *ptr;
		ptr=start;
		
		if(ptr==NULL)
			printf("\nQueue is empty");
		else
		{
			val=ptr->data;
			start=start->next;
			free(ptr);
			printf("\nValue %d is deleted",val);
		}
		
	}
	
	void display()
	{
		struct node *ptr;
		
		ptr=start;
		
		if(ptr == NULL)
		{
			printf("\nQueue is empty");
		}
		else
		{
			printf("\nPrinting queue elements...\n");
			
			while(ptr != NULL)
			{
				printf("%d ",ptr->data);
				ptr = ptr->next;
			}
		}
	}
	
	void main()
	{
		int ch =0;
		
		do
		{
			printf("\n1.Insert");
			printf("\n2.Delete");
			printf("\n3.Display");
			printf("\n4.Exit");
			printf("\nEnter choice:");
			scanf("%d",&ch);
			
			switch(ch)
			{
				case 1:
					enqueue();
					break;
				case 2:
					dequeue();
					break;
				case 3:
					display();
					break;
				case 4:
					exit(0);
			}
			
		}while(ch != 4);
	}
	
	

