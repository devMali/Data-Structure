#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *start;

void create()
{
	struct node *new1,*ptr;
	int val;
	
	printf("\nEnter -1 to end");
	printf("\nEnter num:");
	scanf("%d",&val);
	
	
	while(val != -1)
	{
		new1=(struct node *)malloc(sizeof(struct node));
		
		if(start == NULL)
		{
			new1->data=val;
			new1->prev=NULL;
			new1->next=NULL;
			start=new1;
		}
		else
		{
			ptr=start;
			
			while(ptr->next != NULL)
				ptr= ptr->next;
			
			new1->data=val;
			new1->next = NULL;
			new1->prev = ptr;
			ptr->next =new1;
			
		}
		
		printf("\nEnter num:");
		scanf("%d",&val);
	}
	
}

void beginsert()
{
	struct node *new1;
	int val;
	new1=(struct node *)malloc(sizeof(struct node));
	
	printf("\nEnter any value:");
	scanf("%d",&val);
	
	if(start==NULL)  
   	{	 
       new1->next = NULL;  
       new1->prev=NULL;  
       new1->data=val;  
       start=new1;  
   	}
	else  
	{
		new1->data=val;
		start->prev=new1;
		new1->next=start;
	
		new1->prev=NULL;
		start=new1;	
	}
	printf("\nNode inserted in the begining");
}

void lastinsert()
{
	struct node *new1,*ptr;
	int val;
	new1=(struct node *)malloc(sizeof(struct node));
	
	printf("\nEnter any value:");
	scanf("%d",&val);	
	new1->data=val;
	
	ptr=start;
	while(ptr->next != NULL)
		ptr= ptr->next;
	
	ptr->next=new1;
	new1->prev=ptr;
	new1->next=NULL;
	
	printf("\nNode inserted at the end");
}

void insaft()
{
	struct node *new1,*ptr,*preptr;
	int val,num;
	
	printf("\nEnter any value:");
	scanf("%d",&val);
	
	printf("\nEnter value to be search:");
	scanf("%d",&num);	
	
	ptr=preptr=start;	
	
	while(preptr->data != num && preptr->next != NULL)
	{
		preptr=ptr;
		ptr= ptr->next;
	}
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=val;
	preptr->next=new1;
	new1->prev=preptr;
	new1->next=ptr;
	ptr->prev=new1;
	
	printf("\nNode inserted");
}

void insbfr()
{
	struct node *new1,*ptr,*preptr;
	int val,num;
	
	printf("\nEnter any value:");
	scanf("%d",&val);
	
	printf("\nEnter value to be search:");
	scanf("%d",&num);
	
	ptr=preptr=start;
	
	while(ptr->data != num && ptr->next != NULL)
	{
		preptr=ptr;
		ptr= ptr->next;
	}
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=val;
	preptr->next=new1;
	new1->prev=preptr;
	new1->next=ptr;
	ptr->prev=new1;
	
	printf("\nNode inserted");
}

void display()
{
	struct node *ptr;
	ptr=start;
	
	printf("\nPrinting values:");
	//	printf("%d ",ptr->data);
	while(ptr != NULL)
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
}

void delfirst()
{
	struct node *ptr;
	
	ptr=start;
	start=start->next;
	start->prev=NULL;
	free(ptr);
	
	printf("\nFirst node deleted");
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
	int num;
	
	printf("\nEnter value to be delted:");
	scanf("%d",&num);
	ptr=start;
	
	while(ptr->data != num && ptr != NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	ptr->next->prev=preptr;
	free(ptr);
	
	printf("\nNode deleted");
}

void delaft()
{
	struct node *ptr,*preptr;
	int num;
	
	printf("\nEnter number after you want to do deletion:");
	scanf("%d",&num);
	preptr=ptr=start;
	
	while(preptr->data != num && ptr != NULL)
	{
		preptr= ptr;
		ptr= ptr->next;
	}
	preptr->next=ptr->next;
	ptr->next->prev=preptr;
	free(ptr);
	
	printf("\nNode deleted");
	
}
void delbfr()
{
	struct node *ptr,*preptr;
	int num;
	
	printf("\nEnter number before you want to do deletion:");
	scanf("%d",&num);
	preptr=ptr=start;
	
	while(ptr->data != num && ptr != NULL)
	{
		preptr= ptr;
		ptr= ptr->next;
	}
	
	ptr->prev = preptr->prev;
	preptr->prev->next = ptr;
	free(preptr);
	printf("\nNode deleted");
	
	
}

void main ()  
{  
    int choice =0;  
    while(choice != 8)   
    {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n0.Create LL\n1.Insert in begining\n2.Insert at last\n3.Insert After\n4.Insert Before\n5.Delete First\n6.Delete Last\n7.Display\n8.Exit\n9.Delete node\n10.delete after a node\n11delete before a node");  
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
		 	case 9:  
            delnode();       
            break;
		 	case 10:  
            delaft();       
            break;
		 	case 11:  
            delbfr();       
            break;
		 	default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  

