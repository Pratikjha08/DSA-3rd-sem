#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node * atBegining(node* head, int data){
    node * temp = malloc(sizeof(node));
    temp->data = data;
    temp->link = head;
    return temp;
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
    head->data = 2;
    head->link = NULL;
    head = atBegining(head, 1);
    printData(head);
    return 0;
}