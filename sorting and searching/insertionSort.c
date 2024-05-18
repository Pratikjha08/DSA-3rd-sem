#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int size){
    int i, j;
    for (i = 1; i < size; i++) {
        int temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main(){
    int *arr, size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    arr = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Array before sorting\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertionSort(arr, size);
    printf("Array after sorting\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}