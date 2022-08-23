#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int front=-1,rear=-1;
int queue[MAX];

void enqueue()
{
	int val;
	
	printf("\nEnter Value:");
	scanf("%d",&val);
	
	if(rear == MAX-1)
	{
		printf("\nOVERFLOW");
	}
		if(rear == -1 && front == -1)
	{
		front =0;
		rear =0;
	}
	else
	{
		rear= rear +1;
	}
	queue[rear]=val;
	printf("\nValue inserted");
}

void delqueue()
{
	int val;
	
	if(front == -1 || front > rear)
	{
		printf("\nUNDERFLOW");
		return;
	}
	else
	{
		val = queue[front];
		if(front == rear)
		{
			front =-1;
			rear = -1;
		}
		else
		{
			front = front + 1;
		}
		printf("\n%d value is deleted",val);
	}
}

void display()
{
	int i;
	if(rear == -1)
	{
		printf("\nQueue is empty");
		return;
	}
	else
	{
		printf("\nPrinting Queue elements");
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
	}
}

void main()
{
	int ch=0;
	
	do
	{
		printf("\n*************************Main Menu*****************************\n");  
        printf("\n=================================================================\n");  
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter choice:");
        scanf("%d",&ch);
        
        switch(ch)
        {
        	case 1:
        		enqueue();
        		break;
        	case 2:
        		delqueue();
        		break;
        	case 3:
        		display();
        		break;
        	case 4:
        		exit(0);
        		break;
        	default:
        		printf("\nEnter correct input");
		}
	}while(ch != 4);
}
