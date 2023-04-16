#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {
	int elem;
	struct Node *next;
}Node;

Node* getNode(int e) {
	Node *newNode = malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->elem = e;

	return newNode;
}

void addNode(Node *k, int e) {
	Node *n = getNode(e);
	Node *p = k;

	while (p->next != NULL) {
		p = p->next;
	}

	p->next = n;
}

void freeMemory(Node *n) {
	//동적할당 해제하기
	Node *p = n, *nextNode;

	while (p != NULL) {
		nextNode = p->next;
		free(p);
		p = nextNode;
	}
}



Node* Union(Node *A, Node *B) {
	Node *a = A->next, *b = B->next;
	Node *U = getNode(0); //union (return 값)

	while ((a != NULL) && (b != NULL)) {
		//printf("%d %d\n", a->elem, b->elem);
		if (a->elem < b->elem) {
			addNode(U, a->elem);
			a = a->next;
		}

		else if (a->elem > b->elem) {
			addNode(U, b->elem);
			b = b->next;
		}

		else { //a->elem == b->elem
			addNode(U, a->elem);
			a = a->next;
			b = b->next;
		}
	}

	while (a != NULL) { 
		addNode(U, a->elem);
		a = a->next;
	}

	while (b != NULL) {
		addNode(U, b->elem);
		b = b->next;
	}

	return U;
}

Node* Intersect(Node *A, Node *B) {
	Node *a = A->next, *b = B->next;
	Node *I = getNode(0);

	while ((a != NULL) && (b != NULL)) {
		//printf("%d %d\n", a->elem, b->elem);
		if (a->elem < b->elem) {
			a = a->next;
		}

		else if (a->elem > b->elem) {
			b = b->next;
		}

		else { // a->elem == b->elem
			addNode(I, a->elem);
			a = a->next;
			b = b->next;
		}
	}

	return I;
}

void printNode(Node *n) {
	Node *p = n;

	//공집합인 경우
	if (p->next == NULL) {
		printf("0\n");
		return;
	}

	while (p->next != NULL) {
		p = p->next;
		printf(" %d", p->elem);
	}

	printf("\n");
}

int main() {

	Node *A, *B, *U, *I; //union, intersect 


	//make header Node
	A = getNode(0);
	B = getNode(0);
	U = getNode(0);
	I = getNode(0);

	int sizeA, sizeB, i,tmp;

	scanf("%d", &sizeA);

	for (i = 0; i < sizeA; i++) {
		scanf("%d", &tmp);
		addNode(A, tmp);
	}

	scanf("%d", &sizeB);

	for (i = 0; i < sizeB; i++) {
		scanf("%d", &tmp);
		addNode(B, tmp);
	}

	//printNode(A); //check
	//printNode(B); //check
	U = Union(A, B);
	printNode(U);
	
	I = Intersect(A, B);
	printNode(I);

	//동적할당해제 
	freeMemory(A);
	freeMemory(B);
	freeMemory(I);
	freeMemory(U);
}
