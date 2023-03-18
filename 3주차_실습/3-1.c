#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int reAdd(int n) {
	if (n == 1) {
		return 1;
	}

	return n + reAdd(n - 1);
}

int main() {
	int n;
	scanf("%d", &n);

	printf("%d", reAdd(n));
}
