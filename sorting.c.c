#include <stdio.h> 
#include <stdlib.h> 
 
// Function to print array 
void printArray(int arr[], int n) { 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
 
// 1. Bubble Sort 
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
    } 
} 
 
// 2. Insertion Sort 
void insertionSort(int arr[], int n) { 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j--; 
        } 
        arr[j + 1] = key; 
    } 
} 
 
// 3.Quick Sort 
int partition(int arr[], int low, int high) { 
    int pivot = arr[high]; 
    int i = (low - 1), temp; 
    for (int j = low; j < high; j++) { 
        if (arr[j] < pivot) { 
            i++; 
            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp; 
        } 
    } 
    temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp; 
    return (i + 1); 
} 
 
void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
 
// 4. Merge Sort 
void merge(int arr[], int l, int m, int r) { 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int L[n1], R[n2]; 
 
    for (int i = 0; i < n1; i++) L[i] = arr[l + i]; 
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j]; 
 
    int i = 0, j = 0, k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) arr[k++] = L[i++]; 
        else arr[k++] = R[j++]; 
    } 
    while (i < n1) arr[k++] = L[i++]; 
    while (j < n2) arr[k++] = R[j++]; 
} 
 
void mergeSort(int arr[], int l, int r) { 
    if (l < r) { 
        int m = (l + r) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
} 
 
// 5.Radix Sort (for positive integers) 
int getMax(int arr[], int n) { 
    int max = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > max) max = arr[i]; 
    return max; 
} 
 
void countingSort(int arr[], int n, int exp) { 
    int output[n]; 
    int count[10] = {0}; 
 
    for (int i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
 
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
 
    for (int i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 
 
    for (int i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
 
void radixSort(int arr[], int n) { 
    int m = getMax(arr, n); 
    for (int exp = 1; m / exp > 0; exp *= 10) 
        countingSort(arr, n, exp); 
} 
 
// 6. Heap Sort 
void heapify(int arr[], int n, int i) { 
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] > arr[largest]) largest = l; 
    if (r < n && arr[r] > arr[largest]) largest = r; 
 
    if (largest != i) { 
        int temp = arr[i]; arr[i] = arr[largest]; arr[largest] = temp; 
        heapify(arr, n, largest); 
    } 
} 
 
void heapSort(int arr[], int n) { 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
    for (int i = n - 1; i > 0; i--) { 
        int temp = arr[0]; arr[0] = arr[i]; arr[i] = temp; 
        heapify(arr, i, 0); 
    } 
} 
 
// Main 
int main() { 
    int arr[100], n, choice; 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    printf("Enter elements: "); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    printf("\nSorting Techniques:\n"); 
    printf("1. Bubble Sort\n2. Insertion Sort\n3. Quick Sort\n4. Merge Sort\n5. Radix Sort\n6. 
Heap Sort\n"); 
    printf("Enter your choice: "); 
    scanf("%d", &choice); 
 
    switch (choice) { 
        case 1: bubbleSort(arr, n); break; 
        case 2: insertionSort(arr, n); break; 
        case 3: quickSort(arr, 0, n - 1); break; 
        case 4: mergeSort(arr, 0, n - 1); break; 
        case 5: radixSort(arr, n); break; 
        case 6: heapSort(arr, n); break; 
        default: printf("Invalid choice!\n"); return 0; 
    } 
 
    printf("\nSorted Array: "); 
    printArray(arr, n); 
 
    return 0; 
}