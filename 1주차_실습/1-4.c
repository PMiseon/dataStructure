#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void shift(char *arr, int len) {

	char tmp;
//	int i;
	char *c; 
	tmp = *arr;
	//printf("%c\n", tmp);
	for (c = arr; c < (arr + len); c++) {
		*c = *(c + 1);
	}
	//*c = tmp;
	*(arr+len-1) = tmp;
	//*(c + len) = tmp;

	return;
}

int main() {

	char arr[100] = { 0 };
	scanf("%s", &arr);


	int len = strlen(arr);
	int i;
	for (i = 0; i < len; i++) {
		//shift(arr, len);
		printf("%s\n", arr);
		shift(arr, len);
	}

	return 0;
}
