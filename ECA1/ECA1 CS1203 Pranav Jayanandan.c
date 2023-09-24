#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int n) {
    int i, j, k, temp;
    int count = 1;
    int* arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        arr[i] = i + 1;
        count *= (i + 1);
    }

    for (i = 0; i < count; i++) {
        printf("%d", arr[0]);
        for (j = 1; j < n; j++) {
            printf(",%d", arr[j]);
        }
        printf("\n");

        // Find largest k such that a[k] < a[k+1]
        k = -1;
        for (j = n - 2; j >= 0; j--) {
            if (arr[j] < arr[j + 1]) {
                k = j;
                break;
            }
        }

        // If no index is found, all permutations are generated
        if (k == -1) break;

        // Find largest l such that a[k] < a[l]
        for (j = n - 1; j > k; j--) {
            if (arr[j] > arr[k]) {
                temp = arr[k];
                arr[k] = arr[j];
                arr[j] = temp;
                break;
            }
        }

        // Reverse the sequence from a[k+1] up to the final element a[n-1]
        for (j = k + 1; j < (n + k + 1) / 2; j++) {
            temp = arr[j];
            arr[j] = arr[n + k - j];
            arr[n + k - j] = temp;
        }
    }

    free(arr);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0 || n > 8) {
        printf("Invalid input. n must be between 1 and 8.\n");
        return 1;
    }

    permute(n);

    return 0;
}