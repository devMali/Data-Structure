#include <stdio.h>

void main()
{
	int arr[100],i,n,val;
	
	printf("\nEnter number of elemets:");
	scanf("%d",&n);
	
	printf("\nPlease enter in sorting order...");
	for(i=0;i<n;i++)
	{
		printf("\nEnte value:");
		scanf("%d",&arr[i]);
	}
	
	printf("\nEnter element to be search:");
	scanf("%d",&val);
	
	for(i=0;i<n;i++)
	{
		if(arr[i] == val)
		{
			printf("\nValue found at index:%d",i+1);
			break;
		}
		
	}
}
