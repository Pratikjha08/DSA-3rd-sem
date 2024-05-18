#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *pointer;
}node;

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
    int ans = head->pointer->pointer->data;
    printf("%d", ans);
    return 0;
}