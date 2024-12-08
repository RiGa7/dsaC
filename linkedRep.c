#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(){
    int ele;
    printf("Enter element");
    scanf("%d", &ele);
    
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->data = ele;
    n->left = NULL;
    n->right = NULL;
}

int main(){

    struct node* n1 = createNode();
    printf("%d\n", n1->data);
    struct node* n2 = createNode();
    printf("%d\n", n2->data);
    struct node* n3 = createNode();
    printf("%d\n", n3->data);
    n1->left = n2;
    n1->right = n3;
    struct node* n4 = createNode();
    printf("%d\n", n4->data);
}
