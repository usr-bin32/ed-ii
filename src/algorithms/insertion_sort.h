#include <cstdlib>

template <typename T>
void insertion_sort(T *arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        int j = i + 1;
        T pivot = arr[j];

        while (j > 0 && pivot < arr[j - 1]) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = pivot;
    }
}
