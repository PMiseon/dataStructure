#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void fullStackException() {
	printf("Stack FULL\n");
	return;
}

void initStack(char *stack, int *t, int N) {
	stack = (char*)malloc(sizeof(char)*(N + 1));
	//*stack[0] = 'a'; //check
	*t = -1;
	return; 
}

void push(char *stack, int *t, int N, char e) {
	if (*t == N - 1) {
		fullStackException();
		return;
	}

	*t = (*t) + 1;
	stack[*t] = e;
	//printf("push %d\n",*t);
	return;
}

void emptyStackException() {
	printf("Stack Empty\n");
	return;
}

void pop(char *stack, int *t) {
	if (*t == -1) {
		emptyStackException();
		return;
	}

	*t = *t - 1;
	//return stack[*t + 1];
}

void duplicate(char *stack, int *t, int N) {
	/* stack의 top에 있는 원소를 pop해서 두 번 push한다. 
	stack이 이미 꽉 차 있으면 “Stack FULL”을 출력한다. */
	if (*t == N - 1) {
		fullStackException();
		return;
	}

	char c = stack[*t];
	pop(stack, t);
	//printf("dup : %c\n", c);
	push(stack, t, N, c);
	push(stack, t, N, c);
	return;
}


void peek(char *stack, int *t) {
	/*stack의 top에 있는 원소를 화면에 출력한다. 
	stack은 변화하지 않는다. stack이 비어 있으면 “Stack Empty”를 출력한다.*/
	if (*t == -1) {
		emptyStackException();
		return;
	}
	printf("%c\n", stack[*t]);
	//return stack[*t];
}

void upRotate(char *stack, int *t, int n) {
	//char tmp = peek(stack, t); //top
	if (n - 1 > *t)
		return;
	char tmp = stack[*t];
	int i;
	for (i = *t - 1; i > *t - n; i--) {
		stack[i + 1] = stack[i];
	}
	stack[*t - n + 1] = tmp;
}

void downRotate(char *stack, int *t, int n) {
	char tmp = stack[*t - n + 1];
	if (n - 1 > *t)
		return;
	//printf("check : %c\n", tmp);
	int i;
	for (i = *t - n + 2; i < *t + 1; i++) {
		stack[i - 1] = stack[i];
	}
	stack[*t] = tmp;
}

void check(char *stack, int *t) {
	int i;
	for (i = 0; i <= *t; i++) {
		printf("%c", stack[i]);
	}
	printf("  check\n");
}

void print(char *stack, int *t) {
	int i;
	for (i = *t; i > -1; i--) {
		printf("%c", stack[i]);
	}
	printf("\n");
	return; 
}

int main() {
	char *stack = NULL;
	int N, t;
	scanf("%d", &N);
	initStack(&stack, &t,N);


	int k, i; 
	scanf("%d", &k);
	getchar();
	
	for (i = 0; i < k; i++) {
		char cmd[10] = { 0 };
		char tmp;
		int n;
		scanf("%s", cmd);
		getchar();

		if (strcmp(cmd, "PUSH") == 0) {
			scanf("%c", &tmp);
			push(&stack, &t, N, tmp);
		}

		else if (strcmp(cmd, "POP") == 0) {
			pop(&stack, &t);
		}

		else if (strcmp(cmd, "PRINT") == 0) {
			print(&stack, &t);
		}

		else if (strcmp(cmd, "UpR") == 0) {
			scanf("%d", &n);
			upRotate(&stack, &t, n);
		}

		else if (strcmp(cmd, "DownR") == 0) {
			scanf("%d", &n);
			downRotate(&stack, &t, n);
		}

		else if (strcmp(cmd, "PEEK") == 0) {
			peek(&stack, &t);
		}

		else if (strcmp(cmd, "DUP") == 0) {
			duplicate(&stack, &t, N);
		}
	}

}
