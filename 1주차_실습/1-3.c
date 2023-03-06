#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void swap(int *ap, int *bp) {

	int tmp;
	tmp = *ap;
	*ap = *bp;
	*bp = tmp;
}


int main() {

	int N, a, b;
	int arr[50] = { 0 };

	scanf("%d", &N);
	int i;
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d %d", &a, &b);

	swap(&arr[a], &arr[b]);
	
	for (i = 0; i < N; i++) {
		printf(" %d", arr[i]);
	}

	return 0;
}
