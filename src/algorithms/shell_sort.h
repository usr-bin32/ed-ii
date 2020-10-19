#include <cstdlib>

/**
 * Implementção do Algoritmo escolhido para fazer a ordenacao
**/
template <typename T>
void shell_sort(T *arr, size_t size, int &comparisons, int &swaps) {
    comparisons = 0;
    swaps = 0;

    size_t i, j, h = 1;
    T aux;

    // calcula o tamanho do salto h inicial
    do {
        h = h * 3 + 1;
    } while (h < size);

    do {
        // atualiza o valor de h.
        h /= 3;
        for (i = h; i < size; i++) {
            aux = arr[i];
            j = i;

            // efetua comparações entre elementos com distância h:
            while (arr[j - h] > aux) {
                comparisons++;
                arr[j] = arr[j - h];
                swaps++;
                j -= h;

                if (j < h) {
                    comparisons--;
                    break;
                }
            }
            comparisons++;

            arr[j] = aux;
            swaps++;
        }
    } while (h != 1);
}
