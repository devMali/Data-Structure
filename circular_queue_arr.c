#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isEmpty() 
{
  if (front == -1) return 1;
  return 0;
}

int isFull() 
{
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

void enQueue() 
{
		
		int val;
		printf("\nEnter value:");
		scanf("%d",&val);
		
	  if (isFull())
	    printf("\n Queue is full!! \n");
	  else
	   {
		    if (front == -1) 
				front = 0;
				
		    rear = (rear + 1) % SIZE;
		    items[rear] = val;
		    printf("\n Inserted -> %d", val);
		}
}

int deQueue() 
{
	int val;
	  
	if (isEmpty()) 
	{
	    printf("\n Queue is empty !! \n");
	    return (-1);
	}
	else 
	{
		val = items[front];
		if (front == rear) 
		{
		  front = -1;
		  rear = -1;
		} 
		else
		{
		  front = (front + 1) % SIZE;
		}
		 
		printf("\n Deleted element -> %d \n", val);
		return (val);
	}
}

void display() 
{
	int i;
	if (isEmpty())
		printf(" \n Empty Queue\n");
		
	else
	{
		printf("\n Front -> %d ", front);
		printf("\n Items -> ");
		for (i = front; i != rear; i = (i + 1) % SIZE) {
		  printf("%d ", items[i]);
		}
		printf("%d ", items[i]);
		printf("\n Rear -> %d \n", rear);
	}
}

int main ()  
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
            enQueue();  
            break;  
            case 2:  
            deQueue();  
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

