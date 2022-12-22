#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void quick_sort(int[], int, int, int *);
int partition(int[], int, int, int *);

int main()
{
    int n, count = 0;
    printf("\nhow much number of elements u want to generate : ");
    scanf("%d", &n);
    int list[n];
    int i;
    time_t t;
    srand((unsigned)time(&t));
    clock_t begin = clock();
    for (i = 0; i < n; i++)
    {
        list[i] = 1LL * (0 + (1000 - 0)) * rand() / RAND_MAX;
    }
    quick_sort(list, 0, n - 1, &count);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("total number of comparision is  -> %d\n", count);
    printf("The execution time is -> %lf\n", time_spent);
    return 0;
}

void quick_sort(int list[], int low, int high, int *count)
{
    int pivot;
    if (low < high)
    {
        pivot = partition(list, low, high, count);
        quick_sort(list, low, pivot - 1, count);
        quick_sort(list, pivot + 1, high, count);
    }
}

int partition(int list[], int low, int high, int *count)
{
    int left, right, temp, pivot_item;
    pivot_item = list[low];
    left = low;
    right = high;
    while (left < right)
    {
        while (list[left] <= pivot_item)
            (*count)++, left++;
        while (list[right] > pivot_item)
            (*count)++, right--;
        if (left < right)
        {
            temp = list[left];
            list[left] = list[right];
            list[right] = temp;
        }
    }
    list[low] = list[right];
    list[right] = pivot_item;
    return right;
}