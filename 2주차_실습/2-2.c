//2-2
//mostOneButSlow 구현해보기 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int mostOneButSlow(int* a[], int n) {
	
	int row = 0, jmax = 0;
	int i, j;

	for (i = 0; i < n; i++) {
		j = 0;
		while ((j<n)&&(a[i][j] == 1)) {
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

	int i, j;
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

	printf("%d",mostOneButSlow(arr, n));

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
