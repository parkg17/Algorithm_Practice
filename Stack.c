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
} NODE;

typedef struct stack {
    NODE * head;
} Stack;

// Function Prototype //
void StackInit(Stack * stack);
int isEmpty(Stack * stack);
void Push(Stack * stack, int data);
int Pop(Stack * stack);
int Peek(Stack * stack);

int main() {

    Stack stack;
    StackInit(&stack);

    for(int i = 0; i < 5; i++) {
        Push(&stack, i + 1);
    }

    while(!isEmpty(&stack)) {
        printf("%d ", Pop(&stack));
    }

    return 0;
}

void StackInit(Stack * stack) {
    stack->head = NULL;
}

int isEmpty(Stack * stack) {
    if(stack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void Push(Stack * stack, int data) {
    NODE * newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = stack->head;
    stack->head = newNode;
    return;
}

int Pop(Stack * stack) {
    int result;
    NODE * temp;

    if(isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(-1);
    }

    result = stack->head->data;
    temp = stack->head;

    stack->head = stack->head->next;
    free(temp);
    return result;
}

int Peek(Stack * stack) {
    if(isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(-1);
    }

    return stack->head->data;
}