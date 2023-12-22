#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define NEWLINE 10

// function for swapping of two integer
int swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Heapify function
void Heapify(int arr[], int N, int i) {
    // root
    int largest = i;
    // left child
    int left = 2 * i + 1;
    // right child
    int right = 2 * i + 2;
    if(left < N && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right < N && arr[right] > arr[largest]) {
        largest = right;
    }
    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        Heapify(arr, N, largest);
    }
}

void buildHeap(int arr[], int N) {
    for(int i = N/2 - 1; i >= 0; i--) {
        Heapify(arr, N, i);
    }
}

void HeapSort(int arr[], int N) {
    buildHeap(arr, N);
    for(int i = N - 1; i >= 0; i--) {
        swap(&arr[i], &arr[0]);
        Heapify(arr, i, 0);
    }
}

int main(int argc, char** args) {
    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
    // buildHeap(arr, size);
    HeapSort(arr, size);
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

}