#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {

	char elem;
	struct Node *prev, *next;
}Node;

void get(Node** header, Node **trailer, int r, int *n) {
	if ((r <= 0)||(r>*n)) {
		printf("invalid position\n");
		return;
	}

	else {
		Node *p = (*header);
		int i;
		for (i = 0; i < r; i++) {
			p = p->next;
		}
		printf("%c\n", p->elem);
	}
	
}

void set(Node **header, Node **trailer, int r, char e, int *n) {
	if ((r <= 0) || (r > *n)) {
		printf("invalid position\n");
		return;
	}

	Node* p = (*header);
	int i;
	for (i = 0; i < r; i++) {
		p = p->next;
	}
	p->elem = e;
	return;
}

Node* newNode() {
	Node *new = malloc(sizeof(Node));
	new->prev = NULL;
	new->next = NULL;

	return new;
}

void init(Node **header, Node **trailer, int *n) {
	(*header) = newNode();
	(*trailer) = newNode();

	(*header)->next = (*trailer);
	(*trailer)->prev = (*header);
	*n = 0;
}

void traverse(Node **header, Node **trailer) {
	Node *p = (*header)->next;
	while (p != (*trailer)) {
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
	return; 
}

void addNodeBefore(Node **header, Node **trailer, Node **p, char e) {
	Node *new = newNode();
	new->elem = e;

	new->prev = (*p)->prev;
	new->next = (*p);
	((*p)->prev)->next = new;
	(*p)->prev = new;

	return;

}

void add(Node **header, Node **trailer, char e, int r, int *n) {

	if ((r <= 0) || (r > *n + 1)) {
		printf("invalid position");
		return;
	}

	Node *p = (*header);
	int i;
	for (i = 0; i < r; i++) {
		p = p->next;
	}
	addNodeBefore(&header, &trailer, &p, e);
	*n = *(n)+1;
	return;
}

char removeNode(Node **header, Node **trailer, Node **p) {
	char e = (*p)->elem;

	((*p)->prev)->next = (*p)->next;
	((*p)->next)->prev = (*p)->prev;
	return e;
}

void delete(Node **header, Node **trailer, int r, int *n) {

	if ((r < 1) || (r > *n)) {
		printf("invalid position\n");
		return;
	}

	Node *p = (*header);

	int i;
	for (i = 0; i < r; i++) {
		p = p->next;
	}
	char e = removeNode(&header, &trailer, &p);
	*n = *n - 1;
	return; 

}

int main() {

	Node *header, *trailer;
	int n; //리스트 수 -> optional 

	init(&header, &trailer, &n);

	int k;
	scanf("%d", &k);
	getchar();

	int i;
	char cmd; 
	int tmpNum;
	char tmpChar;

	for (i = 0; i < k; i++) {
		scanf("%c", &cmd);

		switch (cmd) {
		case 'A': //add
			scanf("%d %c", &tmpNum, &tmpChar);
			add(&header, &trailer, tmpChar, tmpNum, &n);
			break;

		case 'D': //delete
			scanf("%d", &tmpNum);
			delete(&header, &trailer, tmpNum, &n);
			break;

		case 'P': //print
			traverse(&header, &trailer);
			break;

		case 'G': //get
			scanf("%d", &tmpNum);
			get(&header, &trailer, tmpNum, &n);
			break;
		}

		getchar();
	}

	
}
