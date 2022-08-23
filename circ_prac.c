void beginsert()
{
	struct node *new1,*ptr;
	
	new1=(struct node *)malloc(sizeof(struct node));
	new2->data =val;
	
	ptr=start;
	while(ptr->next != start)
		ptr=ptr->next;
	
	ptr->next=new1;
	new1->next=start;
	start= new1;
}

void lastinsert()
{
	struct node *new1,*ptr;
	new1=(struct node *)malloc(sizeof(sturct noe));
	
	ptr=start;
	while(ptr->next != start;)
	ptr=ptr->next;
	
	ptr->next=new1;
	new1->next=start;
}

void delfirst()
{
	struct node *ptr;
	
	ptr=start;
	
	while(ptr->next != start)
	ptr=ptr->next;
	
	ptr->next=start->next;
	start=start->nextl
	free(ptr);
}

void delast()
{
	struct node *ptr,*preptr;
	
	ptr=start;
	
	while(ptr->next != start)
		ptr=ptr->next;
	
	
}










