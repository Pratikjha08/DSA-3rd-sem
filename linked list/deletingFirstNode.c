#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node * nodeAtEnd(node* ptr, int data){
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}

node * deleteNode(node *head){
    node *temp = head;
    head = head->link;
    free(temp);
    return head;
}

void printData(node *head){
    node *ptr = head;
    if (ptr == NULL){
        printf("The linked list is empty");
    }
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
}

int main(){
    node *head = (node *)malloc(sizeof(node));
    head->data = 1;
    head->link = NULL;
    node *ptr = head;
    ptr = nodeAtEnd(ptr, 2);
    ptr = nodeAtEnd(ptr, 3);
    ptr = nodeAtEnd(ptr, 4);
    printf("Before Deleting: ");
    printData(head);
    printf("\nAfter Deleting: ");
    head = deleteNode(head);
    printData(head);
    return 0;
}