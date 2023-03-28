#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)
//4주차 4번 


int main() {

	int n, m;
	int i = 0, j = 0;
	scanf("%d %d", &n, &m);

	int arr[100][100] = { 0 };

	int count = 1; 
	int flag = 0;
	arr[0][0] = 1;

	while (count < n * m ) {
		//오른쪽
		while ((j < m-1) && (arr[i][j + 1] == 0)) {
			arr[i][++j] = ++count;
		}
		//아래 
		while ((i < n-1) && (arr[i + 1][j] == 0)) {
			arr[++i][j] = ++count;
		}

		//왼쪽
		while ((j > 0) && (arr[i][j - 1] == 0)) {
			arr[i][--j] = ++count;
			//j--;
		}

		//위
		while ((i > 0) && (arr[i - 1][j] == 0)) {
			arr[--i][j] = ++count;
			//i--;
		}
	}


	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}

}
