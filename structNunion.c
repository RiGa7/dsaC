#include <stdio.h>
#include <string.h>

struct students{
   int rollno;
   char name[20];
} s2 = {3, "Nikki"};
// outside main function or any other function decleration it's a global decleration.

struct students s3 = {34, "Girl"};
struct students s4 = {23};

union employee{
   int id;
   char name[20];
} e1 = {3};

int main(){
   struct students s1;
   s1.rollno = 32;
   strcpy(s1.name, "Rishika");
   printf("%d %s \n", s1.rollno, s1.name);
   printf("%d %s \n", s2.rollno, s2.name);
   printf("%d %s \n", s3.rollno, s3.name);
   printf("%d %s \n", s4.rollno, s4.name);

   printf("Employee data \n");
   printf("%d %s \n", e1.id, e1.name);
   printf("%s \n", e1.name);

   union employee e2;
   printf("%d %s \n", e2.id, e2.name);
   strcpy(e2.name, "nikki");
   printf("%d %s \n", e2.id, e2.name);
   printf("%d \n", e2.id);

}