#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root=NULL;

void insert()
{
	int val;
	struct node *new1,*curr,*prev;
	
	printf("\nEnter value:");
	scanf("%d",&val);
	
	new1= (struct node *)malloc(sizeof(struct node));
	new1->data=val;
	new1->left=NULL;
	new1->right=NULL;
	
	if(root == NULL)
	{
		root = new1;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		curr=root;
			while(curr != NULL)
		  {
			prev= curr;
			
			if(val<curr->data)
				curr= curr->left;
			else
				curr = curr->right;
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


void main()
	{
		int ch =0;
		
		do
		{
			printf("\n1.Insert");
			printf("\n2.PreOrder");
			printf("\n3.InOrder");
			printf("\n4.PostOrder");
			printf("\n5.Exit");
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
					exit(0);
					
			}
			
		}while(ch != 5);
	}
	
	

