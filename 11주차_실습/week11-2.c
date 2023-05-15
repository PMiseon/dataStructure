#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {
	int elem;
	struct Node *prev, *next;
}Node;

typedef struct Deque {
	struct Node *front, *rear;
}Deque;

void init(Deque *deque) {
	deque->front = NULL;
	deque->rear = NULL;
}

Node *getNode(int e) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->elem = e;

	return newNode;
}

void add_front(Deque *deque, int x) {
	Node *newNode = getNode(x);

	//비어있는 경우 
	if (deque->front == NULL) {
		deque->front = newNode;
		deque->rear = newNode;
		return;
	}

	Node *p = deque->front; //원래 맨 앞 노드 
	newNode->next = p;
	p->prev = newNode;
	deque->front = newNode;

	return;
}


void add_rear(Deque *deque, int x) {
	Node *newNode = getNode(x);

	if (deque->rear == NULL) { //비어있는 경우 
		deque->front = newNode;
		deque->rear = newNode;
		return;
	}

	Node *p = deque->rear;  //원래 맨 뒤 노드 
	newNode->prev = p;
	p->next = newNode;
	deque->rear = newNode;

	return;
}

int delete_front(Deque *deque) {
	
	if (deque->front == NULL) { //emptyQueue
		printf("underflow\n");
		return -1;
	}

	Node *p = deque->front; //삭제예정노드 
	int answer = p->elem; //반환할 원소 

	deque->front = p->next;

	if (deque->front == NULL) { //원소가 1개였던 경우 -> 초기상태
		deque->rear = NULL;
	}
	else {
		deque->front->prev = NULL;
	}
	free(p);

	return answer; 
}

int delete_rear(Deque *deque) {
	if (deque->rear == NULL) {
		printf("underflow\n");
		return -1;
	}

	Node *p = deque->rear; //삭제예정노드 
	int answer = p->elem; //반환할 원소 

	deque->rear = p->prev;

	if (deque->rear == NULL) { //원소가 1개였던 경우 -> 초기상태
		deque->front = NULL;
	}
	else {
		deque->rear->next = NULL;
	}
	free(p);

	return answer;
}

void print(Deque* deque) {
	Node *p = deque->front;

	while (p != NULL) { //후단방향으로 차례대로 출력 
		printf("%d ", p->elem);
		p = p->next;
	}

	printf("\n");
	return;
}

int main() {
	Deque deque; 
	init(&deque);

	int n; //명령의 개수 n 
	scanf("%d", &n);

	int i;
	char cmd[10] = { 0 };
	int tmp; 

	for (i = 0; i < n; i++) {
		scanf("%s", cmd);
		getchar();

		if (strcmp(cmd, "AF") == 0) {
			scanf("%d", &tmp);
			getchar();
			add_front(&deque, tmp);
		}

		else if (strcmp(cmd, "AR") == 0) {
			scanf("%d", &tmp);
			getchar();
			add_rear(&deque, tmp);
		}

		else if (strcmp(cmd, "DF") == 0) {
			int answer = delete_front(&deque);
			if (answer == -1) {
				break;
			}
		}

		else if (strcmp(cmd, "DR") == 0) {
			int answer = delete_rear(&deque);
			if (answer == -1) {
				break;
			}
		}

		else if (strcmp(cmd, "P") == 0) {
			print(&deque);
		}
	}


	//freeMemory
	return 0;
}

/*
15
AF 10
AF 20
AF 30
AR 40
AR 50
P
DF
DF
DR
P
DF
DR
DR
*/
