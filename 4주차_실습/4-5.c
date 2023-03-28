#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)


//week4 - 5

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int arr[100][100] = { 0 };

	int count = 0;
	int i, j;
	int tmpI, tmpJ;

	//맨 윗줄부터 대각선으로 다 채우기 
	for (i = 0; i < m; i++) {
		tmpI = 0;
		tmpJ = i;
		while ((tmpJ != -1) &&(tmpI != n)) {
			arr[tmpI][tmpJ] = ++count;
			tmpJ--;
			tmpI++;
		}
	}

	//나머지 채우기 
	for (i = 1; i < n; i++) {
		tmpI = i;
		tmpJ = m - 1;
		while ((tmpJ != -1) && (tmpI != n)) {
			arr[tmpI][tmpJ] = ++count;
			tmpJ--;
			tmpI++;
		}
	}


	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}



}
