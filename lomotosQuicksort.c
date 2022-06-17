#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;

void swap(int *x, int *y)
{
    int temp = *x;
    *x=*y;
    *y=temp;
}

int partition(int A[], int p, int r)
{
    int x=A[r];
    int i=p-1,j;
    for(j=p;j<r;j++)
    {
        if(A[j]<=x)
        {
            i++;
            count++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[r]);
        return (i+1);
}

void quickSort(int A[], int p, int r)
{
    if(p<r)
    {
        int q=partition(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
    }
}

void display(int A[], int n)
{
    int i=0;
    for(i=0;i<=(n-1);i++)
        printf("%d ",A[i]);
}

int main()
{

    //int n=10,i;


//    int *A=(int *)malloc(sizeof(int)*n);
	int A[6]={8,4,12,1,7,9};
	quickSort(A,0,5);
	display(A,6);
	printf ("\nComparisons for des elements: %d\n", count);
/*
    FILE *fp;
    fp = fopen("Rand.txt", "r");
    i = 0;
    while (fscanf(fp, "%d", &A[i]) != EOF)
        i++;
    quickSort(A, 0, n-1);
    
    printf ("Comparisons for random elements: %d\n", count);
    fclose(fp);
    count = 0;

    fp = fopen("asc.txt", "r");
    i = 0;
    while (fscanf(fp, "%d", &A[i]) != EOF)
        i++;
    quickSort(A, 0, n-1);
    printf ("Comparisons for ascending elements: %d\n", count);
    fclose(fp);
    count = 0;

    fp = fopen("des.txt", "r");
    i = 0;
    while (fscanf(fp, "%d", &A[i]) != EOF)
        i++;
    quickSort(A, 0, n-1);
    printf ("Comparisons for des elements: %d\n", count);
    fclose(fp);
    count = 0;
*/
    return 0;
}
