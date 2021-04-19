#include <stdio.h>
#include <stdlib.h>

int binarysearch(int a[], int size, int key);
int comp(const void *x, const void *y);

int main() {
  int num, i, pos, key;

  scanf("%d", &num);
  int arr[num];

  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);

  scanf("%d", &key);
  qsort(arr, num, sizeof(int), comp);

  // Printing the sorted array
  for (i = 0; i < num; i++)
    printf("%d ", arr[i]);
  printf("\n");

  // Perform binary search
  pos = binarysearch(arr, num, key);
  if (pos == -1)
    printf("Number not found in array\n");
  else
    printf("%d\n", pos);

  return 0;
}

// Comparison function for qsort( )
int comp(const void *x, const void *y) {
  int *xx, *yy;
  xx = (int *)x;
  yy = (int *)y;
  return (*xx - *yy);
}

// Binary search
int binarysearch(int a[], int size, int key) {
  int lower, upper, mid;

  lower = 0;
  upper = size;

  while (lower <= upper) {
    mid = (lower + upper) / 2;
    if (key == a[mid])
      return mid;
    if (key > a[mid])
      lower = mid + 1;
    if (key < a[mid])
      upper = mid - 1;
  }

  return -1;
}
