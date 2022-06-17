#include<stdio.h>
#include<stdlib.h>

int count = 0;
int n = 0;

void swap(int* x, int* y)
{
	count++;
	int temp = *x;
	*x = *y;
	*y = temp;
}

void heapify(int H[], int i)
{
	int largest = i;
	int l = 2 * i;
	int r = 2 * i + 1;

	if (l < n && H[i] < H[l])
		largest = l;
	if (r < n && H[largest] < H[r])
		largest = r;
	if (i != largest)
	{
		swap(&H[i], &H[largest]);
		heapify(H, largest);
	}
}

int extractMax(int H[])
{
	if (n < 1)
	{
		printf("Heap Underflow!\n");
		return -1;
	}
	int max = H[1];
	H[1] = H[n];
	H[n] = -1;
	n = n - 1;
	heapify(H, 1);
	return max;
}

void heapIncrease(int H[], int i, int key)
{
	printf("\nKeepGoing\n");
	if (key < H[i])
	{
		printf("New key is smaller then current key\n");
		return;
	}
	H[i] = key;
	while (i > 1 && H[i / 2] < H[i])
	{
		swap(&H[i], &H[i / 2]);
		i = i / 2;
	}
	return;
}

void heapInsert(int H[], int key)
{
	n = n + 1;
	H[n] = -22;
	heapIncrease(H, n, key);
}

void heapSort(int A[])
{
	for (int j = n / 2 - 1;j >= 0;j--)
	{
		swap(&A[1], &A[j]);
		heapify(A, 1);
	}
}

int getMax(int H[])
{
	return H[1];
}

void display(int H[])
{
	int i = 0;
	printf("Elemets: ");
	for (i = 1;i <= n;i++)
		printf("%d ", H[i]);
}

int main()
{
	int choice;
	int key, key2, index = 0;
	int H[100];
	for (int i = 0; i < 101;i++)
		H[i] = 0;
	do
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Get Max\n4.Increase Key\n5.Exit\nEnter Choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:

			printf("Enter key: ");
			scanf("%d", &key);
			heapInsert(H, key);
			display(H);
			break;
		case 2:
			printf("Dequeued Element: %d\n", extractMax(H));
			display(H);
			break;
		case 3:
			printf("\n%d\n", getMax(H));
			break;
		case 4:
			printf("Enter key: ");
			scanf("%d", &key2);
			printf("Enter Index: ");
			scanf("%d", &index);
			heapIncrease(H, index, key2);
			display(H);
			break;
		case 5:
			break;

		}
	} while (choice != 5);
}
