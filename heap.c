
#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* Max Heap */
void maxHeapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        maxHeapify(a, n, largest);
    }
}

/* Min Heap */
void minHeapify(int a[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] < a[smallest])
        smallest = l;

    if (r < n && a[r] < a[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(&a[i], &a[smallest]);
        minHeapify(a, n, smallest);
    }
}

/* Max Heap Sort - Ascending */
void maxHeapSort(int a[], int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);

    for (i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        maxHeapify(a, i, 0);
    }
}

/* Min Heap Sort - Descending */
void minHeapSort(int a[], int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        minHeapify(a, n, i);

    for (i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        minHeapify(a, i, 0);
    }
}

void display(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int a[100], n, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n1. Max Heap Sort");
    printf("\n2. Min Heap Sort");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        maxHeapSort(a, n);
        printf("\nMax Heap Sort (Ascending): ");
        display(a, n);
    }
    else if (choice == 2)
    {
        minHeapSort(a, n);
        printf("\nMin Heap Sort (Descending): ");
        display(a, n);
    }
    else
    {
        printf("\nInvalid choice");
    }

    return 0;
}
