#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define VALUE_SIZE 1000
#define ARRAY_SIZE 100

void PrintArray(int A[]);
void swap(int * num1, int * num2);
void Quick_Sort(int A[], int left, int right);
void Random_Quick_Sort(int A[], int left, int right);

int main() {

	srand((unsigned)time(NULL));
	int CheckDuplicate[VALUE_SIZE] = { 0 };
	int A[ARRAY_SIZE];
	int temp;

	/* 1. Unaligned random value */
	for (int i = 0; i < ARRAY_SIZE; ) {
		temp = rand() % 1000;
		if (CheckDuplicate[temp] == 0) {
			CheckDuplicate[temp] = 1;
			A[i] = temp;
			i++;
		}
	}

	PrintArray(A);

	return 0;
}

void PrintArray(int A[]) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", A[i]);
	}
	printf("\n\n");

	Quick_Sort(A, 0, ARRAY_SIZE - 1);
	//Random_Quick_Sort(A, 0, ARRAY_SIZE - 1);
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", A[i]);
	}
	return;
}

void swap(int * num1, int * num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	return;
}

void Quick_Sort(int A[], int left, int right) {
	int pivot = left;
	int first = pivot;
	int last;

	if (left < right) {
		for (last = left + 1; last <= right; last++) {
			if (A[last] < A[pivot]) {
				first++;
				swap(&A[first], &A[last]);
			}
		}
		swap(&A[left], &A[first]);
		pivot = first;

		Quick_Sort(A, left, pivot - 1);
		Quick_Sort(A, pivot + 1, right);
	}
	return;
}

void Random_Quick_Sort(int A[], int left, int right) {
	rand((unsigned)time(NULL));
	if (left < right) {
		// Randomized Partition //
		int pivot = (rand() % (right - left + 1)) + left;
		swap(&A[pivot], &A[left]);

		// The rest are the same. //
		pivot = left;
		int first = pivot;
		int last;

		for (last = left + 1; last <= right; last++) {
			if (A[last] < A[pivot]) {
				first++;
				swap(&A[first], &A[last]);
			}
		}
		swap(&A[left], &A[first]);
		pivot = first;

		Random_Quick_Sort(A, left, pivot - 1);
		Random_Quick_Sort(A, pivot + 1, right);
	}
	return;
}