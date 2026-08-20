#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++)
        for(j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void insertionSort(int arr[], int n) {
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int temp[100];
    int i = l, j = m + 1, k = 0;

    while(i <= m && j <= r) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= m)
        temp[k++] = arr[i++];

    while(j <= r)
        temp[k++] = arr[j++];

    for(i = l, k = 0; i <= r; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[100], n, choice, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\n1. Bubble Sort\n2. Insertion Sort\n3. Merge Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        bubbleSort(arr, n);
    else if(choice == 2)
        insertionSort(arr, n);
    else if(choice == 3)
        mergeSort(arr, 0, n - 1);
    else {
        printf("Invalid Choice");
        return 0;
    }

    printf("Sorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}