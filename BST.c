#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *right;
	struct node *left; 
}*root=NULL;

void insert()
{
	int val;
	struct node *new1,*curr,*prev;
	printf("\nEnter Value:");
	scanf("%d",&val);
	
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=val;
	new1->left=NULL;
	new1->right=NULL;
		
	if(root == NULL)
	{
		root=new1;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		curr=root;
		while(curr != NULL)
		{
			prev=curr;
			
			if(val < curr->data)
				curr=curr->left;
			else
				curr=curr->right;

		}
		if(val < prev->data)
			prev->left=new1;
		else
			prev->right=new1;
	}
}

void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	if(root != NULL)
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}

void findSmall(struct node *root)
{
	struct node *ptr;
	ptr=root;
	int s;
	if( (root == NULL) || (root->left == NULL))
		printf("\nTree is empty");
	else
	{
		while(ptr->left != NULL)
		ptr= ptr->left;
	
		s=ptr->data;
		printf("\n%d is smallest element in tree",s);
		
	}
}
void findLarge(struct node *root)
{
	struct node *ptr;
	ptr=root;
	int s;
	if( (root == NULL) || (root->right == NULL))
		printf("\nTree is empty");
	else
	{
		while(ptr->right != NULL)
		ptr= ptr->right;
	
		s=ptr->data;
		printf("\n%d is Largest element in tree",s);
		
	}
}
int total(struct node *root)
{
	int c;
	if(root == NULL)
		return 0;
	else
	{
		return(total(root->left) +total(root->right) +1);
	}
}

int search(struct node *root)
{
	int val;
	printf("\nEnter value:");
	scanf("%d",&val);
	
	if(root == NULL)
		return 0;
	else
	{
		if(root->data == val)
			return root->data;
		else if (val < root->data)
			return search(root->left);
		else
			return search(root->right);
			
	}
}
void main()
	{
		int ch =0,t,s;
		
		do
		{
			printf("\n1.Insert");
			printf("\n2.PreOrder");
			printf("\n3.InOrder");
			printf("\n4.PostOrder");
			printf("\n5.Find smallest element");
			printf("\n6.Find largest element");
			printf("\n7.total");
			printf("\n8.Exit");
			printf("\n9.search");
			
			printf("\nEnter choice:");
			scanf("%d",&ch);
			
			switch(ch)
			{
				case 1:
					insert();
					break;
				case 2:
					preorder(root);
					break;
				case 3:
					inorder(root);
					break;
				case 4:
					postorder(root);
					break;
				case 5:
					findSmall(root);
					break;
				case 6:
					findLarge(root);
					break;
				case 7:
					t=total(root);
					printf("\nTotal node are:%d",t);
					break;
				case 8:
					exit(0);
				case 9:
					s=search(root);
					printf("\nvalue %d found",s);
					break;
					
			}
			
		}while(ch != 8);
	}
	
	

