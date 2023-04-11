#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

#define NG 5 //A,B,C,D,E
#define NE 4 //1,2,3,4

typedef struct Node {
	char groupName; //user name 
	int elementName; //coupon name 
	struct Node *nextElement, *nextGroup;
}Node;

typedef struct Element {
	int name;
	struct Node *next; //to header Node 
}Element;


typedef struct Group {
	char name;
	struct Node *next; // to header Node
}Group;



void addShare(Group *g, Element *e, char groupName, int elementName) { //추가하기 

	//newNode
	Node *newNode = malloc(sizeof(Node));
	newNode->elementName = elementName;
	newNode->groupName = groupName;
	newNode->nextElement = NULL;
	newNode->nextGroup = NULL;

	Node *p; 

	//addGroup
	p = e->next; //elementHeader 
	while ((p->nextGroup != NULL) && ((p->nextGroup)->groupName < groupName)) {
		p = p->nextGroup; 
	}//들어가야하는 자리의 prev

	newNode->nextGroup = p->nextGroup;
	p->nextGroup = newNode;
	


	//addElement 
	p = g->next; //groupHeader
	while ((p->nextElement != NULL) && ((p->nextElement)->elementName < elementName)) {
		p = p->nextElement;
	}//들어가야하는 자리의 prev

	newNode->nextElement = p->nextElement;
	p->nextElement = newNode;

	printf("OK\n");

	return;
}


void removeShare(Group *g, Element *e, char groupName, int elementName) {

	Node *r; //제거할 노드 
	Node *p;

	//remove from Group
	p = g->next; //header
	while ((p->nextElement)->elementName != elementName) {
		p = p->nextElement;
	} //제거해야하는 노드의 prev 
	r = p->nextElement;
	p->nextElement = r->nextElement;

	//remove from Element 
	p = e->next;
	while ((p->nextGroup)->groupName != groupName) {
		p = p->nextGroup;
	}//제거해야 하는 노드의 prev
	r = p->nextGroup;
	p->nextGroup = r->nextGroup;

	printf("OK\n");
	free(r); //제거한 노드 동적할당해제 
}


void traverseShareElements(Element *e) {
	Node *p = e->next; //header

	if (p->nextGroup == NULL) {
		printf("0\n");
		return;
	}
	//탐색할 원소가 없으면 0 출력 

	while (p->nextGroup != NULL) {
		p = p->nextGroup;
		printf("%c ", p->groupName);
	}
	//끝까지 탐색하면서 groupName 출력 

	printf("\n");
	return;
}

void traverseShareGroups(Group *g) {

	Node *p = g->next;

	if (p->nextElement == NULL) {
		printf("0\n");
		return;
	}
	//탐색할 원소가 없으면 0 출력 

	while (p->nextElement != NULL) {
		p = p->nextElement;
		printf("%d ", p->elementName);
	}
	//끝까지 탐색하면서 element Name 출력 

	printf("\n");
	return;
}

void freeMemorybyGroup(Group *g) { //동적할당 해제하기 
	Node *p = g->next;//header 
	Node *nextNode;

	while (p != NULL) {
		nextNode = p->nextGroup;
		free(p);
		p = nextNode;
	}
	//연결된 Group 끝까지 탐색하면서 동적할당 해제 
	//*g는 main 함수에서 동적할당해제 
}

void freeMemorybyElement(Element *e) {
	Node *p = e->next;//header 
	Node *nextNode;

	while (p != NULL) {
		nextNode = p->nextElement;
		free(p);
		p = nextNode;
	}
	//연결된 Element 끝까지 탐색하면서 동적할당 해제 
	//*e는 main 함수에서 동적할당해제 
}


int main() {

	int i;

	Element *e[NE]; //1,2,3,4
	Group *g[NG]; //A,B,C,D,E

	//init Element 
	for (i = 0; i < NE; i++) {
		e[i] = malloc(sizeof(Element));
		e[i]->name = i + 1;

		//헤더연결 
		Node *header = malloc(sizeof(Node));
		header->nextElement = NULL;
		header->nextGroup = NULL;
		

		e[i]->next = header;
	}


	//init Group 
	for (i = 0; i < 5; i++) {
		g[i] = malloc(sizeof(Group));
		g[i]->name = 'a' + i;

		//헤더연결 
		Node *header = malloc(sizeof(Node));
		header->nextElement = NULL;
		header->nextGroup = NULL;

		g[i]->next = header;
	}

	char cmd; //명령어 
	char group; //group 정보 
	int ele; //element 정보 

	while (1) {
		scanf("%c", &cmd);

		if (cmd == 'q') {
			break;
		}

		switch (cmd) {
		case'a':
			scanf("%d %c", &ele, &group);
			if (group == 'A') {
				addShare(g[0], e[ele - 1], group, ele);
			}
			else if (group == 'B') {
				addShare(g[1], e[ele - 1], group, ele);
			}
			else if (group == 'C') {
				addShare(g[2], e[ele - 1], group, ele);
			}
			else if (group == 'D') {
				addShare(g[3], e[ele - 1], group, ele);
			}
			else if (group == 'E') {
				addShare(g[4], e[ele - 1], group, ele);
			}

			break;

		case 'r':
			scanf("%d %c", &ele, &group);
			if (group == 'A') {
				removeShare(g[0], e[ele - 1], group, ele);
			}
			else if (group == 'B') {
				removeShare(g[1], e[ele - 1], group, ele);
			}
			else if (group == 'C') {
				removeShare(g[2], e[ele - 1], group, ele);
			}
			else if (group == 'D') {
				removeShare(g[3], e[ele - 1], group, ele);
			}
			else if (group == 'E') {
				removeShare(g[4], e[ele - 1], group, ele);
			}
			break;

		case 'e':
			getchar();
			scanf("%c", &group);

			if (group == 'A') {
				traverseShareGroups(g[0]);
			}

			else if (group == 'B') {
				traverseShareGroups(g[1]);
			}

			else if (group == 'C') {
				traverseShareGroups(g[2]);
			}

			else if (group == 'D') {
				traverseShareGroups(g[3]);
			}

			else if (group == 'E') {
				traverseShareGroups(g[4]);
			}
			//traverseShareGroup();
			break;

		case 'g':
			scanf("%d", &ele);
			traverseShareElements(e[ele - 1]);
			break;
		}

		getchar();

	}


	//동적할당해제하기 

	//freeMemorybyElement(Element *e)

	for (i = 0; i < NG; i++) {
		freeMemorybyGroup(g[i]);
		free(g[i]);
	}

	for (i = 0; i < NE; i++) {
		freeMemorybyElement(e[i]);
		free(e[i]);
	}
}


/*
a 1 C
a 4 A
a 4 E
a 4 D
e A
g 4
a 2 A
e A
r 4 A
g 4
e A
g 1
r 1 C
e C
g 1
g 3
q
*/

/*
[correct output]
OK
OK
OK
OK
4
A D E
OK
2 4
OK
D E
2
C
OK
0
0
0
*/
