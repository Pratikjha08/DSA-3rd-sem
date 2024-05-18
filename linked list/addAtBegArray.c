#include <stdio.h>

void addBeg(int *arr, int n, int data){
    for(int i = n-1; i>=0;i--){
        arr[i+1] = arr[i];
    }
    arr[0] = data;
}

int main(){
    int arr[10], n;
    printf("Enter number of element: ");
    scanf("%d",&n);
    for (int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    addBeg(arr, n, 1);
    for(int i = 0; i<(n+1); i++){
        printf("%d ",arr[i]);
    }
    return 0;
}