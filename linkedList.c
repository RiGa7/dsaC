#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

// basic of struct

// struct student{
//     int rollno;
//     char name[];
// }; struct student stu; // stu will be use to access structer members e.g., stu.rollno;

// node for the linked list
struct node{
    int ele;
    struct node *address;
};
struct node *start = NULL, *newNode, *temp, *prevNode; // pointer type variable will be accessed by -> (arrow) e.g., start->ele;

void createNode(){
    int n;
    char ch;

    printf("Enter the first element: ");
    scanf("%d", &n);

    // Allocate memory for the first node
    start = (struct node *)malloc(sizeof(struct node));
    start->ele = n;
    start->address = NULL;
    temp = start;

    // Ask if user wants to add more nodes
    do{
        printf("Wanna add another element? (y/n): ");
        scanf(" %c", &ch); // Note the space before %c to handle newline
        if (ch == 'y' || ch == 'Y'){
            printf("Enter the next element: ");
            scanf("%d", &n);

            // Allocate memory for the new node
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->ele = n;
            newNode->address = NULL;

            // Link the new node to the end of the list
            temp->address = newNode;
            temp = newNode; // Move temp to the new node
        }
    } while (ch == 'y' || ch == 'Y');
}

void display(){
    char ch;
    if (start == NULL){
        printf("List is empty \nWanna create list? (y/n): ");
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y'){
            createNode();
        }
    }
    else{
        temp = start;
        while (temp != NULL){
            printf(" %d", temp->ele);
            temp = temp->address;
        }
    }
}

void inBegining(){
    int n;
    temp = start;
    if (start != NULL){
        printf("Enter element : ");
        scanf("%d", &n);
        newNode = (struct node *)(malloc(sizeof(struct node)));
        newNode->ele = n;
        newNode->address = temp;
        start = newNode;
    }
    else{
        printf("No list exists. ");
    }
}

void inEnd(){
    int n;
    temp = start;
    if (start != NULL){
        printf("Enter element : ");
        scanf(" %d", &n);
        newNode = (struct node *)(malloc(sizeof(struct node)));

        while (temp->address != NULL){
            temp = temp->address;
        }
        newNode->ele = n;
        newNode->address = NULL;
        temp->address = newNode;
    }
    else{
        printf("No list exists. ");
    }
}

void atSpecific(){
    int n, pos;
    bool check = true;

    temp = start;
    prevNode = start;

    if (start != NULL){
        printf("Enter the position of element: ");
        scanf("%d", &pos);
        if (pos < 1){
            printf("Position should be greater than 0");
            return;
        }

        printf("Enter element : ");
        scanf(" %d", &n);

        newNode = (struct node *)(malloc(sizeof(struct node)));

        if (pos == 1){
            newNode->ele = n;
            newNode->address = temp;
            start = newNode;
            return;
        }

        for (int i = 0; i < pos - 1; i++){
            if (temp != NULL){
                prevNode = temp;
                temp = temp->address;
            }
            else{
                printf("Postion out of bound.");
                check = false;
                break;
            }
        }
        if (check){
            prevNode->address = newNode;
            newNode->ele = n;
            newNode->address = temp;
        }
    }
    else{
        printf("No list exists. ");
    }
}

void delFirst(){
    if (start == NULL){
        printf("List is empty");
    }
    else{
        temp = start;
        if (temp->address != NULL){
            printf("First node has been deleted.\n");
            start = start->address;
            printf("Remaing List is: ");
            display();
        }
        else{
            printf("Only element of list is deleted.\nList is empty now.");
            start = NULL;
        }

        free(temp);
        temp = NULL;
    }
}

void delMid(){
    if (start == NULL){
        printf("List is empty");
    }
    else{
        int n;
        bool found = false;
        printf("Enter element to delete: ");
        scanf("%d", &n);

        temp = start;
        prevNode = NULL;
        if (temp->address == NULL){
            if (temp->ele == n){
                printf("%d element has been deleted.\nNow List is empty.", n);
                free(temp);
                temp = NULL;
                start = NULL;
            }
            else{
                printf("Element not found");
            }
            return;
        }
        while (temp != NULL){
            if (temp->ele == n){
                found = true;
                break;
            }
            prevNode = temp;
            temp = temp->address;
        }
        if (found){
            printf("%d element has been deleted.\nCurrent list: ", n);
            if(prevNode != NULL){
                prevNode->address = temp->address;
            }
            else{ // If deleting the first node
                start = temp->address;
            }
            free(temp);
            display();
        }
        else{
            printf("Element not found.");
        }
    }
}

void delLast(){

    if (start == NULL){
        printf("List is empty");
    }
    else if (start->address == NULL){
        printf("Only node is deleted.\nList is empty now.");
        free(start);
        start = NULL;
    }
    else{

        temp = start;

        while (temp->address != NULL){
            prevNode = temp;
            temp = temp->address;
        }
        prevNode->address = NULL;
        free(temp);
        temp = NULL;
        printf("Last node has been deleted.\nCurrent list: ");
        display();
    }
}
int main(){
    int ch;
    while (1){
        printf("\nMenu:\n");
        printf("Enter 1 to Create a node \n");
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