#include <stdio.h>
#include <stdlib.h>

int main(){
    int **arr;
    int *row, *column, *value;
    int m, n, count = 0, k=0;
    printf("Enter row and column of sparse matrix: ");
    scanf("%d%d",&m, &n);
    arr = (int **)malloc(m*sizeof(int));
    for (int i = 0; i<n; i++){
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            scanf("%d",&arr[i][j]);
            if (arr[i][j] != 0){
                count++;
            }
        }
    }
    row = (int *)malloc(count * sizeof(int));
    column = (int *)malloc(count * sizeof(int));
    value = (int *)malloc(count * sizeof(int));
    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if (arr[i][j] != 0){
                row[k] = i;
                column[k] = j;
                value[k] = arr[i][j];
                k++;
            }
        }
    }
    for (int i = 0; i<count; i++){
        printf("value: %d at row index: %d and column index: %d \n",value[i],row[i],column[i]);
    }
    return 0;
}