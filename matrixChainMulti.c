#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int op(int **s, int i, int j)
{
	if(i==j)
		printf("A%d",i);
	else
	{
		printf("(");
		op(s,i,s[i][j]);
		op(s,s[i][j]+1,j);
		printf(")");
	}
	return 0;
}

int mcm(int p[], int n)
{
	int i,j,k,l,q;
	int **m=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		m[i]=(int *)malloc(n*sizeof(int));
	int **s=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		s[i]=(int *)malloc(n*sizeof(int));
	for(i=1;i<n;i++)
		m[i][i]=0;
	for(l=2;l<n;l++)
	{
		for(i=1;i<n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	op(s,l,n-1);
	printf("\n");
	return m[1][n-1];
}

int main()
{
	int n,i;
	printf("Enter the number of matrices: ");
	scanf("%d",&n);
	n++;
	int arr[n];
	printf("Enter the dimensions: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("Minimum number of multiplications required is: %d\n",mcm(arr,size));
	return 0;
}
