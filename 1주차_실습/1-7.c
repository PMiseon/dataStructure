#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int main() {


	int n;
	scanf("%d", &n);

	int* arr1; 
	int* arr2;

	arr1 = (int*)malloc(sizeof(int)*n);
	arr2 = (int*)malloc(sizeof(int)*n);

	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &arr2[i]);
	}

	for (i = 0; i < n; i++) {
		printf(" %d", arr1[i] + arr2[n - i - 1]);
	}


}
