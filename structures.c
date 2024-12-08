#include<stdio.h>


struct student{
    int rollno;
    float marks;

}; struct student stu[10];


int main(){

    int i;
    for(i = 0 ; i<10; i++){
        printf("Enter %d student details :   ",i+1);
        scanf("%d", &stu[i].rollno);
        scanf("%f", &stu[i].marks);
    }

    for(i = 0 ; i<10; i++){
        printf("%d \t", stu[i].rollno);
        printf("%f \t", stu[i].marks);
        printf("\n");
    }

    return 0;
}