#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int findChar(int count, char c, char *find) {
	
	if (*find == NULL) {
		return count;
	}

	if (*find == c)
		count++;
	findChar(count, c, (find+1));
}


int main() {
	char input[100] = { 0 };
	scanf("%s", &input);

	getchar();

	char c;
	scanf("%c", &c);

	printf("%d\n",findChar(0, c, &input));

}
