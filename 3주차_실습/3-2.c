#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void reNum(int n) {

	if (n == 0) {
		return;
	}

	reNum(n / 10);

	printf("%d\n", n % 10);
}


int main() {
	int n;
	scanf("%d", &n);

	reNum(n);

}
