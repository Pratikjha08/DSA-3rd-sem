#include <stdio.h>

void push(int *arr, int top, int element);
void pop(int *arr, int top);
void displayStack(int *arr, int top);

int main(){
    int top = -1;
    int arr[100];
    int ch;
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    do{
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                int ele;
                printf("Element to be added: ");
                scanf("%d",&ele);
                top++;
                push(arr,top,ele);
                break;
            }
            case 2:{
                pop(arr,top);
                top--;
                break;
            }
            case 3:{
                displayStack(arr,top);
                break;
            }
        }
    }while(ch>=1 &&ch<=3);
    return 0;
}

void push(int *arr, int top, int element){
    arr[top] = element;
    printf("%d was added to the stack \n",arr[top]);
}

void pop(int *arr, int top){
    printf("%d was removed form the stack \n",arr[top]);
}

void displayStack(int *arr, int top){
    int i=top;
    if (i==-1){
        printf("Empty Stack\n");
    }else{
        for (i;i>=0;i--){
            printf("%d  ",arr[i]);
        }
        printf("\n");
    }
}