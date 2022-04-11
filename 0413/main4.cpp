#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int start;
	int end;
}time;

int possibleMeeting(time* arr, int size) {
	int index = 0, end = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].start >= end) {
			index++;
			end = arr[i].end;
		}
	}
	return index;
}

void printMeeting(time* arr, int size) {
	int end = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].start >= end) {
			printf("%d %d\n", arr[i].start, arr[i].end);
			end = arr[i].end;
		}
	}
}

int main() {
	int size;
	scanf("%d", &size);
	time* arr = (time*)malloc(size * sizeof(time));
	for (int i = 0; i < size; i++)
		scanf("%d %d", &arr[i].start, &arr[i].end);

	printf("%d\n", possibleMeeting(arr, size));
	printMeeting(arr, size);
	return 0;
}