#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {
	int coef, exp; //계수, 차수 
	struct Node *next;
}Node;

void appendTerm(Node *k, int c, int e) {
	Node *t = malloc(sizeof(Node));
	t->next = NULL;
	t->exp = e;
	t->coef = c;

	while (k->next != NULL) {
		k = k->next;
	}

	k->next = t;
}

Node* addPoly(Node *A, Node *B) {
	Node *result = malloc(sizeof(Node));
	result->next = NULL;

	Node *i = A->next;
	Node *j = B->next;
	Node *k = result; 

	while ((i != NULL) && (j != NULL)) {
		if (i->exp > j->exp) {
			appendTerm(result, i->coef, i->exp);
			i = i->next;
		}

		else if (i->exp < j->exp) {
			appendTerm(result, j->coef, j->exp);
			j = j->next;
		}

		else {
			int sum = i->coef + j->coef;
			if (sum != 0) {
				appendTerm(result, sum, i->exp);
			}
			i = i->next;
			j = j->next;
		}
	}

	while (i != NULL) {
		appendTerm(result, i->coef, i->exp);
		i = i->next;
	}

	while (j != NULL) {
		appendTerm(result, j->coef, j->exp);
		j = j->next;
	}

	return result;
}

void traverse(Node *result) {
	Node *p = result->next;

	while (p != NULL) {
		printf("%d %d ",p->coef, p->exp );
		p = p->next;
	}
}

int main() {

	Node *A = malloc(sizeof(Node));
	A->next = NULL; //headerA 

	Node *B = malloc(sizeof(Node));
	B->next = NULL; //headerB


	int n, m; 
	int coef, exp;

	scanf("%d",&n);
	int i;
	
	for (i = 0; i < n; i++) {
		scanf("%d %d", &coef, &exp);
		appendTerm(A, coef, exp);
	}

	scanf("%d", &m);

	for (i = 0; i < m; i++) {
		scanf("%d %d", &coef, &exp);
		appendTerm(B, coef, exp);
	}

	Node *result = addPoly(A, B);
	traverse(result);
	//scanf("%m")
}
