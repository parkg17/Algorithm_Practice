#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define VALUE_SIZE 1000
#define ARRAY_SIZE 100

typedef struct node {
	int data;
	struct node * next;
} NODE;

NODE * Add_Node(int data);
void PrintArray(NODE * head);
void Merge_Sort(NODE **L, int size);
NODE* merge(NODE *L, NODE *R);

int main() {

	srand((unsigned)time(NULL));
	int CheckDuplicate[VALUE_SIZE] = { 0 };
	int temp;

	// Dynamic Allocation //
	NODE * head;
	head = (NODE *)malloc(sizeof(NODE));
	head->next = NULL;
	NODE * temp_node = head;

	/* 1. Unaligned random value */
	for (int i = 0; i < ARRAY_SIZE; ) {
		temp = rand() % 1000;
		if (CheckDuplicate[temp] == 0) {
			CheckDuplicate[temp] = 1;
			temp_node->next = Add_Node(temp);
			temp_node = temp_node->next;
			i++;
		}
	}

	PrintArray(head);

	return 0;
}

NODE * Add_Node(int data) {
	NODE *new_node = (NODE *)malloc(sizeof(NODE));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void PrintArray(NODE * head) {
	NODE * temp = head->next;

	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n\n");

	Merge_Sort(&head->next, ARRAY_SIZE);
	temp = head->next;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	return;
}

void Merge_Sort(NODE **node, int size) {

	NODE * Sentinel = *node; // 경계 노드
	NODE *L1 = *node;
	NODE *L2 = NULL;
	int L1_SIZE = size / 2;
	int L2_SIZE = size - (size / 2);

	// Divide if there are more than two //
	// elements and the value is valid.	 //
	if (size > 1 && *node != NULL) {

		// Partition //
		for (int i = 0; i < L1_SIZE - 1; i++) {
			Sentinel = Sentinel->next;
		}
		L2 = Sentinel->next;
		Sentinel->next = NULL;

		Merge_Sort(&L1, L1_SIZE);
		Merge_Sort(&L2, L2_SIZE);

		*node = merge(L1, L2);
	}
	return;
}

NODE* merge(NODE *L, NODE *R) {

	NODE *result = NULL;

	if (L == NULL) 
		return R;
	else if (R == NULL) 
		return L;

	if (L->data < R->data) {
		result = L;
		result->next = merge(L->next, R);
	}
	else {
		result = R;
		result->next = merge(L, R->next);
	}

	return result;
}