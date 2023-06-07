#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {
	int id, data;
	struct Node *left, *right;
}Node;

Node* getNode(int id, int data, Node *left, Node *right) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->id = id;
	newNode->data = data;
	newNode->left = left;
	newNode->right = right;

	return newNode;
}

void makeTree(Node *t) {

	Node *f7 = getNode(7, 130, NULL, NULL);
	Node *f8 = getNode(8, 80, NULL, NULL);
	Node *f6 = getNode(6, 120, f7, f8);
	Node *f3 = getNode(3, 50, NULL, f6);
	Node *f4 = getNode(4, 70, NULL, NULL);
	Node *f5 = getNode(5, 90, NULL, NULL);
	Node *f2 = getNode(2, 30, f4, f5);
	Node *f1 = getNode(1, 20, f2, f3);

	*t = *f1;
}

Node *findNode(Node *t, int id) { //id 찾기 
	if (t == NULL)return NULL;
	if (t->id == id) {
		return t;
	}

	Node* leftNode = findNode(t->left, id);
	if (leftNode != NULL) {
		return leftNode;
	}
	Node* rightNode = findNode(t->right, id);
	if (rightNode != NULL) {
		return rightNode;
	}
}

void preOrder(Node *t) { //선위순회 
	if (t == NULL) {
		return;
	}

	printf(" %d", t->data); //visit 
	preOrder(t->left);
	preOrder(t->right);
}

void inOrder(Node *t) {
	if (t == NULL) return;

	if (t->left != NULL) {
		inOrder(t->left);
	}
	printf(" %d", t->data); //visit
	if (t->right != NULL) {
		inOrder(t->right);
	}
}

void postOrder(Node *t) {
	if (t == NULL) return;
	if (t->left != NULL) {
		postOrder(t->left);
	}
	if (t->right != NULL) {
		postOrder(t->right);
	}
	printf(" %d", t->data);
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

	Node *tree = (Node*)malloc(sizeof(Node));
	makeTree(tree);

	int cmd;
	scanf("%d", &cmd);
	int id;
	scanf("%d", &id);

	Node *start = (Node*)malloc(sizeof(Node)); //subtree root 
	start = findNode(tree, id);
	;
	if (start == NULL) { //찾는 노드가 없었으므로 종료 
		printf("-1");
		freeMemory(tree);
	    free(tree);
		return;
	}

	if (cmd == 1) { //선위
		preOrder(start);
	}

	else if (cmd == 2) { //중위 
		inOrder(start);
	}

	else if (cmd == 3) { //후위 
		postOrder(start);
	}

	freeMemory(tree);
	free(tree);
	free(start);
}
