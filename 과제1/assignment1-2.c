#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma warning (disable : 4996)

int countOnesButSlow(int** A, int n);
int countOnes(int** A, int n);
int** makeArr(int n, int* kTotal);

int main() {

	int num1 = 3000, num2 = 1000, num3 = 2000;
	//PC 성능문제로 모든 수를 1/10 

	int **arr1, **arr2, **arr3;

	int kTotal1 = 0, kTotal2 = 0, kTotal3 = 0;
	int slowOnes1, slowOnes2, slowOnes3;
	int fastOnes1, fastOnes2, fastOnes3;

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;


	arr1 = makeArr(num1, &kTotal1);
	arr2 = makeArr(num2, &kTotal2);
	arr3 = makeArr(num3, &kTotal3);



	//n1에 대한 빠른 버전의 수행 결과 
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	fastOnes1 = countOnes(arr1, num1);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("kTotal : %d, ones : %d, cputime : %.12f\n", kTotal1, fastOnes1, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	//n2에 대한 빠른 버전의 수행 결과 
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	fastOnes2 = countOnes(arr2, num2);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("kTotal : %d, ones : %d, cputime : %.12f\n", kTotal2, fastOnes2, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));


	//n3에 대한 빠른 버전의 수행 결과 
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	fastOnes3 = countOnes(arr3, num3);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("kTotal : %d, ones : %d, cputime : %.12f\n", kTotal3, fastOnes3, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));





	//n1에 대한 느린 버전의 수행 결과 
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	slowOnes1 = countOnesButSlow(arr1, num1);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("kTotal : %d, ones : %d, cputime : %.12f\n", kTotal1, slowOnes1, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	//n2에 대한 느린 버전의 수행 결과 
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	slowOnes2 = countOnesButSlow(arr2, num2);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("kTotal : %d, ones : %d, cputime : %.12f\n", kTotal2, slowOnes2, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	//n3에 대한 느린 버전의 수행 결과 
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	slowOnes3 = countOnesButSlow(arr3, num3);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("kTotal : %d, ones : %d, cputime : %.12f\n", kTotal3, slowOnes3, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	return 0;



}

int** makeArr(int n, int* total) {
	//n값에 대해 난수 함수를 이용하여 n*n 배열 초기화

	int i, j;
	int *k = (int*)malloc(sizeof(int)*(n + 1)); //k_i
	k[0] = n;

	int **arr = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int)*n);
	}

	int sum = 0;

	for (i = 0; i < n; i++) {

		srand(time(NULL));
		k[i + 1] = rand() % (int)(0.1*k[i] + 1) + (int)(0.9*k[i]);
		//k_i 개의 1 생성 

		//check
		for (j = 0; j < k[i + 1]; j++) {
			arr[i][j] = 1;
		}
		for (j = k[i + 1]; j < n; j++) {
			arr[i][j] = 0;
		}

		sum += k[i + 1];
	}


	*total = sum;

	return arr;

}

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
	int i = 0, j = n - 1;


	for (i = 0; i < n; i++) {

		while ((A[i][j] == 0) && (j >= 0)) {
			j--;
		}

		sum += j + 1;
	}

	return sum;

}

