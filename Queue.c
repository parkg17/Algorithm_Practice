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

typedef struct queue {
    NODE * front;
    NODE * rear;
} Queue;

// Function Prototype //
void QueueInit(Queue * queue);
int isEmpty(Queue * queue);
void Enqueue(Queue * queue, int data);
int Dequeue(Queue * queue);
int Peek(Queue * queue);

int main() {

    Queue queue;
    QueueInit(&queue);

    for(int i = 0; i < 5; i++) {
        Enqueue(&queue, i + 1);
    }

    while(!isEmpty(&queue)) {
        printf("%d ", Dequeue(&queue));
    }

    return 0;
}

void QueueInit(Queue * queue) {
    queue->front = NULL;
    queue->rear= NULL;
}

int isEmpty(Queue * queue) {
    if(queue->front== NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue * queue, int data) {
    NODE * newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    return;
}

int Dequeue(Queue * queue) {
    int result;
    NODE * temp;

    if(isEmpty(queue)) {
        printf("Queue Underflow\n");
        exit(-1);
    }

    temp = queue->front;
    result = temp->data;
    queue->front = queue->front->next;

    free(temp);
    return result;
}

int Peek(Queue * queue) {
    if(isEmpty(queue)) {
        printf("Queue Underflow\n");
        exit(-1);
    }

    return queue->front->data;
}