#include<stdio.h>

void main(){
    int i , j , k, a1[2][2], a2[2][2], result[2][2];

printf("Enter the elements of first matrix:\n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            scanf("%d", &a1[i][j]);
        }
    }

printf("Enter the elements of second matrix:\n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            scanf("%d", &a2[i][j]);
        }
    }
    printf("First Matrix:\n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("%d\t", a1[i][j]);
        }
    }
    printf("Second Matrix:\n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("%d\t", a2[i][j]);
        }
    }
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            int sum = 0;
            for(k=0; k<2; k++){
               sum+= a1[i][k] * a2[k][j];
            }
            result[i][j] = sum;
        }
    }

    printf("\nResulutant Array : ");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}