#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int heapify(int arr[], int n, int i);
void print_array(int arr[], int n);
int heap_sorting(int arr[], int n); // main function heap sorting ke liye
int main()
{
    int n;
    printf("\nenter your numbers of elements  ");
    scanf("%d", &n);
    int arr[n];
    time_t t;
    srand((unsigned)time(&t));
    clock_t begin = clock();
    for (long long i = 0; i < n; i++)
    {
        arr[i] = 1LL * (0 + (1000 - 0)) * rand() / RAND_MAX;
    }
    int count = heap_sorting(arr, n);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("total number of comparision is  -> %d\n", count);
    // printf("total execution time is  -> %lf\n", time_spent);
}
int heapify(int arr[], int n, int i)
{
    int count = 0;
    int largest = i;   // this is thge largest one
    int l = 2 * i + 1; // left ke liye  2*i + 1
    int r = 2 * i + 2; // right ke liye  2*i + 2

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        count += 1;
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        count += heapify(arr, n, largest); // resursely heapify the tree sub
    }
    return count;
}
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; ++i) // function to print the array accredited to user
        printf("%d ", arr[i]);
    printf("  ");
}
int heap_sorting(int arr[], int n)
{
    int count = 0;
    for (int i = n / 2 - 1; i >= 0; i--) // for re making of the array
        count += heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0]; // moving current root to the end
        arr[0] = arr[i];
        arr[i] = temp;
        count += heapify(arr, i, 0);
    }
    return count;
}