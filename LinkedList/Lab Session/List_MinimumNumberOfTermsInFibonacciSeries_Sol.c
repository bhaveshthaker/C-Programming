#include <stdio.h>
#include <stdlib.h>

struct node {
  int num;
  struct node *next;
};

struct node *createFibonacciLL(int);
struct node *reverseFibonacciLL(struct node *);
int findMinFibonacciNumbers(struct node *, int);

int main() {
  int num, n;
  struct node *head;
  scanf("%d", &num);

  // Create a linked list of Fibonacci numbers
  head = createFibonacciLL(num);

  head = reverseFibonacciLL(head);

  // Find the minimum Fibonacci numbers that sum to num
  n = findMinFibonacciNumbers(head, num);
  printf("%d\n", n);

  return 0;
}

struct node *createFibonacciLL(int k) {
  struct node *p, *head;
  int old = 0, newer = 1;
  head = NULL;

  p = (struct node *)malloc(sizeof(struct node));
  p->num = old;
  p->next = NULL;
  head = p;

  p = (struct node *)malloc(sizeof(struct node));
  p->num = newer;
  p->next = NULL;
  head->next = p;

  int newterm = 1;
  while (newterm <= k) {
    newterm = old + newer;
    if (newterm > k)
      break;

    p->next = (struct node *)malloc(sizeof(struct node));
    p = p->next;
    p->num = newterm;
    p->next = NULL;
    old = newer;
    newer = newterm;
  }

  return head;
}

// Reverses the linked list of Fibonacci numbers
struct node *reverseFibonacciLL(struct node *head) {
  struct node *t, *r, *prev;
  t = head;
  prev = NULL;
  r = NULL;
  while (t != NULL) {
    r = prev;
    prev = t;
    t = t->next;
    prev->next = r;
  }
  return prev;
}

// Finds the minimum Fibonacci numbers that sum to num
int findMinFibonacciNumbers(struct node *head, int k) {
  struct node *p;
  int count;

  count = 0;
  p = head;
  while (p != NULL) {
    if (k == 0)
      break;

    if (p->num <= k) {
      k = k - p->num;
      count++;
    }
    p = p->next;
  }
  return count;
}
