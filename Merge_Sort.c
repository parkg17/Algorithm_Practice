#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define VALUE_SIZE 1000
#define ARRAY_SIZE 100

void PrintArray(int A[]);
void Merge_Sort(int A[], int start, int last);
void Merge(int A[], int start, int mid, int last);

// Merge Sort is not in-place sorting						//
// However, if we implement a Merge Sort as a linked list,	//
// We can implement a Merge Sort as in-place sorting		//

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

	Merge_Sort(A, 0, ARRAY_SIZE - 1);

	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", A[i]);
	}
	return;
}

void Merge_Sort(int A[], int start, int last) {
	if (start < last) {
		int mid = (start + last) / 2;
		Merge_Sort(A, start, mid);
		Merge_Sort(A, mid + 1, last);
		Merge(A, start, mid, last);
	}
}

void Merge(int A[], int start, int mid, int last) {
	int i, j, k;
	int temp[ARRAY_SIZE];
	i = start;
	j = mid + 1;
	k = start;

	while (i <= mid && j <= last) {
		if (A[i] <= A[j])
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];
	}
	while (i <= mid) { temp[k++] = A[i++]; }
	while (j <= last) { temp[k++] = A[j++]; }
	for (int index = start; index <= last; index++) {
		A[index] = temp[index];
	}
}