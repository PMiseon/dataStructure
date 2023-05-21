#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {
	int name, data;
	struct Node *left, *right;
}Node;

Node* makeNode(int num, int data, Node *left, Node *right) {

	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->name = num;
	newNode->data = data;
	newNode->left = left;
	newNode->right = right;

	return newNode;
}

void makeTree(Node *root) {
	//◦ 단말 노드부터 생성하고, 부모노드를 붙여가는 방식으로 트리를 구성함.  

	Node *f7 = makeNode(7, 130, NULL, NULL);
	Node *f8 = makeNode(8, 80, NULL, NULL);
	Node *f6 = makeNode(6, 120, f7, f8);
	Node *f3 = makeNode(3, 50, NULL, f6);
	Node *f4 = makeNode(4, 70, NULL, NULL);
	Node *f5 = makeNode(5, 90, NULL, NULL);
	Node *f2 = makeNode(2, 30, f4, f5);
	Node *f1 = makeNode(1, 20, f2, f3);

	*root = *f1; 
}

void print(Node *node, int *flag) {
	printf("%d ", node->data);

	if (node->left != NULL) {
		printf("%d ", (node->left)->data);
	}

	if (node->right != NULL) {
		printf("%d ", (node->right)->data);
	}

	*flag = 1; //찾는 폴더가 있었다 
	return;
}


void findNode(int n, Node* root, int *flag) {
	Node *p = root;

	if (p->name == n) {
		print(p, flag);
		return;
	}

	if (p->left != NULL) {
		findNode(n, p->left,flag);
	}

	if (p->right != NULL) {
		findNode(n, p->right,flag);
	}

	else { //p->left == NULL && p->right == NULL
		return; 
	}
}


void freeMemory(Node* p) { //동적할당해제 
	
	if (p->left != NULL) {
		freeMemory(p->left);
	}

	if (p->right != NULL) {
		freeMemory(p->right);
	}

	free(p);
}


int main() {

	Node *root = (Node*)malloc(sizeof(Node));
	makeTree(root);

	int n;
	scanf("%d", &n);

	int flag = 0;

	findNode(n, root, &flag);

	if (flag == 0) {
		printf("-1\n");
	}

	freeMemory(root);


}
