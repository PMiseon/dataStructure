#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void findMax(int arr[],int n, int index, int max) {

	if (index > n) {
		printf("%d\n", max);
		return;
	}

	if (arr[index] > max) {
		max = arr[index];
	}

	findMax(arr, n, index + 1, max);
}

int main() {
	int n;
	scanf("%d", &n);

	int i;
	int arr[21] = { 0 };

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	findMax(arr, n, 0,arr[0]);
}
