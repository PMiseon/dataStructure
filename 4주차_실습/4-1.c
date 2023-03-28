#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void change(int* arr, int start, int end) {
	//뒤집기 정보 
	int i;
	int tmp;

	while (end > start) {

		tmp = *(arr + start);
		*(arr + start) = *(arr + end);
		*(arr + end) = tmp;

		start++;
		end--;
	}

}

int main() {
	int n;
	int arr[101] = { 0 };
	
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int k,start, end; //뒤집기 
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		scanf("%d", &start);
		scanf("%d", &end);

		change(arr, start, end);
	}

	for (i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
}
