#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;

node * createNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void add(node * head, int data){
    node *ptr = head;
    node *toAdd = createNode(data);
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = toAdd;
    toAdd->prev = ptr;
}

void createList(node *head, int n){
    int *data = (int *)malloc(n*sizeof(int));
    printf("Enter %d data: ",n);
    for (int i = 0; i<n; i++){
        scanf("%d",&data[i]);
    }
    for (int i=0; i<n; i++){
        add(head, data[i]);
    }
}

void display(node *head){
    node *ptr = head;
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    node *head = createNode(1);
    int n;
    printf("Enter number of nodes to add: ");
    scanf("%d",&n);
    createList(head, n);
    display(head);
    return 0;
}