#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node * newNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void addBeg(node * tail , int data){
    node *toAdd = newNode(data);
    toAdd->next = tail->next;
    tail->next = toAdd;
}

void display(node *tail){
    node *ptr = tail->next;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr!= tail->next);
}


int main(){
    node *tail = newNode(5);
    addBeg(tail, 4);
    display(tail);
    return 0;
}