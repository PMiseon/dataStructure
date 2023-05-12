#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#pragma warning (disable : 4996)

#define NUM 1000000  

typedef struct Node {
	int elem;
	int min; //입력했을때 min값 
	struct Node *next; //단일연결리스트 이용하기 
}Node;



void push(Node *stack, int *min, int *count, int e) {
	*count = *count + 1; //count++
	//printf("count : %d\n", *count);

	if (stack->next == NULL) {
		*min = e; //첫번째 입력 elem = 첫번째 min 
	}

	if (*min > e) { //min인지 확인 -> 기록 
		*min = e;
	}

	Node *newNode = (malloc(sizeof(Node)));
	newNode->elem = e;
	newNode->min = *min;
	newNode->next = NULL;

	newNode->next = stack->next;
	stack->next = newNode;

	return;
}


void pushMillion(Node *stack, int *min, int* count) {
	//난수발생함수 -> 1000~9999 사이의 난수 정수 스택에 삽입하여 반환 후 호출 
	int i;
	int randNum; // 난수 
	srand(time(NULL));

	for (i = 0; i < NUM; i++) {
		//randNum = //난수발생시키기 
		randNum = (rand() % (9999 - 1000 + 1)) + 1000;
		//a~b 범위의 난수 만들기 -> rand()%(b-a+1)+a

		//push
		*count = *count + 1; //count++

		if (stack->next == NULL) {
			*min = randNum; //첫번째 입력 elem = 첫번째 min 
		}

		if (*min > randNum) { //min인지 확인 -> 기록 
			*min = randNum;
		}

		Node *newNode = (malloc(sizeof(Node)));
		newNode->elem = randNum;
		newNode->min = *min;
		newNode->next = NULL;

		newNode->next = stack->next;
		stack->next = newNode;
	}
	return;
}

int pop(Node *stack, int *count, int *flag) {

	if (*count <= 0) {
		printf("EmptyStackException\n");
		*flag = 1;
		return NULL; //empty Stack Exception
	}

	*count = *count - 1; //count--;

	Node *p = stack->next; //pop->delete 
	int elem = p->elem; //출력용 
	stack->next = p->next;
	free(p); //동적할당해제 
	return elem; //pop() 한 top의 elem 
}

void popMillion(Node *stack, int *count) {
	int i;
	for (i = 0; i < NUM; i++) {
		//pop(stack, count);
		if (*count <= 0) { //NUM개 이하인 경우에는 예외 처리 
			//popMillion이 남은 스택이 없어질 때까지 실행은 되지만, emptyStackException이 출력된다. 

			printf("EmptyStackException\n");
			break; //emptyStackException
		}
		*count = *count - 1; //count--;

		Node *p = stack->next; //pop->delete 
		stack->next = p->next;
		free(p); //동적할당해제 
	}

	return;
}

int findMin(Node *stack, int *flag, int *count) {

	if (*count <= 0) { //스택에 원소가 없는 경우 
		*flag = 1;
		printf("EmptyStackException\n");
		return NULL;
	}

	return (stack->next)->min; //pop()->min 값 
}

void check(Node *stack) { //입력확인용 
	Node *p = stack->next;
	while (p != NULL) {
		printf(" %d,%d->", p->min, p->elem);
		p = p->next;
	}
	printf("\n");
	return;
}

void freeMemory(Node *stack) { //동적할당 해제하기 
	Node *p = stack->next;
	Node *nextNode;

	while (p != NULL) {
		nextNode = p->next;
		free(p);
		p = nextNode;
	}
}

int main() {

	Node *stack = malloc(sizeof(Node)); //header
	stack->next = NULL;

	char cmd;
	int tmp;
	int min;
	int count = 0;
	int answer = 0; //결과 

	//시간측정
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;


	while (1) {
		scanf("%c", &cmd);

		if (cmd == 'q') {
			//freeMemory; 
			printf("(프로그램 종료)\n");
			freeMemory(stack); //모든 원소 동적할당 해제 
			free(stack); //header 동적할당 해제 
			break;
		}

		else if (cmd == 'p') { //push 
			scanf("%d", &tmp); //원소 e
			
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			push(stack, &min, &count, tmp); //push 
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			printf("push %d (%d), cputime = %2.12f\n", tmp, count, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
		}

		else if (cmd == 'P') { //pushMillion
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			pushMillion(stack, &min, &count); //pushMillion
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			printf("pushMillion (%d), cputime = %2.12f\n", count, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
		}

		else if (cmd == 'o') { //pop
			int flag = 0;

			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			answer = pop(stack, &count, &flag);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			if (flag != 1) { //emptyStackException이 발생하지 않은 경우에만 출력한다 
				printf("pop %d (%d),cputime = %2.12f\n", answer, count, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			}
		}

		else if (cmd == 'O') { //popMillion
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			popMillion(stack, &count);//popMillion
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("popMillion (%d), cputime = %2.12f\n", count, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

		}

		else if (cmd == 'f') { //findMin
			int flag = 0;

			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			answer = findMin(stack,&flag, &count);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			if (flag != 1) {
				printf("min %d (%d), cputime = %2.12f\n", answer, count, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			}
		}

		//else if (cmd == 'c') { //check
		//	check(stack);
		//}

		//getchar();
	}
}
