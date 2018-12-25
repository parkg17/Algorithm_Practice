#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define VALUE_SIZE 1000
#define ARRAY_SIZE 100

void PrintArray(int A[]);
void Selection_Sort(int A[]);

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

	Selection_Sort(A);

	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", A[i]);
	}
	return;
}

void Selection_Sort(int A[]) {
	int temp;
	int minimum_index;
	for (int i = 0; i < ARRAY_SIZE - 1; i++) {
		minimum_index = i;
		for (int j = i + 1; j < ARRAY_SIZE; j++) {
			if (A[j] < A[minimum_index]) {
				minimum_index = j;
			}
		}
		temp = A[minimum_index];
		A[minimum_index] = A[i];
		A[i] = temp;
	}
}
