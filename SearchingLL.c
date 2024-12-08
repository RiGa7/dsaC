#include <stdio.h>
#include <stdlib.h>
struct node
{
    int ele;
    struct node * address;
};struct node * start, *temp, *newNode;


void createNode(){
    int n, ele;
    char ch;
    printf("Enter the 1st element : ");
    scanf("%d", &ele);
    start = (struct node *) malloc(sizeof(struct node));
    start->ele = ele;
    start->address = NULL;

    
    printf("Want to add more elements (y/n)?");
    scanf(" %c", &ch);
    if(ch == 'y' || ch == 'Y'){
        temp = start;
        printf("Enter the number of elements to add : ");
        scanf("%d", &n);
        for(int i = 0 ; i<n; i++){
            printf("Enter element : ");
            scanf("%d", &ele);

            newNode = (struct node *)(malloc(sizeof(struct node)));
            newNode->ele = ele;
            newNode->address = NULL;
            temp->address = newNode;
            temp = newNode;
        }   
    }

}

void display(){
    if(start == NULL){
        printf("list is empty");
    }else{
        temp = start;
        while(temp != NULL){
            printf("%d\t",temp->ele);
            temp = temp->address;
        }
    }
}

void search(){
    int ele;
    
    if(start == NULL){
        printf("list is empty");
    }else{
        printf("\nEnter element to search: ");
        scanf("%d", &ele);
        temp = start;
        while(temp != NULL){
            printf("in serqach");
            if(temp->ele == ele){
                printf("Element found at adress %u", temp);
                exit(1);
            }
            temp = temp->address;
        }
        printf("\nElement not found");
    }
}

int main(){

    createNode();
    display();
    search();
    return 0;
}