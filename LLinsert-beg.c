#include<stdio.h>  
#include<stdlib.h>  

struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *start; 

void beginsert()  
{  
    struct node *new_node;  
    int num;  
    new_node = (struct node *) malloc(sizeof(struct node *));  
    if(new_node == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter value\n");    
        scanf("%d",&num);    
        new_node->data = num;  
        new_node->next = start;  
        start = new_node;  
        printf("\nNode inserted");  
    }  
      
} 

void display()  
{  
    struct node *ptr;  
    ptr = start;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (ptr!=NULL)  
        {  
            printf("\t%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
}   

void main ()  
{  
    int choice =0;  
    while(choice != 3)   
    {  
        printf("\n\n*********Main Menu*********\n");   
        printf("\n1.Insert in begining\n2.Display\n3.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            beginsert();    
			break;
			case 2:
			display();
			break;
			case 3:
			exit(0);
			break;  
     	}
	}
}
