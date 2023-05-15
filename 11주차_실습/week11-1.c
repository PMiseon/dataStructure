#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Queue {
	int *q; 
	int front, rear;
	int N; //queueSize 
}Queue;

void init(Queue *Q, int size) {
	Q->N = size;

	//Q->front = 0;
	//Q->rear = Q->N - 1;
	Q->front = 1;
	Q->rear = 0;

	Q->q = (int*)malloc(sizeof(int)*(Q->N)); //큐 사이즈만큼 동적할당 

	//배열의 초기값 0
	int i;
	for (i = 0; i < Q->N; i++) {
		Q->q[i] = 0;
	}
	return;
}

int isEmpty(Queue *Q) {
	return (Q->rear + 1) % Q->N == Q->front;
}

int size(Queue *Q) {
	return (Q->N - Q->front + Q->rear + 1) % Q->N;
}

int isFull(Queue *Q) {
	return (Q->rear + 2) % Q->N == Q->front;
}

void print(Queue *Q) {
	int i;
	for (i = 0; i < Q->N; i++) {
		printf(" %d", Q->q[i]);
	}
	printf("\n");
	return;
}

int insert(Queue *Q, int e) { //enqueue
	if (isFull(Q)) {
		//fullQueueException;
		printf("overflow ");
		print(Q);
		return -1; 
	}

	Q->rear = (Q->rear + 1) % Q->N;
	Q->q[Q->rear] = e;
	return 1;
}

int delete(Queue *Q) { //dequeue
	if (isEmpty(Q)) {
		//emptyQueueException
		printf("underflow\n");
		return -1;
	}

	int e = Q->q[Q->front];
	Q->q[Q->front] = 0;
	Q->front = (Q->front + 1) % Q->N;
	return e;
}

void freeMemory(Queue *Q) {
	free(Q->q);
}

int main() {


	int q; //queue size
	scanf("%d", &q);

	Queue Q;
	init(&Q, q);

	int n;
	scanf("%d", &n); //명령의 개수 
	getchar();


	int i;
	char cmd; 
	for (i = 0; i < n; i++) {
		scanf("%c", &cmd);
		getchar();

		if (cmd == 'I') {
			int tmp;
			int k = 0;
			scanf("%d", &tmp);
			getchar();
			k = insert(&Q, tmp);
			if (k == -1) {
				break;
			}
		}

		else if (cmd == 'D') {
			int k = 0;
			k = delete(&Q);
			if (k == -1) {
				break;
			}
		}

		else if (cmd == 'P') {
			print(&Q);
		}

	}

	freeMemory(&Q);
}
