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

node * addToBeg(node *head, int data){
    node *toAdd = newNode(data);
    head->prev = toAdd;
    toAdd->next = head;
    head = toAdd;
    return head; 
}

void addToEnd(node * head, int data){
    node *toAdd = newNode(data);
    node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    } 
    ptr->next = toAdd;
    toAdd->prev = ptr;
}

void addToPos(node *head, int data, int pos){
    node *toAdd = newNode(data);
    node *ptr = head;
    while ((--pos) != 1){
        ptr = ptr->next;
    }
    toAdd->prev = ptr;
    toAdd->next = ptr->next;
    ptr->next = toAdd;
}

void display(node *head){
    node *ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    } 
}

int main(){
    node *head = newNode(2);
    head = addToBeg(head, 1);
    head = addToBeg(head, 0);
    addToEnd(head,3);
    addToEnd(head,4);
    addToPos(head, 5, 3);
    display(head);
    return 0;
}