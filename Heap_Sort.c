#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define VALUE_SIZE 1000
#define ARRAY_SIZE 100

void PrintArray(int A[]);
void swap(int * num1, int * num2);
void Build_Max_Heap(int A[]);
void Max_Heapify(int A[], int index);
void Heap_Sort(int A[]);
//////////////////////////////////////////////
int Heap_Maxinum(int A[]);
int Heap_Extract_Max(int A[]);
void Heap_Increase_Key(int A[], int index, int key);
void Max_Heap_Insert(int A[], int key);

int main() {

	srand((unsigned)time(NULL));
	int CheckDuplicate[VALUE_SIZE] = { 0 };
	int A[1000];
	int temp;

	/* 1. Unaligned random value */
	// Save Array Size in A[0]. So, start loop with i = 1 //
	A[0] = ARRAY_SIZE - 1;

	for (int i = 1; i < ARRAY_SIZE; ) {
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

	Heap_Sort(A);

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

void Build_Max_Heap(int A[]) {
	// Because half of the tree is a leaf node, only the	//
	// remaining half iternal nodes need to be checked.		//

	for (int i = (A[0] / 2); i > 0; i--) {
		Max_Heapify(A, i);
	}
}

void Max_Heapify(int A[], int index) {
	int left = 2 * index;
	int right = 2 * index + 1;
	int largest = index;

	// Check Left Node //
	if (left < A[0] && A[left] > A[index]) {
		largest = left;
	}

	// Check Right Node //
	if (right < A[0] && A[right] > A[largest]) {
		largest = right;
	}

	// Maintain Heapify //
	if (largest != index) {
		swap(&A[index], &A[largest]);
		Max_Heapify(A, largest);
	}
	return;
}

void Heap_Sort(int A[]) {
	Build_Max_Heap(A);

	for (int i = A[0]; i > 1; i--) {
		swap(&A[1], &A[i]);
		A[0]--;
		Max_Heapify(A, 1);
	}

	return;
}

//////////////////////////////////////////////

// Priority Queue //

int Heap_Maxinum(int A[]) {
	return A[1];
}

int Heap_Extract_Max(int A[]) { // O(lgn)
	if (A[0] < 1) {
		printf("Insufficient Head Size\n");
		exit(1);
	}
	int max = A[1];
	A[1] = A[A[0]];
	A[0]--;
	Max_Heapify(A, 1);
	return max;
}

void Heap_Increase_Key(int A[], int index, int key) { // O(lgn)
	if (key < A[index]) {
		printf("new key value is less than original key value\n");
		exit(1);
	}
	A[index] = key;
	while (index > 1 && A[index / 2] < A[index]) {
		swap(&A[index], &A[index / 2]);
		index = index / 2;
	}
	return;
}

void Max_Heap_Insert(int A[], int key) {
	A[0]++;
	A[A[0]] = -2147483648; // int MINIMUM value
	Heap_Increase_Key(A, A[0], key);
	return;
}