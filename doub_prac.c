void beginsert()
{
	struct node *new1;
	int val;
	
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=val;
	
	if(start == NULL)
	{
		new1->next=NULL;
		new1->prev=NULL;
		start =new1;
	}
	else
	{
		start->prev=new1;
		new1->next=start;
		new1->prev=NULL;
		start= new1;
	}
}

void lastinsert()
{
	struct node *new1,*ptr;
	
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=val;
	
	ptr=start;
	
	while(ptr->next != NULL)
		ptr=ptr->next;
	
	ptr->next=new1;
	new1->prev=ptr;
	new1->next=NULL;
	
}

void insaft()
{
	struct node *new1,*ptr,*preptr;
	
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=val;
	
	preptr=ptr=start;
	while(preptr->data != key && ptr != NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new1;
	new1->prev=preptr;
	new1->next=ptr;
	ptr->prev=new1;
}


void insbfr()
{
	struct node *new1,*ptr,*preptr;
	
	new1=(struct node *)malloc(sizeof (struct node));
	new1->data=val;
	
	ptr=preptr=start;
	
	while(ptr->next != key && ptr != NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	
	preptr->next=new1;
	new1->prev=preptr;
	ptr->prev=new1;
	new1->next=ptr;
}













