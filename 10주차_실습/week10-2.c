#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {
	int elem;
	int count; 
	struct Node *next;
}Node;

int isOperand(char c) {
	if ((c >= '0') && (c <= '9')) {
		return 1;
	}

	else return 0;
}


int pop(Node *stack) {
	stack->count = stack->count - 1;

	Node *p = stack->next; //지워야하는 노드 
	int r = (stack->next)->elem;
	stack->next = p->next;
	free(p);
	return r;
}

void push(Node *stack, int elem) {
	stack->count = stack->count + 1;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->elem = elem;

	newNode->next = stack->next;
	stack->next = newNode;
}

int top(Node *stack) {
	return (stack->next)->elem;
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

int doOperator(char c, int x, int y) {
	if (c == '+')
		return x + y;
	else if (c == '-')
		return x - y;
	else if (c == '*')
		return x * y;
	else if (c == '/')
		return x / y;
}


int main() {

	int n;
	scanf("%d", &n);
	getchar();

	Node *stack = (Node*)malloc(sizeof(Node));
	stack->next = NULL;
	int i,j;

	for (i = 0; i < n; i++) {
		char input[100] = { 0 };
		scanf("%s", input);
		int len = strlen(input);

		for (j = 0; j < len; j++) {
			char s = input[j];

			if (isOperand(s)) {
				push(stack, s - '0');
			}

			else {
				int a = pop(stack);
				int b = pop(stack);
				int tmp = doOperator(s, b, a);
				push(stack, tmp);

			}
		}

		printf("%d\n", pop(stack));

	}

}
