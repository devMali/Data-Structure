#include <stdio.h>
struct node
{
	int data;
	struct node *next;
};

struct node *front=-1;
struct node *rear =-1;

void enqueue()
{
	int val;
	struct node *new1;
	printf("\nEnter value:");
	scanf("%d",&val);
	
	new1= (struct node *)malloc(sizeof(struct node));
	new1->data=val;
	new1->next=0;
	
	
	if(rear == -1)
	{
		front = rear = new1;
		rear->next = front;
	}
	else
	{
		rear->next = new1;
		rear = new1;
		rear->next = front;
	}
}

void dequeue()
{
	struct node *tmp;
	tmp=front;
	
	if((front==-1) && (rear == -1))
	{
		printf("\nQueue is empty");
	}
	else
	{
		if(front==rear)
		{
			front = rear = -1;
			free(tmp);
		}
		else
		{
			front = front->next;
			rear->next = front;
			free(tmp);
		}
	}
}

void display()
{
	struct node *ptr;
	ptr=front;
	
	if((front==-1) && (rear == -1))
	{
		printf("\nQueue is empty");
	}
	else
	{
		while(ptr->next != front)	
		{
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
			printf("%d\t",ptr->data);
	}	
	
}

void main ()  
{  
	int choice;   
    while(choice != 4)   
    {     
        printf("\n*************************Main Menu*****************************\n");  
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice:");  
        scanf("%d",& choice);  
        switch(choice)  
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
            break;  
            default:   
            printf("\nEnter valid choice....!\n");  
        }  
    }  
}  

