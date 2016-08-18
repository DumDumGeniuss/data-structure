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

void selectionSort(int list[], int length) {
    for(int i = 0; i < length; i++) {
        int minValueIndex = i;
        for(int j = i; j < length; j++) {
            if(list[j] < list[minValueIndex]) {
                minValueIndex = j;
            }
        }
        int temp = list[minValueIndex];
        list[minValueIndex] = list[i];
        list[i] = temp;
        display("In this iteration", list, length);
    }
}



void main() {
    int list[] = {7, 9, 3, 6, 0, 5, 4, 2, 8, 1};
    int length = sizeof(list)/sizeof(int);
    display("Before Selection Sort", list, length);
    selectionSort(list, length);
    display("After Selection Sort", list, length);
}
