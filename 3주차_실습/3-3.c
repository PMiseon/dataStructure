#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void printNum(int n) {
	
	if (n == 0) {
		return;
	}

	printf("%d\n", n % 10);

	printNum(n / 10);
}

int main() {

	int n;
	scanf("%d", &n);
	printNum(n);

}
