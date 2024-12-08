#include<stdio.h>

int fibo(int n, int a, int b){
    if(n==0)
        return 0;
    else{
        printf("%d ", a);
        return fibo(n-1, b, a+b);
    }
}

int main(){
    fibo(0,0,1);
}