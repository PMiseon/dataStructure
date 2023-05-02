#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

char pop(char stack[], int *t) {
	if (*t == -1) {
		return '0';
	}
	*t = *t - 1;

	return stack[*t + 1];
}

void push(char stack[], int *t, char e) {
	*t = *t + 1;
	stack[*t] = e;
	return;
}

void print(char stack[], int *t) {
	int i;
	for (i = *t; i > -1; i--) {
		printf("%c", stack[i]);
	}
	printf("\n");
}


int main() {
	char s[1001] = { 0 };

	//initStack 
	char stack[500] = { 0 }; 
	int t = -1;

	gets(s);
	int len = strlen(s);

	int i;
	char tmp = NULL;
	int count = 0;
	int flag = 0;
	// flag == 0 -> OK_count, flag == 1-> Wrong_count

	for (i = 0; i < len; i++) {

		if (s[i] == '{') {
			count++;
			push(&stack, &t, '{');
		}
		else if (s[i] == '(') {
			count++;
			push(&stack, &t, '(');
		}
		else if (s[i] == '[') {
			count++;
			push(&stack, &t, '[');
		}


		else if (s[i] == '}') {
			count++;
			tmp = pop(&stack, &t);
			if (tmp != '{') {
				flag = 1;
			}
		}
		else if (s[i] == ')') {
			count++;
			tmp = pop(&stack, &t);
			if (tmp != '(')
				flag = 1;
		}
		else if (s[i] == ']') {
			count++;
			tmp = pop(&stack, &t);
			if (tmp != '[')
				flag = 1;
		}
	}

	if (t != -1) { //남은 stack이 있는 경우 
		printf("Wrong_%d\n", count);
		return 0;
	}

	if (flag == 0) {
		printf("OK_%d\n", count);
	}

	else if (flag == 1) {
		printf("Wrong_%d\n", count);
	}
}
