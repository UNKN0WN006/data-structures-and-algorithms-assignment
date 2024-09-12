#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// a. Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printf("Pass %d: ", i);
        printArray(arr, n);
    }
}

// b. Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
        printf("Pass %d: ", i + 1);
        printArray(arr, n);
    }
}

// c. Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("Pass %d: ", i + 1);
        printArray(arr, n);
    }
}

// d. Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int size) {
    if (low < high) {
        int pi = partition(arr, low, high);
        printf("Pivot %d placed: ", arr[pi]);
        printArray(arr, size);
        quickSort(arr, low, pi - 1, size);
        quickSort(arr, pi + 1, high, size);
    }
}

// e. Merge Sort
void merge(int arr[], int l, int m, int r, int size) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
    printf("Merged: ");
    printArray(arr, size);
}

void mergeSort(int arr[], int l, int r, int size) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, size);
        mergeSort(arr, m + 1, r, size);
        merge(arr, l, m, r, size);
    }
}

// f. Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        printf("Heap Sort Pass: ");
        printArray(arr, n);
        heapify(arr, i, 0);
    }
}

// Main function
int main() {
    int choice, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        temp[i] = arr[i];  // To reset the array for each sorting algorithm
    }

    do {
        printf("\nMenu:\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Heap Sort\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];  // Reset array to original unsorted values
        }

        switch (choice) {
            case 1:
                printf("\nInsertion Sort:\n");
                insertionSort(arr, n);
                break;
            case 2:
                printf("\nSelection Sort:\n");
                selectionSort(arr, n);
                break;
            case 3:
                printf("\nBubble Sort:\n");
                bubbleSort(arr, n);
                break;
            case 4:
                printf("\nQuick Sort:\n");
                quickSort(arr, 0, n - 1, n);
                break;
            case 5:
                printf("\nMerge Sort:\n");
                mergeSort(arr, 0, n - 1, n);
                break;
            case 6:
                printf("\nHeap Sort:\n");
                heapSort(arr, n);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    free(arr);
    free(temp);
    return 0;
}