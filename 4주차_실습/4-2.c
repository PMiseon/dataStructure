#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)


int main() {

	int n;
	scanf("%d", &n);

	int x[100] = { 0 };
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	int m;
	scanf("%d", &m);

	int tmp1, tmp2;
	int tmp;
	scanf("%d", &tmp1);

	for (i = 0; i < m - 1; i++) {
		scanf("%d", &tmp2);
		tmp = x[tmp2];
		x[tmp2] = x[tmp1];
		x[tmp1] = tmp;
	}

	for (i = 0; i < n; i++) {
		printf(" %d", x[i]);
	}

 }
