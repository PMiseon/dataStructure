#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void ABC(int *a, int k) {

	int *max = (a+k);
	int tmp; 
	int *p;

	for (p = a + k; p < a + 10; p++) {
		if (*p > *max) {
			max = p;
		}
	}

	//swap
	tmp = *(a + k);
	*(a + k) = *max;
	*max = tmp; 

}

int main() {

	int arr[10] = { 0 };
	int i;

	for (i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
	
	for (i = 0; i < 10; i++) {
		ABC(arr, i);
	}

	for (i = 0; i < 10; i++) {
		printf(" %d", arr[i]);
	}

	return 0;
}
