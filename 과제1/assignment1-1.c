#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)


int countOnesButSlow(int** A, int n) {
	//O(n^2)

	int sum = 0;
	int i, j;

	for (i = 0; i < n; i++) {
		j = 0;
		while ((j < n) && (A[i][j] == 1)) {
			sum++;
			j++;
		}
	}

	return sum;
}

int countOnes(int** A, int n) {
	//O(n)

	int sum = 0;
	int i=0, j = n-1;


	for (i = 0; i < n; i++) {
	
		while ((A[i][j] == 0) && (j>=0)) {
			j--;
		}

		sum += j + 1;
	}

	return sum;

}


int main() {

	int n, i,j;
	scanf("%d", &n);
	
	int** arr;
	arr = (int**)malloc(sizeof(int*)*n);

	for (i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int)*n);
	}


	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	printf("%d\n", countOnesButSlow(arr, n));
	printf("%d", countOnes(arr, n));

}

/*
8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 0
1 1 1 1 1 1 0 0
1 1 1 1 1 0 0 0
1 1 1 1 1 0 0 0
1 1 1 1 1 0 0 0
1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0
*/
