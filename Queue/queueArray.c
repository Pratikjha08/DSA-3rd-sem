#include <stdio.h>
#define Max 100

typedef struct queue {
    int data[Max];
    int rear;
    int front;
}Q;

Q createQueue(){
    Q q;
    q.front = -1;
    q.rear = -1;
    return q;
}

int isFull(Q *q){
    return (q->rear == Max-1);
}
int isEmpty(Q *q){
    return (q->rear == q->front);
}

void enqueue(Q *q, int data){
    if(isFull(q)){
        printf("The queue is full");
        return;
    }
    q->data[++(q->rear)] = data;
    printf("%d was add in queue\n", data);
    if (q->front == -1){
        q->front = 0;
    }
}

int dequeue(Q *q){
    if(isEmpty(q)){
        printf("The queue is empty");
        return -1;
    }
    return q->data[(q->front)++];
}

void display(Q *q){
    for (int i = q->front; i<=q->rear; i++){
        printf("%d ",q->data[i]);
    }
}

int main(){
    Q q = createQueue();
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    printf("%d was dequed from the queue\n", dequeue(&q));
    display(&q);
    return 0;
}