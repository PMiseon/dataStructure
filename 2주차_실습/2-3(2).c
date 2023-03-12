//3-1 시간 측정하기 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
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
	}


}

void prefixAverages2(int *x, int n) {
	int i, j, sum = 0;
	int *A = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		sum += x[i];
		A[i] = (double)sum / (i + 1) + 0.5;
	}

}


int main() {

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	int n;
	scanf("%d", &n);

	int *x;
	x = (int*)malloc(sizeof(int)*n);

	int i;
	for (i = 0; i < n; i++) {
		//scanf("%d", &x[i]);
		//난수발생 함수를 사용하여 크기 n의 1~10,000 사이의 정수 배열 X를 초기화한 후 각 함수를 한 번씩 호출한다.
		x[i] = rand() % 10000 + 1;
	}


	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	// 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
	prefixAverages1(x, n);
	QueryPerformanceCounter(&end);
	// 측정값으로부터 실행시간 계산
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));


	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	// 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
	prefixAverages2(x, n);
	QueryPerformanceCounter(&end);
	// 측정값으로부터 실행시간 계산
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	return 0;
}
