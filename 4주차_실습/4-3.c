#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int main() {
	int n;
	scanf("%d", &n);

	int i, j;
	int arr[100][100] = { 0 };

	//fillArray
	int count = 0;
	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (j = 0; j < n; j++) {
				arr[i][j] = ++count;
			}
		}

		else { //i%2 == 1
			for (j = n - 1; j >= 0; j--) {
				arr[i][j] = ++count;
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}
}
