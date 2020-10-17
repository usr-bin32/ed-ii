#include <cstdlib>
/**
 * Implementção do Algoritmo escolhido para fazer a ordenacao
**/
template <typename T>
void shell_sort(T *arr,  size_t size, int &comparisonsCounter, int &changesCounter) 
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
                comparisonsCounter++;

                arr[j] = arr[j - h];
                changesCounter++;
                j -= h;

                if (j < h) break;
            }
            comparisonsCounter++;
            
            arr[j] = aux;
            changesCounter++;
        }
    } while (h != 1);

};