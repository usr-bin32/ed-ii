#include <cstdlib>

template <typename T>
int slice(T *arr, int first, int end, int &comparisons, int &swaps) {
    int n = (end + first);
    T pivot = arr[n / 2];

    int i = first - 1, j = end + 1;

    do {
        do {
            i++;
            comparisons++;
        } while (arr[i] < pivot);

        do {
            j--;
            comparisons++;
        } while (arr[j] > pivot);

        if (i < j) {
            T aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            swaps++;
        }
    } while (i < j);
    return j;
}

template <typename T>
void quick_sort(T *arr, int first, int end, int &comparisons, int &swaps) {
    if (first < end) {
        int s = slice(arr, first, end, comparisons, swaps);
        quick_sort(arr, first, s, comparisons, swaps);
        quick_sort(arr, s + 1, end, comparisons, swaps);
    }
}

template<typename T>
void quick_sort(T *arr, size_t size, int &comparisons, int &swaps) {
    comparisons = 0;
    swaps = 0;
    quick_sort(arr, 0, size - 1, comparisons, swaps);
}
