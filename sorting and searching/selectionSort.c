#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *arr, int size){
    int i, j;
    for (i = 0; i < size - 1; i++) {
        int min = i;
        for (j = i + 1; j < size; j++) {
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if (min != i){
            int temp;
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
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
    selectionSort(arr, size);
    printf("Array after sorting\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}