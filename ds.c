#include <stdio.h>
struct point
{
	int x;
};
void main()
{
	int i;
	struct point p1[10];
	
	for(i=0;i<10;i++)
	{
		p1[i].x=i;
	}
	for(i=0;i<10;i++)
	{
		printf("\n%d",p1[i].x);
	}
}
