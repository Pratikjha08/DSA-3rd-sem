#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct Queue{
    int data[MAX_SIZE];
    int front;
    int rear;
}Queue;

Queue* createQueue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = MAX_SIZE-1;
    q->rear = MAX_SIZE-1;
    return q;
}

int isFull(Queue *q){
    return ((q->rear+1)%MAX_SIZE == q->front);
}

int isEmpty(Queue *q){
    return (q->rear == q->front);
}

void enqueue(Queue *q, int data){
    if (isFull(q)){
        printf("Overflow");
    }
    q->rear = (++q->rear)%MAX_SIZE;
    q->data[q->rear] = data;
    printf("%d was added into queue\n", data);
}

int dequeue(Queue *q){
    if (isEmpty(q)){
        printf("Underflow");
        return -1;
    }
    q->front = (++q->front)%MAX_SIZE;
    return(q->data[q->front]);
}

void display(Queue *q){
    if (isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    int i = (q->front + 1) % MAX_SIZE;
    while (i != (q->rear + 1) % MAX_SIZE){
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main(){
    Queue *q = createQueue();
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    printf("%d was removed from the queue\n",dequeue(q));
    display(q);
    free(q);
    return 0;
}