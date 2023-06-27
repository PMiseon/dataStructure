#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {
	int elem; //노드 번호
	struct Node *left, *right;
}Node;

Node *getNode(int e) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->elem = e;
}

Node *findNode(Node *r, int id) {
	if (r == NULL) return NULL;

	if (r->elem == id) {
		return r;
	}

	Node *leftNode = findNode(r->left, id);
	if (leftNode != NULL) {
		return leftNode;
	}

	Node *rightNode = findNode(r->right, id);
	if (rightNode != NULL) {
		return rightNode;
	}
}

void *makeNode(Node *p, int l, int r) { //elem, left elem, right elem 
	//Node *p;// = getNode(e);
	//printf("check : %d\n", e);

	if (l != 0) {
		p->left = getNode(l);
		//int newE, newI, newR;
		//scanf("%d %d %d", &newE, &newI, &newR);
		//p->left = makeNode(newE, newI, newR);
	}

	if (r != 0) {
		p->right = getNode(r);
		//int newE, newI, newR;
		//scanf("%d %d %d", &newE, &newI, &newR);
		//p->right = makeNode(newE, newI, newR);
	}
}

Node *buildTree(int n) {
	int e, l, r, i;
	scanf("%d %d %d", &e, &l, &r);
	Node *root = getNode(e);
	if (l != 0) {
		root->left = getNode(l);
	}
	if (r != 0) {
		root->right = getNode(r);
	}

	for (i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &e, &l, &r);
		Node *k = findNode(root, e);
		k = makeNode(k, l, r);
	}
	return root;
}

void preOrder(Node *t) {
	//선위순회, 확인용
	if (t == NULL) return;

	printf("%d ", t->elem);
	preOrder(t->left);
	preOrder(t->right);
}

void freeMemory(Node *t) {
	if (t == NULL) return;
	if (t->left != NULL) {
		freeMemory(t->left);
	}
	if (t->right != NULL) {
		freeMemory(t->right);
	}
	if (t->left == NULL && t->right == NULL) {
		free(t);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	Node *root = buildTree(n);
	//preOrder(root);

	int m;
	scanf("%d", &m);
	getchar();
	int i;
	for (i = 0; i < m; i++) {
		char tmp[100] = { 0 };
		scanf("%s", tmp);
		getchar();
		char *p;
		Node *q = root; 
		printf(" %d", q->elem);

		for (p = tmp; *p != NULL; p++) {
			if (*p == 'R') {
				q = q->right;
				printf(" %d", q->elem);
			}

			else if (*p == 'L') {
				q = q->left;
				printf(" %d", q->elem);
			}
		}

		printf("\n");
	}

	freeMemory(root);
	free(root);
}
