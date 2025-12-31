#include <stdio.h>

int main()
{
    int n,i;
    int a = 1, b = 1, c;
    int count = 0;

    printf("Enter n: ");
    scanf("%d",&n);

    if(n==1 || n==2)
    {
        printf("Nth Fibonacci number = 1");
        printf("\nSteps = 1");
        return 0;
    }

    for(i=3;i<=n;i++)
    {
        count++;            // loop step
        c = a + b; count++;
        a = b;     count++;
        b = c;     count++;
    }

    printf("Nth Fibonacci number = %d", b);
    printf("\nSteps = %d", count);

    return 0;
}