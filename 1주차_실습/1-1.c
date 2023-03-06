#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int sum(int n) {
	int sum = 0;
	int i;
	for (i = 1; i < n + 1; i++) {
		sum += i;
	}

	return sum;
}

int main() {
	int x;
	scanf("%d", &x);

	int i,k = 0;
	for (i = 1; i < x + 1; i++) {
		k += sum(i);
	}

	printf("%d", k);


}
