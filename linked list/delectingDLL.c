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

node * delbeg(node *head){
    node *ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    ptr = NULL;
    return head;
}
void delend(node *head){
    node *ptr = head;
    node *temp;
    while (ptr->next != NULL){
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = NULL;
    free(ptr);
    ptr = NULL;
}

void delpos(node* head, int pos){
    node *ptr = head;
    while((pos--)!=1){
        ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    ptr = NULL;
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
    addToEnd(head,2);
    addToEnd(head,3);
    addToEnd(head,4);
    addToEnd(head,5);
    printf("Before: ");
    display(head);
    head = delbeg(head);
    printf("\nAfter (for Beg): ");
    display(head);
    delend(head);
    printf("\nAfter (for End): ");
    display(head);
    delpos(head , 2);
    printf("\nAfter (for Pos): ");
    display(head);
    return 0;
}