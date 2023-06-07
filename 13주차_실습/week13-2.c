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

void preOrder(Node *t, int *sum) { //선위순회를 이용해서 합을 구했습니다 
	if (t == NULL) {
		return;
	}
	*sum += t->data; //visit 

	preOrder(t->left,sum);
	preOrder(t->right,sum);
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
	int id;
	scanf("%d", &id);

	int *sum = 0;

	Node *tree = (Node*)malloc(sizeof(Node));
	makeTree(tree);

	Node *start = (Node*)malloc(sizeof(Node)); //subtree root 
	start = findNode(tree, id);
	;
	if (start == NULL) { //찾는 노드가 없었으므로 종료 
		printf("-1");
		freeMemory(tree);
		free(tree);
		return;
	}

	preOrder(start, &sum);
	printf("%d", sum);


	freeMemory(tree);
	free(tree);
	free(start);
}
