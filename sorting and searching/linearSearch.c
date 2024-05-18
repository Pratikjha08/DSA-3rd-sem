#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *arr, int size, int key){
    int i;
    for (i=0; i<size; i++){
        if (arr[i] == key){
            return 1;
            break;
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
    if (linearSearch(arr, size, key)){
        printf("%d is present in array",key);
    }else{
        printf("%d is not present in array", key);
    }
    return 0;
}