#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int array[], int size)
{
    for(int step = 0; step < size - 1; step++)
    {
        for(int i = 0; i < size - step - 1; i++)
        {
            if(array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

int main()
{
    clock_t start_random,end_random;
    clock_t start_sorted,end_sorted;
    clock_t start_desc,end_desc;
    double time_taken_random,time_taken_sorted,time_taken_desc;

    int random[10000], sorted[10000], desc[10000], n;

    printf("Bubble Sort\n");
    printf("Enter Size of Array:");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        sorted[i]=i;

    for(int i=0;i<n;i++)
        random[i]=rand()%1000;

    for(int i=n;i<0;i--)
        desc[i]=i;

    start_random = clock();
    bubbleSort(random, n-1);
    end_random = clock();
    time_taken_random = ((double)(end_random-start_random))/CLOCKS_PER_SEC;

    start_sorted = clock();
    bubbleSort(sorted, n-1);
    end_sorted = clock();
    time_taken_sorted = ((double)(end_sorted-start_sorted))/CLOCKS_PER_SEC;

    start_desc = clock();
    bubbleSort(desc, n-1);
    end_desc = clock();
    time_taken_desc = ((double)(end_desc-start_desc))/CLOCKS_PER_SEC;

    printf("\nRandom Array Time : %lf\n",time_taken_random);
    printf("Sorted Array Time : %lf\n",time_taken_sorted);
    printf("Descending Array Time : %lf\n",time_taken_desc);

    return 0;
}