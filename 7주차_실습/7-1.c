#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {
	int elem;
	struct Node *next;
}Node;

Node* newNode(int e) {
	Node* n = malloc(sizeof(Node));
	n->elem = e;
	n->next = NULL;

	return n;
}

void addElem(Node *N, int e) {

	Node *n = newNode(e);
	Node *p = N; 


	while (p->next != NULL) {
		p = p->next;
	}

	p->next = n;
	return;
}

void check(Node *N) { //확인용 
	Node *p = N;
	while (p != NULL) {
		printf("%d ", p->elem);
		p = p->next;
	}
}

int subset(Node *A, Node *B) {
	
	Node *ptrA = A, *ptrB = B;

	if (ptrA == NULL) { //A가 공집합인 경우 0 
		return 0;
	}

	while ((ptrA != NULL) && (ptrB != NULL)) {
		if (ptrA == NULL) {
			break;
		}

		if (ptrB == NULL) {
			break;
		}

		if(ptrA->elem == ptrB->elem) {
			ptrA = ptrA->next;
			ptrB = ptrB->next;
		}

		else if (ptrA->elem > ptrB->elem) {
			ptrB = ptrB->next;
		}

		else if (ptrA->elem < ptrB->elem) {
			break;
		}
	}

	if (ptrA == NULL) {
		return 0;
	}

	else {
		return ptrA->elem;
	}
}

void freeMemory(Node *N) {
	//동적할당해제하기
	Node *p = N, *nextNode;

	while (p != NULL) {
		nextNode = p->next;
		free(p);
		p = nextNode;
	}
}

int main() {

	Node *A = NULL,*B = NULL; 

	int sizeA, sizeB;
	int i, tmp;

	scanf("%d", &sizeA);
	for (i = 0; i < sizeA; i++) {
		scanf("%d", &tmp);
		if (A == NULL) {
			A = newNode(tmp);
		}

		else {
			addElem(A, tmp);
		}
	}

	//check(A);

	scanf("%d", &sizeB);
	for (i = 0; i < sizeB; i++) {
		scanf("%d", &tmp);
		if (B == NULL) {
			B = newNode(tmp);
		}

		else {
			addElem(B, tmp);
		}
	}

	printf("%d\n",subset(A, B));

	//동적할당해제하기 
	if (A != NULL) {
		freeMemory(A);
	}

	if (B != NULL) {
		freeMemory(B);
	}

}
