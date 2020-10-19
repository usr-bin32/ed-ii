#include <cstdlib>

template <typename T>
void merge(T *arr, size_t start, size_t middle, size_t end) {
    T *aux = new T[end - start + 1];

    size_t i = start, j = middle + 1, k = 0;
    while (i <= middle && j <= end) {
        if (arr[i] <= arr[j]) {
            aux[k] = arr[i];
            i++;
        } else {
            aux[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= middle) {
        aux[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end) {
        aux[k] = arr[j];
        j++;
        k++;
    }

    for (k = 0; k < end - start + 1; k++) {
        arr[start + k] = aux[k];
    }

    delete[] aux;
}

template <typename T>
void merge_sort(T *arr, size_t start, size_t end) {
    if (start < end) {
        size_t middle = (start + end) / 2;

        merge_sort(arr, start, middle);
        merge_sort(arr, middle + 1, end);

        merge(arr, start, middle, end);
    }
}

template <typename T>
void merge_sort(T *arr, size_t size) {
    merge_sort(arr, 0, size - 1);
}
