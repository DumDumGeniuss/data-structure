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

void merge(int list[], int low, int mid, int high, int length, int tempList[]) {
    int csr1, csr2, i;
    for(csr1 = low, csr2 = mid + 1, i = low; csr1 <= mid && csr2 <= high; i++) {
        if(list[csr1] <= list[csr2]) {
            tempList[i] = list[csr1];
            csr1++;
        } else {
            tempList[i] = list[csr2];
            csr2++;
        }
    }
    while(csr1 <= mid) {
        tempList[i] = list[csr1];
        csr1++;
        i++;
    }
    while(csr2 <= high) {
        tempList[i] = list[csr2];
        csr2++;
        i++;
    }
    for(i = low; i <= high; i++) {
        list[i] = tempList[i];
    }
    display("This iteration", list, length);
}

void sort(int list[], int low, int high, int length, int tempList[]) {
    if(low == high) {
        return;
    }
    int mid = (low + high)/2;
    sort(list, low, mid, length, tempList);
    sort(list, mid + 1, high, length, tempList);
    merge(list, low, mid, high, length, tempList);
}

void mergeSort(int list[],int length) {
    int tempList[length];
    sort(list, 0, length - 1, length, tempList);
}

int main() {
    int list[] = {3, 6, 7, 5, 4, 1, 9, 8, 0, 2};
    int length = sizeof(list)/sizeof(int);
    display("Before Merging Sort", list, length);
    mergeSort(list, length);
    display("After Merging Sort", list, length);
    return 0;
}
