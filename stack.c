#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int size;
    int top;
    int *arr;
} st;

int isEmpty(st* ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(st* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}
void push(st *ptr, int data){
    if(isFull(ptr)){
        printf("Stack Overflow. \n");
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = data;
}

void display(st *s){
    if(isEmpty(s)){
        printf("Stack is Empty.\n");
        return;
    }
    int top = s->top;
    printf("\nStack : ");
    for(int i = 0; i<=s->top; i++){
        printf("%d \t",s->arr[i]);
    }
    printf("\n");
}

void pop(st *s){
    if(isEmpty(s)){
        printf("Stack is Empty.\n");
        return;
    }
    printf("%d is poped.\n",s->arr[s->top]);
    s->top--;
}

void peek(st *s){
    if(isEmpty(s)){
        printf("Stack is Empty.\n");
        return;
    }
    printf("%d is the 1st element. \n", s->arr[0]);
}

int main(){
    
    st *s = (st*)malloc(sizeof(st));
    s->size = 10;
    s->top = -1;
    s->arr = (int *) malloc(s->size*sizeof(int));

    printf("%d \n", isEmpty(s));
    printf("%d \n", isFull(s));

    push(s,2);
    push(s,3);
    push(s,4);

    display(s);

    pop(s);

    display(s);

    peek(s);

    printf("%d \n", isEmpty(s));
    printf("%d \n", isFull(s));

    return 0;
}