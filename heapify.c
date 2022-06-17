#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;

void swap(int *x, int *y)
{
	count++;
	int temp = *x;
	*x=*y;
	*y=temp;
}

void display(int A[], int n)
{
	for(int i=0;i<n-1;i++)
		printf("%d ",A[i]);
	printf("\n");
}

void heapify(int A[], int n, int i)
{
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	
	if (l < n && A[l] > A[largest])
		largest = l;
		
	if (r < n && A[r] > A[largest])
		largest = r;
	
	if (largest != i)
	{
		swap(&A[i],&A[largest]);
		heapify(A, n, largest);
	}

}

void heapSort(int A[], int n)
{
	for(int i=n/2 -1;i>=0;i--)
		heapify(A, n, i);
		
	for(int i=n-1;i>=0;i--)
	{
		swap(&A[0],&A[i]);
		display(A,n);
		heapify(A, i, 0);
	}
}
/*
void heapSortRamdon(int A[], int n)
{
	for(int i=n/2 -1;i>=0;i--)
		heapify(A, n, i);
		
	for(int i=n-1;i>=0;i--)
	{
		swap(&A[0],&A[i]);
		heapify(A, i, 0);
	}
}
*/
int main()
{
	int n=1000;
	printf("Enter Size of ARRAY: ");
	scanf("%d", &n);
	int A[n];

	srand(time(NULL));

	for(int i=0;i<n;i++)
		A[i]=rand()%101;

	heapSort(A,n);

	printf("\nSorted Array: ");
	display(A,n);
	printf("\nCount: %d\n",count);
	
	return 0;
}
