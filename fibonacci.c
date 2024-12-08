#include<stdio.h>

void fibo(int n, int a, int b) {
    if (n <= 0)
        return; // Base case: stop recursion when n reaches 0
    printf("%d  \n", a); 
    printf("n is : %d ", n);// Print the current Fibonacci number
    fibo(n - 1, b, a + b); // Recursive call with updated values
}

int main() {
    int n = 1; // Number of Fibonacci terms to generate
    printf("Fibonacci sequence up to %d terms:\n", n);
    fibo(n, 0, 1); // Start the Fibonacci sequence with 0 and 1
    return 0;
}
