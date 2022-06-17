#include<stdio.h>

int cnt=0;

long long int power(long long int a,long long  int b)
{	
	cnt++;
	
	if(b==0)
		return 1;
	
	long long int temp=power(a,b/2);
	
	if(b%2==0)
		return temp*temp;
	else
		return a*temp*temp;
}
/*
int power2(int x, int y)
{	
	cnt++;
	if(y==0)
		return 1;
	if(x==0)
		return 0;
		
	return x*power2(x,y-1);
}
*/
int main()
{
	long long int x, y;
	printf("Enter x and y: ");
	scanf("%lld%lld", &x, &y);
	
	long long int result= power(x,y);
	
	printf("\nRESULT: %lld\n",result);
	printf("\nCOUNT: %d\n",cnt);
	return 0;
}
