
#include "bar.h"

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void sort(int * v, int size) {
  qsort (v, size, sizeof(int), compare);
}