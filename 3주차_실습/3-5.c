#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)


void rHanoi(int n, char from, char aux, char to) {
	if (n == 1) {
		printf("%c %c\n", from, to);
		return;
	}

	rHanoi(n - 1, from, to, aux);
	printf("%c %c\n", from, to);
	rHanoi(n - 1, aux, from, to);
	return;
}

void hanoi(int n) {
	char A = 'A', B = 'B', C = 'C';
	rHanoi(n, A, B, C);
	return;
}

int main() {
	int n;
	scanf("%d", &n);

	hanoi(n);
}
