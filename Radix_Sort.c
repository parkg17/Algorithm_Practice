#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define VALUE_SIZE 1000
#define ARRAY_SIZE 100

void PrintArray(int A[]);
void Radix_Sort(int A[]);
int expon(int num);

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

	Radix_Sort(A);

	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", A[i]);
	}
	return;
}

void Radix_Sort(int A[]) {
	int digits = 0;
	int i, j, temp;
	int count[10] = {0};
	int B[ARRAY_SIZE] = { 0 };

	// Calculate the Digits of Maximum Number //
	temp = VALUE_SIZE - 1;
	while (temp != 0) {
		temp /= 10;
		digits += 1;
	}

	for (i = 1; i <= digits; i++) {
		for (j = 0; j < ARRAY_SIZE; j++) {
			count[(A[j] / expon(i)) % 10]++;
		}

		for (j = 1; j < 10; j++) {
			count[j] += count[j - 1];
		}

		// Since it starts at 1, Consider with "--" //
		for (j = ARRAY_SIZE - 1; j >= 0; j--) {
			B[--count[(A[j] / expon(i)) % 10]] = A[j];
		}

		// Swap and Reset //
		for (j = 0; j < ARRAY_SIZE; j++) {
			A[j] = B[j];
			B[j] = 0;
		}

		// Reset //
		for (j = 0; j < 10; j++) {
			count[j] = 0;
		}
	}

	return;
}

int expon(int num) {
	int result = 1;
	for (int i = 1; i < num; i++) {
		result = result * 10;
	}
	return result;
}

// Stable Sort, Time Complexity is O(dn) Where d is the number of digits