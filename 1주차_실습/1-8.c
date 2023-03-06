#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {
	char name[8];
	int kor, eng, math;
	double avg;
	//int great, bad; 
}Node;


int main() {

	int n;
	scanf("%d", &n);
	Node* s;
	s = (Node*)malloc(sizeof(Node)*n);

	

	int i;
	for (i = 0; i < n; i++) {
		scanf("%s %d %d %d", &s[i].name, &s[i].kor, &s[i].eng, &s[i].math);
		s[i].avg = (double)(s[i].kor + s[i].eng + s[i].math) / 3.0;
	}

	for (i = 0; i < n; i++) {

		printf("%s", s[i].name);
		printf(" %.1lf", s[i].avg);

		if ((s[i].kor >= 90) || (s[i].eng >= 90) || (s[i].math >= 90)) {
			printf(" GREAT");
		}


		if ((s[i].kor < 70) || (s[i].eng < 70) || (s[i].math < 70)) {
			printf(" BAD");
		}

		printf("\n");
	}


	


	return 0;
}
