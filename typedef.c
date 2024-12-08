#include <stdio.h>
#include <string.h>

typedef struct students{
   int rollno;
} stu;

void main(){
    stu s[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &s[i].rollno);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", s[i].rollno);
    }
    
}