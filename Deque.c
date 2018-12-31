#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
	int data;
	struct node * next;
	struct node * prev;
} NODE;

typedef struct deque {
	NODE * head;
	NODE * tail;
} Deque;

// Function Prototype //
void DequeInit(Deque * deque);
int isEmpty(Deque * deque);
void DequeAddFirst(Deque * deque, int data);
void DequeAddLast(Deque * deque, int data);
int DequeRemoveFirst(Deque * deque);
int DequeRemoveLast(Deque * deque);
int DequeGetFirst(Deque * deque);
int DequeGetLast(Deque * deque);

int main() {

	Deque deque_1;
	Deque deque_2;
	DequeInit(&deque_1);
	DequeInit(&deque_2);

	for (int i = 0; i < 5; i++) {
		DequeAddFirst(&deque_1, i + 1);
		DequeAddFirst(&deque_2, i + 1);
	}

	while (!isEmpty(&deque_1)) {
		printf("%d ", DequeRemoveFirst(&deque_1));
	}
	printf("\n");
	while (!isEmpty(&deque_2)) {
		printf("%d ", DequeRemoveLast(&deque_2));
	}

	return 0;
}

void DequeInit(Deque * deque) {
	deque->head = NULL;
	deque->tail = NULL;
}

int isEmpty(Deque * deque) {
	if (deque->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void DequeAddFirst(Deque * deque, int data) {
	NODE * newNode = (NODE *)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->next = deque->head;
	newNode->prev = NULL;

	if (isEmpty(deque)) {
		deque->tail = newNode;
	}
	else {
		deque->head->prev = newNode;
	}
	deque->head = newNode;

	return;
}

void DequeAddLast(Deque * deque, int data) {
	NODE * newNode = (NODE *)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = deque->tail;

	if (isEmpty(deque)) {
		deque->head = newNode;
	}
	else {
		deque->tail->next = newNode;
	}
	deque->tail = newNode;

	return;
}

int DequeRemoveFirst(Deque * deque) {
	int result;
	NODE * temp = deque->head;

	if (isEmpty(deque)) {
		printf("Deque Underflow!\n");
		exit(-1);
	}

	result = temp->data;
	deque->head = temp->next;
	free(temp);
	if (deque->head == NULL) {
		deque->tail = NULL;
	} 
	else {
		deque->head->prev = NULL;
	}

	return result;
}

int DequeRemoveLast(Deque * deque) {
	int result;
	NODE * temp = deque->tail;

	if (isEmpty(deque)) {
		printf("Deque Underflow!\n");
		exit(-1);
	}

	result = temp->data;
	deque->tail= temp->prev;
	free(temp);
	if (deque->tail == NULL) {
		deque->head = NULL;
	}
	else {
		deque->tail->next = NULL;
	}

	return result;
}


int DequeGetFirst(Deque * deque) {
	if (isEmpty(deque)) {
		printf("Queue Underflow\n");
		exit(-1);
	}

	return deque->head->data;
}

int DequeGetLast(Deque * deque) {
	if (isEmpty(deque)) {
		printf("Queue Underflow\n");
		exit(-1);
	}

	return deque->tail->data;
}