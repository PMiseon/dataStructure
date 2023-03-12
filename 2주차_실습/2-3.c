//3-1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

void prefixAverages1(int *x, int n) {
	int i, j, sum = 0;
	int *A = (double*)malloc(sizeof(double)*n);

	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++) {
			sum += x[j];
		}
		A[i] = (double)sum / (i + 1) + 0.5;
		printf("%d ", A[i]);
	}

	printf("\n");

}


/*
위의 의사코드 함수 prefixAverages1의 내용을 살펴보면, i 번째 외부 반복에서는,
바로 전 i – 1번째 반복에서 구했던 [0 ~ i – 1]의 합에, i + 1 번째 원소 값 한 개만을 더해 현재 합을 얻어 평균을 구한다. 
따라서 이를 수정하여 이전의 i – 1번째까지의 합을 보관하여 다음 반복으로 전달하는 방식으로 반복한다면 
현재 합을 구하는데 필요한 시간을 단축할 수 있다는 것을 알 수 있다. 
이렇게 중간 합을 보관하는 방식으로 알고리즘을 개선한 함수 prefixAverage2는 누적평균값들을 선형 시간에 구할 수 있게 된다.*/

void prefixAverages2(int *x, int n) {
	int i, j, sum = 0;
	int *A = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		sum += x[i];
		A[i] = (double)sum / (i + 1) + 0.5;
		printf("%d ", A[i]);
	}


	return A;

}


int main() {

	int n;
	scanf("%d", &n);

	int *x;
	x = (int*)malloc(sizeof(int)*n);

	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	prefixAverages1(x, n);
	prefixAverages2(x, n);

	return 0;
}
