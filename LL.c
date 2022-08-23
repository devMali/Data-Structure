#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *start;  
  
void beginsert ();   
void lastinsert ();  
void randominsert(); 
void begin_delete();  
void last_delete();  
void random_delete();  
void display();  
void search();  
void main ()  
{  
    int choice =0;  
    while(choice != 9)   
    {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n  5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n10.insbfr\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            beginsert();      
            break;  
            case 2:  
            lastinsert();         
            break;  
            case 3:  
            randominsert();       
            break;  
            case 4:  
            begin_delete();       
            break;  
            case 5:  
            last_delete();        
            break;  
            case 6:  
            random_delete();          
            break;  
            case 7:  
            search();         
            break;  
            case 8:  
            display();        
            break;  
            case 9:  
            exit(0);  
            break; 
			case 10:
			insbfr();
			break; 
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
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
void lastinsert()  
{  
    struct node *new_node,*temp;  
    int num;     
    new_node = (struct node*)malloc(sizeof(struct node));      
    if(new_node == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value?\n");  
        scanf("%d",&num);  
        new_node->data = num;  
        if(start == NULL)  
        {  
            new_node -> next = NULL;  
            start = new_node;  
            printf("\nNode inserted");  
        }  
        else  
        {  
            temp = start;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = new_node;  
            new_node->next = NULL;  
            printf("\nNode inserted");  
          
        }  
    }  
}  
void randominsert()  
{  
    int i,loc,num;   
    struct node *new_node, *temp;  
    new_node = (struct node *) malloc (sizeof(struct node));  
    if(new_node == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter element value");  
        scanf("%d",&num);  
        new_node->data = num;  
        printf("\nEnter the location after which you want to insert ");  
        scanf("\n%d",&loc);  
        temp=start;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
          
        }  
        new_node ->next = temp ->next;   
        temp ->next = new_node;   
        printf("\nNode inserted");  
    }  
} 

void insbfr()
{
	struct node *curr,*prev,*new1;
	int val,key;
	
	printf("\nEnter element value");  
    scanf("%d",&val);  
    printf("\nEnter the location before which you want to insert ");  
    scanf("\n%d",&key);  
        
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=val;
	new1->next=NULL;
	
	if(start->data==val)
	{
		new1->next=start;
		///return;
	}
	
	while(curr->data !=key && curr!=NULL)
	{
		prev=curr;
		curr=curr->next;
	}
	
	if(curr==NULL)
	{
		printf("\n key not found");
	//	return;
	}
	new1->next=curr;
	prev->next=new1;
	printf("\n node inserted");
}



void begin_delete()  
{  
    struct node *new_node;  
    if(start == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        new_node = start;  
        start = new_node->next;  
        free(new_node);  
        printf("\nNode deleted from the begining ...\n");  
    }  
}  
void last_delete()  
{  
    struct node *new_node,*new_node1;  
    if(start == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(start -> next == NULL)  
    {  
        start = NULL;  
        free(start);  
        printf("\nOnly node of the list deleted ...\n");  
    }  
          
    else  
    {  
        new_node = start;   
        while(new_node->next != NULL)  
        {  
            new_node1 = new_node;  
            new_node = new_node ->next;  
        }  
        new_node1->next = NULL;  
        free(new_node);  
        printf("\nDeleted Node from the last ...\n");  
    }     
}  
void random_delete()  
{  
    struct node *new_node,*new_node1;  
    int loc,i;    
    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&loc);  
    new_node=start;  
    for(i=0;i<loc;i++)  
    {  
        new_node1 = new_node;       
        new_node = new_node->next;  
              
        if(new_node == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    new_node1 ->next = new_node ->next;  
    free(new_node);  
    printf("\nDeleted node %d ",loc+1);  
}  
void search()  
{  
    struct node *new_node;  
    int num,i=0,flag;  
    new_node = start;   
    if(new_node == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter num which you want to search?\n");   
        scanf("%d",&num);  
        while (new_node!=NULL)  
        {  
            if(new_node->data == num)  
            {  
                printf("num found at location %d ",i+1);  
                flag=0;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            new_node = new_node -> next;  
        }  
        if(flag==1)  
        {  
            printf("num not found\n");  
        }  
    }     
          
}  
  
void display()  
{  
    struct node *new_node;  
    new_node = start;   
    if(new_node == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (new_node!=NULL)  
        {  
            printf("\n%d",new_node->data);  
            new_node = new_node -> next;  
        }  
    }  
}     
              
