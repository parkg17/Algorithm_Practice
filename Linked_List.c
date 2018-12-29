#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct node {   
	int data;
	struct node *next;           
} NODE;

typedef struct list {
	NODE *cur;
	NODE *head;
	NODE *tail;
} LinkedList;

// Function Prototype //
void Init_Node(LinkedList * L);
void Insert_Node(LinkedList * L, int data);
int Delete_Node(LinkedList * L, int data);
void Print_Node(LinkedList * L);

int main() {
	srand((unsigned)time(NULL));
	int temp, check;
	LinkedList * L = (LinkedList *)malloc(sizeof(LinkedList));
	Init_Node(L);

	for (int i = 0; i < 15; i++) {
		Insert_Node(L, i + 1);
		Print_Node(L);
	}
	printf("\n");

	for (int i = 0; i < 10; i++) {
		temp = rand() % 15;
		check = Delete_Node(L, temp);
		printf(" %d Deletion: ", temp);
		if (check == -1) {
			printf("Linked-List is empty\n");
		}
		else if (check == 0) {
			printf("No Data\n");
		} 
		else {
			printf("OK\n");
		}
		Print_Node(L);
	}


	return 0;
}

// 링크드 리스트 초기화 함수 //
void Init_Node(LinkedList * L) {
	L->cur = NULL;
	L->head = NULL;
	L->tail = NULL;
}


// 새 노드를 동적 할당하고 삽입하는 함수 //
void Insert_Node(LinkedList * L, int data) {
	NODE * newNode = malloc(sizeof(NODE));
	newNode->data = data;
	newNode->next = NULL;

	if (L->head == NULL) {
		L->head = newNode;
	}
	else {
		L->tail->next = newNode;
	}
	L->tail = newNode;
}

// 특정 data값을 갖는 노드를 삭제하는 함수. 에러가 발생할 경우 -1 반환 //
int Delete_Node(LinkedList * L, int data) {
	NODE * node = L->head;
	NODE * before_node = NULL;

	// 원소가 하나도 없을 경우 //
	if (node == NULL) return -1;

	// 일치할 경우, 삭제를 진행 //
	do {
		if (node->data == data) {
			
			if (before_node == NULL) { // 첫 번째 원소일 경우
				L->head = node->next;
				if(node->next == NULL) L->tail = NULL; // 원소가 1개일 경우
			}
			else if (node->next == NULL) { // 마지막 원소일 경우
				L->tail = before_node;
				before_node->next = NULL;
			}
			else { // 일반적인 경우
				before_node->next = node->next;
			}
			free(node);
			return 1; 
		}
		before_node = node;
		node = node->next;
	} while (node != NULL);

	// 해당 데이터를 갖는 노드를 찾지 못함 //
	return 0;
}

void Print_Node(LinkedList * L) {
	NODE * node = L->head;
	if (node == NULL) return;
	
	do {
		printf("%d ", node->data);
		node = node->next;
	} while (node != NULL);
	printf("\n");
	return;
}

