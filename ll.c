#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* address;
};

struct node *head = NULL, *temp , *newNode, *prevNode;

struct node* createNewNode(){
    int data;
    printf("Enter element : ");
    scanf("%d",&data);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->address = NULL;
    return newNode;
}

void createNode(){   
    char ch;
    head = createNewNode();
    temp = head;
    do{
        printf("Do you want to add more elements? (y/n)");
        scanf(" %c",&ch);
        if(ch == 'y' || ch == 'Y'){
            newNode = createNewNode();
            temp->address = newNode;
            temp = temp->address;
        }
    }while (ch == 'y' || ch == 'Y'); 
}

void display(){
    temp = head;
    if(temp == NULL){
        printf("List is empty.\n");
    }else{
        printf("\nLinked List : \n");
        while(temp != NULL){
            printf("%d\t", temp->data);
            temp = temp->address;            
        }
        printf("\n");
    }
}

void inBegining(){
    temp = head;
    newNode = createNewNode();
    newNode->address = temp;
    head = newNode;
}

void inEnd(){
    temp = head;
    if(temp == NULL){
        printf("List is empty. \n");
    }else{
        while(temp->address != NULL){
            temp = temp->address;
        }
        newNode = createNewNode();
        temp->address = newNode;
    }
}

void atSpecific(){
    temp = head;
    int pos;
    printf("Enter position : ");
    scanf("%d", &pos);

    if(pos == 1){
        inBegining();
    }
    int i = 2;
    while(temp->address != NULL){
        prevNode = temp;
        if(pos == i){
            newNode = createNewNode();
            newNode->address = prevNode->address;
            prevNode->address = newNode;
            return;
        }
        i++;
        temp = temp->address;
    }
    printf("Position out of bound. \n");
}

void delFirst(){
    temp = head;
    if(temp == NULL){
        printf("List is empty. \n");
    }else{
        head = temp->address;
        free(temp);
        temp = NULL;
        printf("First element is deleted.\n");
        display();
    }
}
void delLast(){
    temp = head;
    if(temp == NULL){
        printf("List is empty. \n");
    }else if(temp->address == NULL){
        head = NULL;
        free(temp);
        temp = NULL;
        printf("Only element is deleted. \n");
    }else{
        while (temp->address != NULL){
            prevNode = temp;
            temp = temp->address;
        }
        prevNode->address = NULL;
        free(temp);
        temp = NULL;
        printf("Last element deleted. \n");
        display();
    }
}
void delMid(){
    int pos;
    temp = head;
    bool check = true;    
    printf("Enter position: ");
    scanf("%d", &pos);

    if(temp == NULL){
        printf("List is empty. \n");
    }else if (pos == 1){
        head = temp->address;
        free(temp);
        temp = NULL;
        display();
    }else{
        for (int i = 2 ;temp != NULL; i++){
            prevNode = temp;
            temp = temp->address;
            if(pos == i){
                prevNode->address = temp->address;
                free(temp);
                temp = NULL;
                printf("Element at position %d deleted. \n",pos);
                check = false;
                display();
            }
        }
        check?NULL:"Positon not found.\n";
    }
}
int main(){
    int ch;
    while (1){
        printf("\nMenu:\n");
        printf("Enter 1 to Create a Linked List \n");
        printf("Enter 2 to Display the linked list \n");
        printf("Enter 3 to add element in the begining\n");
        printf("Enter 4 to add element in the end\n");
        printf("Enter 5 to add element at specific position\n");
        printf("Enter 6 to delete element in the begining\n");
        printf("Enter 7 to delete element in the end\n");
        printf("Enter 8 to delete element at specific position\n");
        printf("Enter 0 to Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &ch);

        switch (ch){
        case 1:
            createNode();
            break;
        case 2:
            display();
            break;
        case 3:
            inBegining();
            break;
        case 4:
            inEnd();
            break;
        case 5:
            atSpecific();
            break;
        case 6:
            delFirst();
            break;
        case 7:
            delLast();
            break;
        case 8:
            delMid();
            break;
        case 0:
            return 0;
        default:
            printf("Enter a valid number");
            break;
        }
    }
    return 0;
}
