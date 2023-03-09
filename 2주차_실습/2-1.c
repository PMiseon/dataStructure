//자료구조 2주차 실습

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int modulo(int a, int b) {
	return a % b;
}

int main() {

	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", modulo(a, b));

}
