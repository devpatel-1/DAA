#include <stdio.h>

int count = 0;

int fib(int n)
{
    count++;
    if(n==1 || n==2)
        return 1;

    return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    int result = fib(n);

    printf("Nth Fibonacci number = %d", result);
    printf("\nSteps = %d", count);

    return 0;
}