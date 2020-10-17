#include <cstdlib>

template <typename T>
int slice(T *arr, int first, int end, int &comparisonsCounter, int &changesCounter)
{
  int n = (end + first);
  T pivo = arr[n / 2];

  int i = first - 1, j = end + 1;

  do
  {
    do
    {
      i++;
      comparisonsCounter++ ;
    } while (arr[i] < pivo);

    do
    {
      j--;
      comparisonsCounter++ ;
    } while (arr[j] > pivo);

    if (i <= j)
    {
      T aux = arr[i];
      arr[i] = arr[j];
      arr[j] = aux;
      changesCounter++ ;
      i = i + 1;
      j = j - 1;
    }
  } while (i < j);
  return j;
};
