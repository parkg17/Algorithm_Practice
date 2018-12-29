#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define VALUE_SIZE 1000
#define ARRAY_SIZE 100

void PrintArray(int A[]);
void swap(int * num1, int * num2);
void Counting_Sort(int A[]);

int main() {

	srand((unsigned)time(NULL));
	int A[ARRAY_SIZE];

	/* 1. Unaligned random value */
	for (int i = 0; i < ARRAY_SIZE; i++) {
		A[i] = rand() % 1000;
	}

	PrintArray(A);

	return 0;
}

void PrintArray(int A[]) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", A[i]);
	}
	printf("\n\n");

	Counting_Sort(A);

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

void Counting_Sort(int A[]) {
	int i;
	int B[ARRAY_SIZE] = { 0 };
	int CountArr[VALUE_SIZE] = { 0 };

	for (i = 0; i < ARRAY_SIZE; i++) {
		CountArr[A[i]] = CountArr[A[i]] + 1;
	}

	for (i = 1; i < VALUE_SIZE; i++) {
		CountArr[i] += CountArr[i - 1];
	}

	for (i = ARRAY_SIZE - 1; i >= 0; i--) {
		B[CountArr[A[i]] - 1] = A[i];
		CountArr[A[i]]--;
	}

	for (i = 0; i < ARRAY_SIZE; i++) {
		A[i] = B[i];
	}

	return;
}

// Stable sort, Not Compare Sort