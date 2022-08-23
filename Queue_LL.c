#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;   

void insert()  
{  
    struct node *new1;  
    int val;   
      
    new1 = (struct node *) malloc (sizeof(struct node));  
    if(new1 == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter value:\n");  
        scanf("%d",&val);  
        new1 -> data = val;  
        if(front == NULL)  
        {  
            front = new1;  
            rear = new1;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = new1;  
            rear = new1;  
            new1->next = NULL;  
        }  
    }  
}     
void delete ()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
        printf("\nValue deleted");
    }  
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        while(ptr != NULL)   
        {  
            printf("%d\t",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}  

void main ()  
{  
    int choice;   
    while(choice != 4)   
    {     
        printf("\n*************************Main Menu*****************************\n");  
        printf("\n=================================================================\n");  
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice:");  
        scanf("%d",& choice);  
        switch(choice)  
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
            case 4:  
            exit(0);  
            break;  
            default:   
            printf("\nEnter valid choice....!\n");  
        }  
    }  
}  

