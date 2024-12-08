#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int size;
    int front;
    int rear;
    int *arr;
}q;

int isEmpty(q *q){
    return (q->front == q->rear);
}

int isFull(q *q){
    return ((q->rear+1)%q->size == q->front);
}

int main(){
    q *queue = (q*)malloc(sizeof(q));
    queue->size = 3;
    queue->front = -1;
    queue->rear = -1;
    queue->arr = (int *)malloc(queue->size*(sizeof(int)));

    printf("%d \n", isFull(queue));
    printf("%d \n", isEmpty(queue));
}