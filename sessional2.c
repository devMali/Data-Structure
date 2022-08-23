#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root;

void insert()
{
	struct node *new1,*curr,*prev;
	int val;
	
	new1=(struct node *)malloc(sizeof(struct node));
	
	printf("\nEnter value:");
	scanf("%d",&val);
	
	new1->data = val;
	new1->right = NULL;
	new1->left = NULL;
	
	if(root == NULL)
	{
		root = new1;
		root->left = NULL;
		root->right = NULL;	
	}
	else
	{
		curr = root;
		
		while(curr != NULL)
		{
			prev = curr;
			
			if(val < curr->data)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if(val < prev->data)
			prev->left = new1;
		else
			prev->right = new1;
	}
	printf("value %d is inserted in tree\n",val);
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

void main()
{
	int ch=0;
	
	do
	{
		printf("\n\n1.Insert element in Tree");
		printf("\n2.InOrder Traversal");
		printf("\n3.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				insert(root);
				break;
			case 2:
				printf("\nInOrder Traversal:\n");
				inorder(root);
				break;
			case 3:
				printf("\nGood Bye...");
				exit(0);
				break;
			default:
				printf("\nEnter valid choice...");
		}
		
	}while(ch != 3);
}
