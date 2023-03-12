//2주차 2번 O(n)으로 구현하기 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int mostOnes(int** a, int n) {

	int row = 0,jmax = 0;
	int i, j = 0;

	for (i = 0; i < n; i++) {
		while ((j < n) && (a[i][j] == 1)) {
			j++;
		}

		if (j > jmax) {
			row = i;
			jmax = j;
		}
	}


	return row;
}

int main() {
	
	int n;
	scanf("%d", &n);

	int** arr;
	int i, j;
	
	arr = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int)*n);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	printf("%d", mostOnes(arr, n));

}

/*
8
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0

*/
