#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

typedef struct Queue{
    node *front;
    node *rear;
}Queue;

Queue* createQueue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

node* createNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->link =NULL;
    return newNode;
}

int isEmpty(Queue *q){
    return (q->front == NULL);
}

void enqueue(Queue *q,int data){
    node *toEnqueue = createNode(data);
    if (q->front == NULL){
        q->front = q->rear = toEnqueue;
    }else{
        q->rear->link = toEnqueue;
        q->rear = toEnqueue;
    }
    printf("%d is added to the queue\n",data);
}

int dequeue(Queue *q){
    if (isEmpty(q)){
        printf("UnderFlow");
        return -1;
    }
    node *temp = q->front; 
    q->front = temp->link;
    int data = temp->data;
    free(temp);
    temp = NULL;
    return data;
}

void display(Queue *q){
    node *ptr = q->front;
    if (isEmpty(q)){
        printf("The queue is Empty\n");
    }
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main(){
    Queue *queue = createQueue();
    enqueue(queue,1);
    enqueue(queue,2);
    enqueue(queue,3);
    enqueue(queue,4);
    enqueue(queue,5);
    printf("%d is removed from the queue\n", dequeue(queue));
    display(queue);
    return 0;
}