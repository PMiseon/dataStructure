#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct time {
	int hour, min, sec;
}time;

int main() {

	time t1, t2, answer;
	scanf("%d %d %d", &t1.hour, &t1.min, &t1.sec);
	scanf("%d %d %d", &t2.hour, &t2.min, &t2.sec);

	int flag = 0;

	//hour 
	answer.hour = t2.hour - t1.hour;
	
	//min
	answer.min = t2.min - t1.min;
	if (t2.min < t1.min) {
		answer.hour--;
		answer.min += 60;
	}

	answer.sec = t2.sec - t1.sec;
	if (t2.sec < t1.sec) {
		answer.min--;
		answer.sec += 60;
	}

	printf("%d %d %d\n", answer.hour, answer.min, answer.sec);

}
