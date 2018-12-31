#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct node {
    int data;
    struct node * next;
} NODE;

typedef struct cll {
    NODE * tail;
    NODE * cur;
    NODE * before;
    int data_number;
} CLL;

// Function Prototype //
void ListInit(CLL * L);



int main() {
	srand((unsigned)time(NULL));

    CLL * L = (CLL *)malloc(sizeof(CLL));
    ListInit(L);
	





	return 0;
}

void ListInit(CLL * L) {
    L->tail = NULL;
    L->cur = NULL;
    L->before = NULL;
    L->data_number = 0;
}

// Tail Insertion Function //
void ListInsertTail(CLL * L, int data) {
    NODE * newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;

    if(L->tail == NULL) {
        L->tail = newNode;
        newNode->next = newNode;
    }
    else {
        newNode->next = L->tail->next;
        L->tail->next = newNode;
        L->tail = newNode;  // The Only Difference
    }
    L->data_number++;
}

// Head Insertion Function //
void ListInsertHead(CLL * L, int data) {
    NODE * newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;

    if(L->tail == NULL) {
        L->tail = newNode;
        newNode->next = newNode;
    }
    else {
        newNode->next = L->tail->next;
        L->tail->next = newNode;
    }
    L->data_number++;
}