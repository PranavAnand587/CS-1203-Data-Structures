#include <stdio.h>

// Merge two subarrays of arr[]
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    // Merge the temp arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray

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

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

// Here Merge Sort will have a time complexity of O(nlog(n))
//     Merge Sort is a divide-and-conquer algorithm that divides the input array into two equal halves and recursively sorts them.
    // The divide step continues until the array is divided into subarrays with a single element.
    // The conquer step involves merging these subarrays in a sorted manner.
    // The merge step, which combines two sorted subarrays, takes O(n) time, where 'n' is the total number of elements in the two subarrays.
    // The divide step occurs in a binary fashion, with each division halving the size of the subproblems. This binary division results in log₂(n) levels of recursion.
    // At each level of recursion, all 'n' elements need to be merged.
// So at the end it becomes O(n*log(n)), where log(n) represents the number of levels of recursion
// And this happened n times as n represents the total number of elements in array

// Function to partition the array and return the pivot index
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

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Here quick sort will have a time complexity of O(nlogn)
// It divides the input array into smaller subarrays and sorting them 
// independently through a pivot element. The pivot selection, on average, 
// leads to balanced partitioning, where subarrays are divided into roughly
// equal sizes. This results in a logarithmic depth of recursion,
// specifically log₂(n) levels, and a linear time partitioning step
// (O(n) at each level. The combination of these factors results in the
// O(n log n) time complexity 

// Heapify the subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

// Here the time complexity of Heap Sort is  O(nlogn) also
// This algorithm involves two main phases. First, it constructs
// a max-heap in linear time (O(n)), arranging the elements to 
// satisfy the heap property. Second, it repeatedly extracts the
// maximum element (root of the heap) and restores the heap structure,
// which is a logarithmic operation (O(log n). This extraction and 
// restoration process occurs for each element, and because the 
// height of the heap is logarithmic, the overall time complexity is O(n log n),

int main() {
    int experimental_data[] = {1, 2, 45, 35, 23, 66, 7, 5, 99, 34};
    int n = sizeof(experimental_data) / sizeof(experimental_data[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", experimental_data[i]);
    }
    printf("\n");

    // Merge Sort
    mergeSort(experimental_data, 0, n - 1);
    printf("Sorted array using Merge Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", experimental_data[i]);
    }
    printf("\n");

    // Quick Sort
    quickSort(experimental_data, 0, n - 1);
    printf("Sorted array using Quick Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", experimental_data[i]);
    }
    printf("\n");

    // Heap Sort
    heapSort(experimental_data, n);
    printf("Sorted array using Heap Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", experimental_data[i]);
    }
    printf("\n");

    return 0;
}

