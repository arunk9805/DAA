
#include<stdio.h>
#include<stdlib.h>

int cnt=0;

int power2(int x, int y)
{	
	if(y==0)
		return 1;
	if(x==0)
		return 0;
	int r=(x*power2(x,y-1));
	cnt++;
	return r;
}

int main()
{
	int x, y;
	printf("Enter x and y: ");
	scanf("%d%d", &x, &y);
	
	int result= power2(x,y);
	
	printf("\nRESULT: %d\n",result);
	printf("\nCOUNT: %d\n",cnt);
	return 0;
}
