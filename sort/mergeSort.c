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

void mergeSort(list, length) {
    sort(list, 0, length - 1);
}

void sort(int list[], int low, int high) {

}

void main() {
    int list[] = {1, 2, 3, 6, 7, 5, 4, 9, 8, 0};
    int length = sizeof(list)/sizeof(int);
    display("Before Merging Sort", list, length);
    mergeSort(list, length);
    display("After Merging Sort", list, length);
}
