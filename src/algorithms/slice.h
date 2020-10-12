#include <cstdlib>

template <typename T>
int slice(T *arr, int first, int end)
{
  int n = (end + first);
  T pivo = arr[n / 2];

  int i = first - 1, j = end + 1;

  do
  {
    do
    {
      i++;
    } while (arr[i] < pivo);

    do
    {
      j--;
    } while (arr[j] > pivo);

    if (i <= j)
    {
      T aux = arr[i];
      arr[i] = arr[j];
      arr[j] = aux;
    }
  } while (i < j);
  return j;
};
