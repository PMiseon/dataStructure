#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)


typedef struct info {
	char name[10];
	int grade;
}info;

int main() {

	info s[5];
	double avg = 0;
	int sum = 0;


	int i;
	for (i = 0; i < 5; i++) {
		scanf("%s %d", &s[i].name, &s[i].grade);
		sum += s[i].grade;
	}

	avg = sum / 5;

	for (i = 0; i < 5; i++) {
		if (s[i].grade <= avg) {
			printf("%s\n", s[i].name);
		}
	}
}
