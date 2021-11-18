#include <iostream>
using namespace std;

void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quicksort(int **a, int rows, int cols);
void print_matrix(int **matrix, int rows, int cols);
void quicksort_r(int **a, int l, int r, int c);

// Driver Code
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    print_matrix(arr, n);
    return 0;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int **a, int l, int r, int c) {
    int i;
    // Left pivot
    int pivot_val = a[l/c][l%c];
    // Move pivot to end
    swap(&a[l/c][l%c], &a[r/c][r%c]);

    // If <= to the pivot value, swap
    int j = l;
    for (i = l; i < r; i++) {
        if (a[i/c][i%c] <= pivot_val) {
            swap(&a[i/c][i%c], &a[j/c][j%c]);
            j++;
        }
    }

    // Move pivot to its place.
    swap(&a[j/c][j%c], &a[r/c][r%c]);

    return j;
}

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quicksort(int **a, int rows, int cols) {
    quicksort_r(a, 0, rows * cols - 1, cols);
}

void quicksort_r(int **a, int l, int r, int c) {
    if (l < r) {
        int pivot = partition(a, l, r, c);
        quicksort_r(a, l, pivot-1, c);
        quicksort_r(a, pivot+1, r, c);
    }
}

/* Function to print an array */
void print_matrix(int **matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
