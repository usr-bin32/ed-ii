#include <cstdlib>
#include "slice.h"
template <typename T>
void quick_sort(T *arr, int first, int end)
{
  if (first < end)
  {
    int s = slice(arr, first, end);
    quick_sort(arr, first, s - 1);
    quick_sort(arr, s + 1, end);
  }
};