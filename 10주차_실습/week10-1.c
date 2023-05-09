#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)


typedef struct Node {
	char elem;
	int count; //header에서만 사용 
	int flag; //단항연산자 판별용
	struct Node *next;
}Node;

//연산자, 우선순위
char ope[12] = { '!','#','@','*','/','+','-','>','<','&','|' };
int opePre[12] = { 6,6,6,5,5,4,4,3,3,2,1 };


char pop(Node *stack) {
	stack->count = stack->count - 1;

	Node *p = stack->next; //지워야하는 노드 
	char r = (stack->next)->elem;
	stack->next = p->next;
	free(p);
	return r;
}

void push(Node *stack, char elem) {
	stack->count = stack->count + 1;
	Node* newNode = malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->elem = elem;

	newNode->next = stack->next;
	stack->next = newNode;
}

char top(Node *stack) {
	return (stack->next)->elem;
}

int preference(char o) { //우선순위 
	int i;
	for (i = 0; i < 11; i++) {
		if (ope[i] == o) {
			return opePre[i];
		}
	}

	return 0;
}

void freeMemory(Node *stack) {
	Node *p = stack->next;
	Node *nextNode;

	while (p != NULL) {
		nextNode = p->next;
		free(p);
		p = nextNode;
	}

	//return;
}

void initStack(Node *stack) {
	stack->count = 0;
	stack->next = NULL;
	return;
}

int isOperand(char s) {
	if ((s >= 'A') && (s <= 'Z'))
		return 1;
	else
		return 0;
}

void write(char c) {
	if (c == '|') {
		printf("||");
	}

	else if (c == '&') {
		printf("&&");
	}

	else if (c == '#') {
		printf("+");
	}

	else if (c == '@') {
		printf("-");
	}
	else printf("%c", c);
}

int main() {
	Node *stack = malloc(sizeof(Node)); //header
	stack->next = NULL;
	//initStack(stack);

	int n;
	scanf("%d", &n);
	getchar();

	int i, j;
	for (i = 0; i < n; i++) {
		initStack(stack); //사용할 스택 초기화 

		char input[100] = { 0 };
		gets(input);

		int len = strlen(input);
		for (j = 0; j < len; j++) {

			if ((input[j] == '|') || (input[j] == '&')) {
				j++;
			}

			if (input[j] == '+' || input[j] == '-') {
				if (j == 0) {
					if (input[j] == '+') {
						input[j] = '#';
					}
					else {
						input[j] = '@';
					}
				}
				else if ((input[j - 1] != ')') && (isOperand(input[j-1]) == 0)) {
					if (input[j] == '+') {
						input[j] = '#';
					}
					else {
						input[j] = '@';
					}
				}
			}


			if (isOperand(input[j])) {
				write(input[j]);
			}

			else if (input[j] == '(') {
				push(stack, input[j]);
			}

			else if (input[j] == ')') {
				while (top(stack) != '(') {

					write(pop(stack));
				}
				pop(stack);
			}

			else {

				while ((stack->count != 0) && (preference(input[j]) <= preference(top(stack)))) {

					write(pop(stack));

				}
				push(stack, input[j]);
			}
		}

		while (stack->count != 0) {
			write(pop(stack));
		}
		printf("\n");
		freeMemory(stack); //사용한 스택 동적할당해제 
	}

	free(stack); //헤더 동적할당 해제 



}
