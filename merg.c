#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int merge(int arr[], int l, int m, int r);
int merge_sorting(int arr[], int l, int r);
void print_array(int array_hai_yaar[], int size);
int main()
{
    int n;
    printf("\nenter your array size ");
    scanf("%d", &n);
    int arr[n];
    time_t t;
    srand((unsigned)time(&t));
    clock_t begin = clock();
    for (long long i = 0; i < n; i++)
    {
        arr[i] = 1LL * (0 + (1000 - 0)) * rand() / RAND_MAX;
    }
    int count = merge_sorting(arr, 0, n - 1);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The total number of comparisons in the heap sort is -> %d\n", count);
    printf("The execution time is -> %lf\n", time_spent);
    return 0;
}
int merge(int arr[], int l, int m, int r)
{
    int i, j, k, count = 0;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            count++;
            arr[k] = L[i];
            i++;
        }
        else
        {
            count++;
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return count;
}
int merge_sorting(int arr[], int l, int r)
{
    int count = 0;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        count += merge_sorting(arr, l, m);
        count += merge_sorting(arr, m + 1, r);
        count += merge(arr, l, m, r);
    }
    return count;
}
void print_array(int array_hai_yaar[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array_hai_yaar[i]);
}