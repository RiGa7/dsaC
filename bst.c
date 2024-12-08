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

int isBST(struct node* root){
    static struct node* prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }else
        return 1;
}

void inOrder(struct node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main(){

    //      50
    //     /  \
    //    30   70
    //   / \   / \
    //  20 40 60 80

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


    printf("\ninOrder traversal: ");
    inOrder(n1);

    printf("\n%s ",isBST(n1) ? "is Bst" : "Not BST");
}
