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

void addToEnd(node * head, int data){
    node *toAdd = newNode(data);
    node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    } 
    ptr->next = toAdd;
    toAdd->prev = ptr;
}

void display(node *head){
    node *ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    } 
}

node * reverse(node* head){
    node *ptr = head;
    node *temp = NULL;
    while (ptr != NULL) {
        temp = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = temp;
        ptr = ptr->prev;
    }
    head = temp->prev;
    return head;
}

int main(){
    node *head = newNode(1);
    addToEnd(head,2);
    addToEnd(head,3);
    addToEnd(head,4);
    addToEnd(head,5);
    printf("Before resersing: ");
    display(head);
    printf("\nAfter reversing: ");
    head = reverse(head);
    display(head);
    return 0;
}