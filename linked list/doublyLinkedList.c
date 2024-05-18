#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;

node * newNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void display(node *head){
    node *ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    } 
}

int main(){
    node *head = newNode(1);
    node *node1 = newNode(2);
    head->next = node1;
    node1->prev = head;
    display(head);
    return 0;
}