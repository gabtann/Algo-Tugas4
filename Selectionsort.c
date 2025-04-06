#include <stdio.h>

// Fungsi untuk menukar dua elemen
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk mencetak array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Fungsi untuk mencetak array setelah setiap iterasi
void printIterasi(int arr[], int size, int iterasi) {
    printf("Proses %d: ", iterasi);
    printArray(arr, size);
}

// Fungsi selection sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Loop melalui semua elemen array
    for (i = 0; i < n - 1; i++) {
        // Temukan elemen minimum dalam subarray yang belum diurutkan
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Tukar elemen minimum yang ditemukan dengan elemen pertama
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }

        // Cetak array setelah setiap iterasi
        printIterasi(arr, n, i + 1);
    }
}

int main() {
    int arr[] = {32, 75, 69, 58, 21, 40, 64, 150, 138, 116, 42, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum sorting:\n");
    printArray(arr, n);

    printf("\nProses sorting:\n");
    selectionSort(arr, n);

    printf("\nArray setelah sorting:\n");
    printArray(arr, n);

    return 0;
}