#include<stdio.h>

int main()
{
	float cap, price[100], weight[100], maxprof, profit = 0;
	int i,n,curr, items_left, used[100];
	printf("Enter no. of items:  ");
	scanf ("%d", &n);
	printf("Enter knapsack capacity: ");
	scanf("%f",&cap);
	items_left = n;
	for (i = 0; i < n; i++)
	{
		printf("Enter price for item[%d]: ", i+1);
		scanf("%f", &price[i]);
		printf("Enter weight for item[%d]: ", i+1);
		scanf("%f", &weight[i]);
	}
	maxprof = 0;
	for(i = 0; i<n; i++)
	{
		used[i] = 0;
	}
	while(cap > 0 && items_left > 0)
	{
		maxprof= -1;
		for(i = 0; i<n; i++)
		{
			if(((price[i]/weight[i]) > maxprof) && (used[i] == 0))
			{
				maxprof = price[i]/weight[i];
				curr = i;
			}
		}
		profit += price[curr];
		cap -= weight[curr];
		items_left--;
		used[curr] = 1;
		if(cap >= 0)
		{
			price[curr] = 0;
			printf("Item %d completely used\n", curr + 1);
		}
		else
		{
			profit -= price[curr];
			cap += weight[curr];
			profit+= (price[curr]*(cap/weight[curr]));
			printf("Item %d %.2f used\n", curr, cap*100/weight[curr]);
			cap= 0;
			price[curr]= 0;
		}
	}
	printf("Total profit: %f\nused items: %d\ncapacity left: %f", profit, n-items_left, cap);
	
	return 0;
}


