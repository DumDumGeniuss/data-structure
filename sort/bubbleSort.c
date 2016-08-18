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

void bubbleSort(int list[], int length) {
    char duringBubbleText[] = "In this iteration";
    for(int i = 0; i < length; i++) {
        int swap = 0;
        for(int j = 0; j < length - 1 - i; j++) {
            if(list[j] >= list[j+1]) {
               int temp = list[j+1];
               list[j+1] = list[j];
               list[j] = temp;
               swap = 1;
            }
        }
        display(duringBubbleText, list, length);
        if(swap == 0) {
          break;
        }
    }
}

void main() {
    int list[] = {1, 2, 3, 6, 7, 5, 4, 9, 8, 0};
    int length = sizeof(list)/sizeof(int);
    display("Before bubbling", list, length);
    bubbleSort(list, length);
    display("After bubbling", list, length);
}
