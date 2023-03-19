#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int minMax(int *a, int *b) {
	int tmp; 
	if (*a < *b) {
		tmp = *(a);
		*(a) = *(b);
		*(b) = tmp;
	}
}

int gcd(int a, int b) {

	minMax(&a, &b);

	if (b == 0) {
		printf("%d\n", a);
		return a;
	}

	gcd(b, a%b);
}

int main() {

	int a, b;
	scanf("%d %d", &a, &b);

	gcd(a, b);
}
