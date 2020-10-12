#include <cstdlib>
/**
 * Implementção do Algoritmo escolhido para fazer a ordenacao
**/
template <typename T>
void shell_sort(T *arr,  size_t size) 
{ 
    size_t i, j, h = 1;
    T aux;

    do { h = h * 3 + 1; } while (h < size); // calcula o tamanho do salto h inicial
                                       
    do
    {
        h /= 3;  // atualiza o valor de h.
        for(i = h ; i < size ; i++) 
        {
            aux = arr[i];
            j = i;

            //efetua comparações entre elementos com distância h:
            while (arr[j - h] > aux) 
            {
                arr[j] = arr[j - h];
                j -= h;

                if (j < h) break;
            }
            arr[j] = aux;
        }
    } while (h != 1);

};