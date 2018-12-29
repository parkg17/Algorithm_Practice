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

// ��ũ�� ����Ʈ �ʱ�ȭ �Լ� //
void Init_Node(LinkedList * L) {
	L->cur = NULL;
	L->head = NULL;
	L->tail = NULL;
}


// �� ��带 ���� �Ҵ��ϰ� �����ϴ� �Լ� //
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

// Ư�� data���� ���� ��带 �����ϴ� �Լ�. ������ �߻��� ��� -1 ��ȯ //
int Delete_Node(LinkedList * L, int data) {
	NODE * node = L->head;
	NODE * before_node = NULL;

	// ���Ұ� �ϳ��� ���� ��� //
	if (node == NULL) return -1;

	// ��ġ�� ���, ������ ���� //
	do {
		if (node->data == data) {
			
			if (before_node == NULL) { // ù ��° ������ ���
				L->head = node->next;
				if(node->next == NULL) L->tail = NULL; // ���Ұ� 1���� ���
			}
			else if (node->next == NULL) { // ������ ������ ���
				L->tail = before_node;
				before_node->next = NULL;
			}
			else { // �Ϲ����� ���
				before_node->next = node->next;
			}
			free(node);
			return 1; 
		}
		before_node = node;
		node = node->next;
	} while (node != NULL);

	// �ش� �����͸� ���� ��带 ã�� ���� //
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

