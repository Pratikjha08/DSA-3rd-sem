#include <stdio.h>
#include <stdlib.h>

void swap(int *n1,int *n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int partition(int *arr, int low, int high){
    int i = low; 
    int j = high;
    int pivot = arr[low];
    while(i<j){
        while(arr[i]<=pivot && i<= high){
            i++;
        }
        while(arr[j]>pivot && j>= low ){
            j--;
        }
        if (i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int *arr, int low, int high){
    if (low<high){
        int pIndex = partition(arr,low,high);
        quickSort(arr,pIndex+1, high);
        quickSort(arr,low, pIndex-1);
    }
}

int main() {
    int *arr, size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int low = 0, high = size - 1;
    arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Array before sorting\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    quickSort(arr, low, high);
    printf("Array after sorting\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}  