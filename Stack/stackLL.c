#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

typedef struct stack{
    node *top;
}Stack;


Stack* createStack(){
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack->top = NULL;
    return newStack;
}

node* createNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void push(Stack* stack,int data){
    node *toPush = createNode(data);
    toPush->link = stack->top;
    stack->top = toPush;
    printf("%d is pushed into stack\n",data);
}

void isEmpty(Stack *stack){
    if (stack->top == NULL){
        printf("The stack is empty");
    }else{
        printf("The stack is not empty");
    }
}

int pop(Stack *stack){
    isEmpty(stack);
    node *ptr = stack->top;
    stack->top = ptr->link;
    int popped = ptr->data;
    free(ptr);
    ptr = NULL;
}

int peek(Stack *stack){
    isEmpty(stack);
    return(stack->top->data);
}

void printStack(Stack *stack){
    node *ptr = stack->top;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
}

int main(){
    Stack *stack1 = createStack();
    push(stack1,1);
    push(stack1,2);
    push(stack1,3);
    push(stack1,4);
    push(stack1,5);
    push(stack1,6);
    push(stack1,7);
    printf("The top element is %d\n",peek(stack1));
    printf("%d is popped form the stack\n",pop(stack1));
    printf("%d is popped form the stack\n",pop(stack1));
    printStack(stack1);
    return 0;
}