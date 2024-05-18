#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int size, int key){
    int s = 0, e = size - 1;
    while (s<=e){
        int mid = (s+e)/2;
        if (arr[mid] == key){
            return 1;
        }else if (arr[mid]>key){
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return 0;
}

int main(){
    int size, *arr, key;
    printf("Enter size of array: ");
    scanf("%d",&size);
    arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i<size; i++){
        printf("Enter %d element: ", i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d",&key);
    if (binarySearch(arr, size, key)){
        printf("%d is present in array",key);
    }else{
        printf("%d is not present in array", key);
    }
    return 0;
}