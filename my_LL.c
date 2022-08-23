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
	struct node *new1, *ptr;
	int val;
	printf("\n Enter -1 to end");
	printf("\n Enter the data : ");
	scanf("%d", &val);
	
	while(val!=-1)
	{
		
	 new1 = (struct node*)malloc(sizeof(struct node));
	 new1 -> data=val;
	 
	 if(start==NULL)
	 {
	 	new1-> next = NULL;
	 	start = new1;
	 }
	 else
	 {
		 ptr=start;
		 while(ptr->next!=NULL)
		 ptr=ptr->next;
		 
		 ptr->next = new1;
		 new1->next=NULL;
	 }
	
	 printf("\n Enter the data : ");
	 scanf("%d", &val);
	 
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
		printf("\n Enter Value:");
		scanf("%d",&val);
		
		new1->data=val;
		new1->next=start;
		start=new1;
		printf("\nNode insertd");
	}
}
	
void lastinsert()
{
	struct node *new1,*tmp;
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
		{
			tmp=tmp->next;
		}
		tmp->next=new1;
		new1->next=NULL;
	}
	printf("\n Node inserted");
}

void display()
{
	struct node *ptr;
	ptr=start;
	
	if(ptr==NULL)
		printf("\nLinked list is empty");
	else
	{
		printf("\nPrinting node:\n");
		while(ptr != NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
	}
}

void insaft()
{
	struct node *new1,*ptr,*preptr;
	int val,key;
	
	printf("\nEnter value to be inserted:");
	scanf("%d",&val);
	printf("\nEnter the value after you want to insert the value:");
	scanf("%d",&key);
	
	ptr=preptr=start;
	while(preptr->data != key && ptr != NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	
	if(preptr->data != key)
	{
		printf("\nKey not found");
	}
	else
	{
		new1=(struct node *)malloc(sizeof(struct node));
		new1->data=val;
		preptr->next=new1;
		new1->next=ptr;	
		printf("\n Node inserted");		
	}

}

void insbfr()
{
	struct node *ptr,*preptr,*new1;
	int val,key;	
	
	printf("\nEnter value to be inserted:");
	scanf("%d",&val);
	printf("\nEnter the value before you want to insert the value:");
	scanf("%d",&key);
	
	preptr=ptr=start;
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=val;
	
	while(ptr->data != key && ptr !=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new1;
	new1->next=ptr;
	
	printf("\nNode inserted");
}

void delfirst()
{
	struct node *ptr;
	ptr=start;
	
	if(start==NULL)
		printf("\nUnderflow");
	else
	{
		ptr=start;
		start=start->next;
		free(ptr);
		printf("\nFirst node Deleted");
	}
}

void delast()
{
	struct node *ptr,*preptr;
	
	if(start==NULL)
		printf("\nUnderflow");
	else
	{
		ptr=start;
		while(ptr->next != NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=NULL;
		free(ptr);
		printf("\nLast Node Deleted");
	}
}

void main ()  
{  
    int choice =0;  
    while(choice != 8)   
    {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n0.Create LL\n1.Insert in begining\n2.Insert at last\n3.Insert After\n4.Insert Before\n5.Delete First\n6.Delete Last\n7.Display\n8.Exit\n");  
        printf("\n===============================================\n");  
		printf("\nEnter your choice:");         
        scanf("%d",&choice);  
        
        switch(choice)  
        {  
            case 0:  
            create();      
            break;  
            case 1:  
            beginsert();      
            break;  
            case 2:  
            lastinsert();         
            break;  
            case 3:  
            insaft();       
            break;  
            case 4:  
            insbfr();       
            break;  
            case 5:  
            delfirst();       
            break;  
            case 6:  
            delast();       
            break;  
            case 7:  
            display();       
            break;
            case 8:  
            exit(0);       
            break;    
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  





