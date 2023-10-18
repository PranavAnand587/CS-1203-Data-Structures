#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Here bubble sort has a time complexity of O(n^2) because
// It involves  two nested loops: the outer loop runs for n times(worst case)
// and inner loop runs for n times as well, so in total it runs n*n=n^2 times.
// Therefore, the time complexity of Bubble Sort will be O(n^2)

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Here Insertion Sort will have a time complexity of O(n^2)
// In the best-case scenario, when the array is already sorted, 
// the inner loop doesn't need to perform many comparisons and swaps.
// It performs just one comparison for each element and, in most cases,
// doesn't perform any swaps. This results in a time complexity of O(n).
// In worse case, scenario, 
//
// In the worst-case scenario for Insertion Sort, when the array is in reverse order, the algorithm will have to perform a significant number of comparisons and swaps for each element. Here's a breakdown of the time complexity analysis:
//
//     The outer loop runs for n iterations, where n is the number of elements in the array.
//
//     In the worst case, for each iteration of the outer loop, the inner while loop may perform j comparisons and j swaps, where j is the position of the element being considered.
//
//     In the first iteration of the outer loop (i = 1), the inner loop performs at most 1 comparison and 1 swap.
//         In the second iteration (i = 2), the inner loop may perform at most 2 comparisons and 2 swaps.
//         In the third iteration (i = 3), the inner loop may perform at most 3 comparisons and 3 swaps.
//         This pattern continues until the final iteration.
//
//     In the last iteration (i = n), the inner loop may perform at most (n-1) comparisons and (n-1) swaps.
//
// The sum of these comparisons and swaps, in the worst case, is roughly:
// 1 + 2 + 3 + ... + (n-1)
//
// This series is an arithmetic series with a sum of (n-1)(n)/2, which is equivalent to O(n^2).

int main() {
    int n = 10; // Size of the array
    int experimental_data[] = {1, 2, 45, 35, 23, 66, 7, 5, 99, 34};

    // Sort the array using Bubble Sort
    bubbleSort(experimental_data, n);
    printf("Sorted array using Bubble Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", experimental_data[i]);
    }
    printf("\n");

    // Reset the array
    
    // Sort the array using Insertion Sort
    insertionSort(experimental_data, n);
    printf("Sorted array using Insertion Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", experimental_data[i]);
    }
    printf("\n");

    return 0;
}
