#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};

bool isFull(struct queue* q){
    return(q->rear == q->size-1);    
}

bool isEmpty(struct queue* q){
    return(q->front == q->rear);
}

void enqueue(struct queue* q, int data){
    if(isFull(q)){
        printf("Overflow");
        return;
    }else{
        q->rear++;
        q->arr[q->rear] = data;
    }
}

void dequeue(struct queue* q){
    if(isEmpty(q)){
        printf("Underflow\n");
        return;
    }else{
        q->front++;
        printf("Dequed %d \n", q->arr[q->front]);
    }
}

void peek(struct queue* q){
    if(isEmpty(q)){
        printf("Underflow\n");
        return;
    }else{
        printf("1st element is : %d \n", q->arr[q->front+1]);
    }
}

int main(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));

    q->size = 3;
    q->front = -1;
    q-> rear = -1;
    q->arr = (int *) malloc(q->size*sizeof(int));

    printf("%d \n",isFull(q));
    printf("%d \n",isEmpty(q));
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,2);
    enqueue(q,1);
    printf("\n%d \n",isFull(q));
    printf("%d \n",isEmpty(q));
    dequeue(q);
    enqueue(q,1);
    printf("\n%d \n",isFull(q));
    printf("%d \n",isEmpty(q));

    peek(q); 

    return 0;
}