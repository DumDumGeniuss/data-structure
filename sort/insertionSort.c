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

void insertionSort(int list[]) {
    for(int i = 0; i < MAX_LIST_LENGTH - 1; i++) {
        if(list[i] > list[i+1]) {
            for(int j = i + 1; j > 0; j--) {
                if(list[j-1] > list[j]) {
                    int temp = list[j - 1];
                    list[j - 1] = list[j];
                    list[j] = temp;
                } else {
                    break;
                }
            }
        }
        display("In this iteration", list);
    }
}

void main() {
    int list[] = {7, 9, 3, 6, 0, 5, 4, 2, 8, 1};
    display("Before insertion Sort", list);
    insertionSort(list);
    display("After insertion Sort", list);
}
