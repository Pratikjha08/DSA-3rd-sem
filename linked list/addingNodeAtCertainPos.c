#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

void atPos(node *head, int pos, int data){
    node * temp = malloc(sizeof(node));
    temp->data = data;
    node *ptr = head;
    while((pos--)!=1){
        ptr = ptr->link;
    }
    temp->link = ptr->link;
    ptr->link = temp;
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
    node *current = (node *)malloc(sizeof(node));
    current-> data = 2; 
    current->link = NULL;
    head->link = current;
    current = (node *)malloc(sizeof(node));
    current-> data = 4; 
    current->link = NULL;
    head->link->link = current;
    printf("Before adding: ");
    printData(head);
    atPos(head, 2, 3);
    printf("\nafter adding: ");
    printData(head);
    return 0;
}