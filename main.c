#include <stdio.h>
#define SIZE 50

typedef struct{
    int top;
    int arr[SIZE];
} STACK;


void initialize(STACK *);
int push(STACK*,int);
int pop(STACK*,int *);
int empty(STACK*);
int full(STACK*);
void showStack(STACK*);
void peek(STACK*);

int main(int argc, char **argv)
{
    STACK stack;
    int x;
    int i;
    initialize(&stack);
    peek(&stack);
    for(i=0;i<55;i++) {
        push(&stack,5);
    }
    peek(&stack);
    for(i=0;i<10;i++) {
        pop(&stack,&x);
    }
    peek(&stack);
    for(i=0;i<5;i++) {
        push(&stack,3);
    }
    
    showStack(&stack);
    
    peek(&stack);
    
    return 0;
}

void peek(STACK *stack) {
    printf("-----------------%d-----------------------",stack->arr[stack->top-1]);
}

void showStack(STACK *stack) {
    int i;
    for(i=0;i<stack->top;i++) {
        printf("STACK[%d] = %d\n",i,stack->arr[i]);
    }
}

int push(STACK *stack, int x) {
    if(full(stack)) {
        stack->arr[stack->top]=x;
        stack->top++;
        printf("Sucessfully pushed!\n");
        return 0;
    }
    else {
        printf("THE STACK IS FULL!!\n");
        return -1;
    }
}

int pop(STACK *stack,int *x) {
    if(empty(stack)) {
        stack->top--;
        *x=stack->arr[stack->top];
        printf("Sucessfully poped!\n");
        return 0;
    }
    else {
        printf("THE STACK IS EMPTY!!\n");
        return -1;
    }
        
}

void initialize(STACK *stack) {
    stack->top=0;
}

int empty(STACK *stack) {
    if(stack->top == 0) {
        return 0;
    }
    else {
        return -1;
    }
}
int full(STACK *stack) {
    if(stack->top == SIZE) {
        return 0;
    }
    else {
        return -1;
    }
}