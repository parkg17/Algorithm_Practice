#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define VALUE_SIZE 1000
#define ARRAY_SIZE 100

void PrintArray(int A[]);
void Bubble_Sort(int A[]);
void Improved_Bubble_Sort(int A[]);

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

	Bubble_Sort(A);

	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", A[i]);
	}
	return;
}

void Bubble_Sort(int A[]) {
	int temp;
	for (int i = 0; i < ARRAY_SIZE - 1; i++) {
		for (int j = ARRAY_SIZE - 1; j >= i + 1; j--) {
			if (A[j] < A[j - 1]) {
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
			}
		}
	}
}

void Improved_Bubble_Sort(int A[]) {
	int temp;
	int flag;
	for (int i = 0; i < ARRAY_SIZE - 1; i++) {
		flag = 0;
		for (int j = ARRAY_SIZE - 1; j >= i + 1; j--) {
			if (A[j] < A[j - 1]) {
				flag = 1;
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
			}
		}
		if (flag == 0) return;
	}
	return;
}