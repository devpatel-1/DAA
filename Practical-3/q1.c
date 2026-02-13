#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to swap two numbers */
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* Selection Sort Function */
void selectionSort(int array[], int size)
{
    int i, j, min_idx;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;

        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
            {
                min_idx = j;
            }
        }

        swap(&array[min_idx], &array[i]);
    }
}

int main()
{
    int n;
    int random[10000], sorted[10000], desc[10000];
    clock_t start, end;
    double time_random, time_sorted, time_desc;

    printf("Selection Sort\n");
    printf("Enter Size of Array: ");
    scanf("%d", &n);

    /* Creating Sorted (Ascending) Array */
    for (int i = 0; i < n; i++)
    {
        sorted[i] = i;
    }

    /* Creating Random Array */
    for (int i = 0; i < n; i++)
    {
        random[i] = rand() % 1000;
    }

    /* Creating Descending Array */
    for (int i = 0; i < n; i++)
    {
        desc[i] = n - i;
    }

    /* Time for Random Array */
    start = clock();
    selectionSort(random, n);
    end = clock();
    time_random = (double)(end - start) / CLOCKS_PER_SEC;

    /* Time for Sorted Array */
    start = clock();
    selectionSort(sorted, n);
    end = clock();
    time_sorted = (double)(end - start) / CLOCKS_PER_SEC;

    /* Time for Descending Array */
    start = clock();
    selectionSort(desc, n);
    end = clock();
    time_desc = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nTime Taken:\n");
    printf("Random Array      : %lf seconds\n", time_random);
    printf("Sorted Array      : %lf seconds\n", time_sorted);
    printf("Descending Array  : %lf seconds\n", time_desc);

    return 0;
}
