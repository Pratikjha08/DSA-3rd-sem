#include <stdio.h>
#include <stdlib.h>  

void merge(int *arr, int low, int mid, int high){
    int *arr1;
    arr1 = (int *)malloc((high+1) * sizeof(int));
    int i = low;
    int j = mid+1;
    int k = low;
    while (i <= mid && j <= high){
        if (arr[i]<arr[j]){
            arr1[k] = arr[i];
            i++;
            k++;
        }else{
            arr1[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i <= mid){
        arr1[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high){
        arr1[k] = arr[j];
        j++;
        k++;
    }
    for (int i = 0; i<=high; i++){
        arr[i] = arr1[i];
    }
    free(arr1);
}

void mergeSort(int *arr, int low, int high){
    if (low == high){
        return;
    }
    int mid = (low+high)/2;
    mergeSort(arr,low, mid);
    mergeSort(arr,mid + 1, high);
    merge(arr, low, mid, high);
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
    mergeSort(arr, low, high);
    printf("Array after sorting\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}