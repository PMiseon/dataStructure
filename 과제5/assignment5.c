#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {
	char elem[100];// = { 0 };
	struct Node *left, *right;
}Node;

Node *getNode() {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


Node *makeExternalNode() { 
	Node *e = getNode();
	printf("Enter Decision:"); 

	char answer[100] = { 0 };
	gets(answer);
	strcpy(e->elem, answer);
	return e;
}


Node *makeInternalNode() {
	Node *i = getNode(); //internalNode 만들기 
	printf("Enter question:");
	char tmp[100] = { 0 };
	gets(tmp);

	strcpy(i->elem, tmp); //v.elem <- read()

	char answer[100] = { 0 };

	printf("Question if yes to '%s'", i->elem); //left child
	gets(answer);//scanf("%s", answer); //read()
	
	if (strcmp(answer, "yes") == 0) {
		i->left = makeInternalNode();
	}

	else { //no
		i->left = makeExternalNode();
	}

	printf("Question if no to '%s'", i->elem); //right child
	gets(answer);//read()

	if (strcmp(answer, "yes") == 0) {
		i->right = makeInternalNode();
	}

	else { //no 
		i->right = makeExternalNode();
	}

	return i;

}


Node *buildDecisionTree() {
	printf("***Let's build a dichotomous QA system\n");
	Node *root = makeInternalNode();
	return root;
}

int isInternal(Node *v) {
	
	if (v->left == NULL && v->right == NULL) { //external Node
		return 0; //false 
	}
	
	return 1; //true
}

void processNode(Node *v) {
		printf("%s", v->elem);
	
		if (isInternal(v)==1) {
			char tmp[100] = { 0 };
			scanf("%s", tmp); //read()
			if (strcmp(tmp, "yes")==0) { 
				processNode(v->left);
			}
			else { //no 
				processNode(v->right);
			}
	}
}

void runDecisionTree(Node *root) {
		printf("***Please answer question\n");
		processNode(root);
		printf("\n\n"); 
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

	Node *root = buildDecisionTree();
	printf("Tree complete. Now Running!!\n");

	int i;
	for (i = 0; i < 3; i++) { //three test runs
		runDecisionTree(root);
	}
	
	freeMemory(root);
	free(root);

	return 0;
}
