#include <cstdlib>
#include "slice.h"
template <typename T>
void quick_sort(T *arr, int first, int end, int &comparisonsCounter, int &changesCounter)
{
  if (first < end)
  {
    std::cout << "Antes Slice" << std::endl;
    int s = slice(arr, first, end, comparisonsCounter, changesCounter);
    std::cout << s << std::endl;
    quick_sort(arr, first, s, comparisonsCounter, changesCounter);
    quick_sort(arr, s + 1, end, comparisonsCounter, changesCounter);
  }
};