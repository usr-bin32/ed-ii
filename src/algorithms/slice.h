#include <cstdlib>

template <typename T>
int slice(T *arr, int first, int end)
{
  T aux;
  int count = first-1;

  for (int i = first; i <= end - 1; i++)
  {
    if (arr[i] < arr[first])
    {
      count++;
      aux = arr[i];
      arr[i] = arr[count];
      arr[first] = aux;
    }
  }
  aux = arr[first];
  arr[first] = arr[count];
  arr[count] = aux;
  return count;
};


