#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *pointer;
}node;

int nodeCounter(node *head){
    int count = 0;
    node *ptr = head;
    while (ptr != NULL){
        count++;
        ptr = ptr->pointer;
    }
    return count;
}

void printData(node *head){
    node *ptr = head;
    if (ptr == NULL){
        printf("The linked list is empty");
    }
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->pointer;
    }
}

int main(){
    node *head;
    head = (node *)malloc(sizeof(node));
    head->data = 10;
    head->pointer = NULL;
    node *current = (node *)malloc(sizeof(node));
    current->data = 20;
    current->pointer = NULL;
    head->pointer = current;
    current = (node *)malloc(sizeof(node));
    current->data = 30;
    current->pointer = NULL;
    head->pointer->pointer = current;
    int ans = nodeCounter(head);
    printf("%d \n",ans);
    printData(head);
    return 0;
}