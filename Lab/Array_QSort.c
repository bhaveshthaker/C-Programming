#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct pair {
  int x, y;
} pair_t;

int cmp(const void *p, const void *q) {
  const pair_t *pa = (const pair_t *)p;
  const pair_t *qb = (const pair_t *)q;
  return (pa->x - qb->x);
}

int main() {
  pair_t array[N];

  for (int i = 0; i < N; ++i) {
    array[i].x = (i % 3);
    array[i].y = i;
  }

  qsort(array, N, sizeof(pair_t), cmp);

  for (int i = 0; i < N; ++i) {
    printf("(%d, %d) ", array[i].x, array[i].y);
  }
  printf("\n");

  return 0;
}
