// quickSelect.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

//#include "stdafx.h"
#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int A[], int size, int q)
{
	int i;
	for (i = 0; i < size; i++)
		if (i != q)
		     printf("%d ", A[i]);
		else 
			printf("%d* ", A[i]);
	printf("\n");
}

int  Partition(int A[], int p, int r)
{
	int x;
	int i, j;

	i = p - 1;
	x = A[r];
	for (j = p; j <= r - 1; j++)
		if (A[j] <= x)
			swap(&A[++i], &A[j]);
	swap(&A[i + 1], &A[r]);
	 
	return i + 1;
}


int total;

int select(int A[], int p, int r, int i)  
{
	      
	if (p <= r) {
		int q = Partition(A, p, r);

		if (q == i)
			return A[q];
		else if (q >  i)
			return select(A, p, q - 1, i);
		else // Else recur for right subarray
			return select(A, q + 1, r, i);
	}
}


int main()
{
	int arr[] = { 98, 4, 9, 8, 22, 11, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k;

	printf(" k 번쨰 작은값(k=0은 첫번째) : ");
	scanf_s("%d", &k);
	n = sizeof(arr) / sizeof(arr[0]);
	total = n;
	printf("%d-th smallest element is = %d \n", k, select(arr, 0, n - 1, k));

	printArray(arr, n, k);
	getchar();
	getchar();

	return 0;
}

