#include <stdio.h>

int count_loop = 0;
int count_eq = 0;
int count_rec = 0;

void loop(int);
void eq(int);
int rec(int);

int main() {
    int n, ans;

    printf("Enter the number: ");
    scanf("%d", &n);

    loop(n);
    eq(n);
    ans = rec(n);

    printf("\nUsing Recursion: Sum of 1 to %d = %d\n", n, ans);
    printf("Number of steps (Recursion): %d\n", count_rec);

    return 0;
}

void loop(int n) {
    int i, sum = 0;
    count_loop++;   // function entry

    for (i = 1; i <= n; i++) {
        count_loop++;       // loop condition
        sum = sum + i;
        count_loop++;       // addition step
    }

    printf("\nUsing Loop: Sum of 1 to %d = %d\n", n, sum);
    printf("Number of steps (Loop): %d\n", count_loop);
}

void eq(int n) {
    int sum;
    count_eq++;     // function entry

    sum = (n * (n + 1)) / 2;
    count_eq++;     // formula calculation

    printf("\nUsing Equation: Sum of 1 to %d = %d\n", n, sum);
    printf("Number of steps (Equation): %d\n", count_eq);
}

int rec(int n) {
    count_rec++;    // function call

    if (n == 0) {
        count_rec++;   // base condition
        return 0;
    } else {
        count_rec++;   // recursive case
        return n + rec(n - 1);
    }
}