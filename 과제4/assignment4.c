#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#pragma warning (disable : 4996)

#define NUM 1000000  

typedef struct Node {
	int data;
	struct Node *next; //next 
}Node;

typedef struct Queue {
	struct Node *front, *rear; 
	//부품큐들은 size 메소드를 지원하지 않는다. 
}Queue;

typedef struct Stack {
	Queue *Q1, *Q2;
	int size; //원소 개수 
}Stack;


void initStack(Stack *s) {
	//init Q1 
	s->Q1 = malloc(sizeof(Queue));
	s->Q1->front = NULL;
	s->Q1->rear = NULL;

	//init Q2
	s->Q2 = malloc(sizeof(Queue));
	s->Q2->front = NULL;
	s->Q2->rear = NULL;

	s->size = 0;
}

Node* getNode(int e) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	//newNode->prev = NULL;
	newNode->data = e;

	return newNode;
}

void EmptyStackException() {
	printf("Empty Stack Exception!! ");
}

//
//void checkQueue(Queue *Q) { //queue에 들어있는 data 확인용
//
//	Node *p = (Q->front);
//	if (p == NULL) {
//		printf("empty\n");
//		return;
//	}
//
//	while (p->next != NULL) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//
//	return; 
//}
//
//void checkStack(Stack *Stack) {
//	printf("first Queue\n");
//	checkQueue(Stack->Q1);
//
//	printf("\nsecond Queue\n");
//	checkQueue(Stack->Q2);
//
//	return;
//}

void enqueue(Queue *q, int e) {
	Node *p = getNode(e);

	if (q->front == NULL && q->rear == NULL) {

		//printf("firstNode\n");
		q->front = p;
		q->rear = p;
	}

	else {
		q->rear->next = p;
		q->rear = p;
	}

	return;
}

int dequeue(Queue *q) {

	if (q->front == NULL && q->rear == NULL) { //isEmpty
		EmptyStackException();
		return 0;
	}

	int e = q->front->data;
	Node *p = q->front;
	q->front = q->front->next;
	if (q->front == NULL) {
		q->rear = NULL;
	}
	free(p);
	return e;
	
}

int isEmpty(Stack *s) { //S
	//S에 대해 isEmpty() 호출(isEmpty)
	//비어있는지 반환 Empty, Nonempty
	
	if (s->Q1->front == NULL && s->Q2->front == NULL) {
		return 1;
	}

	else return 0;
}


void top(Stack *s) { //t
	//가장 최근에 삽입된 원소를 삭제하지 않고 반환
	//O(n)시간 소요 
	if (isEmpty(s)) {
		EmptyStackException();
		return;
	}

	while (s->Q1->front != s->Q1->rear) { //원소가 하나 남을 때까지 
		int tmp = dequeue(s->Q1);
		enqueue(s->Q2, tmp);
	}

	printf("%d ", s->Q1->front->data); //하나 남은 원소 == top 

	int tmp = dequeue(s->Q1);
	enqueue(s->Q2, tmp);
	//다시 Q2->Q1으로 이동

	while (s->Q2->front != NULL || s->Q2->rear != NULL) {
		int tmp = dequeue(s->Q2);
		enqueue(s->Q1, tmp);
	}
	//printf("%d",)
}

void push(Stack *s,int e) { //p
	//n1 n2 n3 ... : S에 대해 push(n1), push(n2), push(n3) ... 를 차례로 호출 (push)
	enqueue(s->Q1, e);
	s->size++;
}

void pushMillion(Stack *s) { //P
	//S에 대해 push(n)을 100만번 호출 - 여기서 n은 10~99 사이의 정수 난수 (pushMillion)
	int i;
	srand(time(NULL));

	for (i = 0; i < NUM; i++) {
		int random =  (rand() % (99 - 10 + 1)) + 10;
		//a~b 범위의 난수 만들기 -> rand()%(b-a+1)+a 
		//10 ~ 99 사이의 정수 난수 
		enqueue(s->Q1, random);
		s->size++;
	}

}

int pop(Stack *s) { //o
	//S에 대해 pop() 호출 (pop)

	if (isEmpty(s)) {
		EmptyStackException();
		return;
	}

	while (s->Q1->front != s->Q1->rear) { //원소가 하나 남을 때까지 
		int tmp = dequeue(s->Q1);
		enqueue(s->Q2, tmp);
	}

	printf("%d ", s->Q1->front->data); //하나 남은 원소 == top 

	int tmp = dequeue(s->Q1);
	//enqueue(s->Q2, tmp);
	//pop 했으므로 Q2로 이동할 필요 없다 

	while (s->Q2->front != NULL || s->Q2->rear != NULL) {
		int tmp = dequeue(s->Q2);
		enqueue(s->Q1, tmp);
	}

	s->size--;
}

void freeMemory(Stack *s) {
	Node *p, *nextNode; 
	//free Q1
	p = s->Q1->front;
	if (p != NULL) {
		while (p == s->Q1->rear) {
			nextNode = p->next;
			free(p);
			p = nextNode;
		}
	}
	//free Q2
	
	p = s->Q2->front;
	if (p != NULL) {
		while (p == s->Q2->rear) {
			nextNode = p->next;
			free(p);
			p = nextNode;
		}
	}
	//free stack
}

int main() {
	Stack *s = malloc(sizeof(Stack));
	initStack(s);

	char cmd;
	int tmp;

	//시간측정
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff ;
	float sumTime;


	while (1) {
		scanf("%c", &cmd);

		if (cmd == 'q') {
			freeMemory(s);
			free(s);
			//printf("프로그램 종료\n");
			break;
		}

		else if (cmd == 'S') { //isEmpty()
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			int ans = isEmpty(s); //isEmpty 실행 
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			
			if (ans == 0) { //false 
				printf("Nonempty ");
			}

			else {
				printf("Empty ");
			}

			printf("(%d), cputime = %2.12f\n", s->size ,((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
		}

		else if (cmd == 't') { //top()호출
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			top(s);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			printf("(%d), cputime = %2.12f\n", s->size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			//printf("pushMillion (%d), cputime = %2.12f\n", count, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
		}

		else if (cmd == 'p') { //push() 호출
			//수정 필요 
			
			int tmp;
			sumTime = 0;
			while (1) {
				scanf("%d", &tmp);
				char c = getchar(); //정수 입력뒤 '\n'가 바로 입력되면 break

				QueryPerformanceFrequency(&ticksPerSec);
				QueryPerformanceCounter(&start);
				push(s, tmp);
				QueryPerformanceCounter(&end);
				diff.QuadPart = end.QuadPart - start.QuadPart;
				sumTime += diff.QuadPart/ (double)ticksPerSec.QuadPart;


				if (c == '\n') {
					break;
				}
			}
			printf("OK (%d),cputime = %2.12f\n", s->size, sumTime);
		}

		else if (cmd == 'P') { //pushMillion
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			pushMillion(s);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			
			printf("OK (%d), cputime = %2.12f\n", s->size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

		}

		else if (cmd == 'o') { //pop
			int flag = 0;

			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			pop(s);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			printf("(%d), cputime = %2.12f\n", s->size, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

		}

	}

}
