#include <stdio.h>

void main()
{
	int i,j,r,c;
	int a[10][10];//,b[10];
	
	printf("Enter the number of rows (between 1 and 10): ");
	scanf("%d", &r);
	printf("Enter the number of columns (between 1 and 10): ");
	scanf("%d", &c);
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("\nEnter value a[%d][%d]:",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("\n\nDisplaying Adjacency matrix:\n\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	
}
