#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int array[], int size)
{
    for(int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;

        while(j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main()
{
    clock_t start_random,end_random;
    clock_t start_sorted,end_sorted;
    clock_t start_desc,end_desc;
    double time_taken_random,time_taken_sorted,time_taken_desc;

    int random[10000], sorted[10000], desc[10000], n;

    printf("Insertion Sort\n");
    printf("Enter Size of Array:");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        sorted[i]=i;

    for(int i=0;i<n;i++)
        random[i]=rand()%1000;

    for(int i=n;i<0;i--)
        desc[i]=i;

    start_random = clock();
    insertionSort(random, n-1);
    end_random = clock();
    time_taken_random = ((double)(end_random-start_random))/CLOCKS_PER_SEC;

    start_sorted = clock();
    insertionSort(sorted, n-1);
    end_sorted = clock();
    time_taken_sorted = ((double)(end_sorted-start_sorted))/CLOCKS_PER_SEC;

    start_desc = clock();
    insertionSort(desc, n-1);
    end_desc = clock();
    time_taken_desc = ((double)(end_desc-start_desc))/CLOCKS_PER_SEC;

    printf("\nRandom Array Time : %lf\n",time_taken_random);
    printf("Sorted Array Time : %lf\n",time_taken_sorted);
    printf("Descending Array Time : %lf\n",time_taken_desc);

    return 0;
}