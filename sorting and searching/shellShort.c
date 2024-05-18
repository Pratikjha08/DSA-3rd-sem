#include <stdio.h>
#include <stdlib.h>

void shellSort(int *arr, int size){
    int i, j, gap;
    for (gap = size/2; gap > 0; gap /= 2){
        for (i = gap; i < size; i++) {
            int temp = arr[i];
            j = i-1;
            while(j>=0 && arr[j]>temp){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
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
    shellSort(arr, size);
    printf("Array after sorting\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}