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

void insertionSortWithGap(int list[], int length, int start, int gap) {
    for(int i = start; i < length - gap; i+=gap) {
        if(list[i] > list[i+gap]) {
            for(int j = i + gap; j >= gap; j-=gap) {
                if(list[j-gap] > list[j]) {
                    int temp = list[j - gap];
                    list[j - gap] = list[j];
                    list[j] = temp;
                } else {
                    break;
                }
            }
        }
    }
}

void shellSort(int list[], int length) {
    int gap = length/2;
    while(gap > 1) {
        for(int i = 0; i < gap; i++) {
            insertionSortWithGap(list, length, i, gap);
        }
        display("In this iteration", list, length);
        gap/=2;
    }
    insertionSortWithGap(list, length, 0, 1);
    display("In this iteration", list, length);
}

int main() {
    int list[] = {7, 9, 3, 6, 0, 5, 4, 2, 8, 1};
    int length = sizeof(list)/sizeof(int);
    display("Before insertion Sort", list, length);
    shellSort(list, length);
    display("After insertion Sort", list, length);
    return 0;
}
