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

void preOrder(struct node * root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main(){

    struct node* n1 = createNode();
    struct node* n2 = createNode();
    struct node* n3 = createNode();
    n1->left = n2;
    n1->right = n3;
    struct node* n4 = createNode();
    struct node* n5 = createNode();
    struct node* n6 = createNode();
    struct node* n7 = createNode();
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    struct node* n8 = createNode();
    struct node* n9 = createNode();
    n5->right = n8;
    n7->right = n9;

    printf("\nPreOrder traversal: ");
    preOrder(n1);
    printf("\nPostOrder traversal: ");
    postOrder(n1);
    printf("\ninOrder traversal: ");
    inOrder(n1);
}
