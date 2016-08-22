#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


void display(char text[], int list[], int length) {
    printf("%s: ", text);
    for(int i = 0; i < length; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void swap(int list[], int x, int y) {
	int temp = list[x];
	list[x] = list[y];
	list[y] = temp;
}

int partition(int list[], int left, int right, int pivot, int length) {
	int leftCursor = left;
	int rightCursor = right -1;
	while(true) {
		while(list[leftCursor] < pivot) {
			leftCursor++;
		}
		while(list[rightCursor] > pivot && 0 < rightCursor) {
			rightCursor--;
		}
		if(leftCursor>=rightCursor) {
			break;
		} else {
			swap(list, leftCursor, rightCursor);
		}
	}
	swap(list, leftCursor, right);
	display("In this iteration", list, length);
	return leftCursor;
}

void quickSort(int list[], int left, int right, int length) {
	if(left>=right) {
		return;
	} else {
		int pivot = list[right];
		int partitionPoint = partition(list, left, right, pivot, length);
		quickSort(list, left, partitionPoint - 1, length);
		quickSort(list, partitionPoint + 1, right, length);
	}
}


int main() {
	int list[] = {8, 1, 3, 5, 7, 9, 2, 4, 6, 0};
	int length = sizeof(list)/sizeof(int);
    display("Before quick Sort", list, length);
    quickSort(list, 0, length - 1, length);
    display("After quick Sort", list, length);
    return 0;
}