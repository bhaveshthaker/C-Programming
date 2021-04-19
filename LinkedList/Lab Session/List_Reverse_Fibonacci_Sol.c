#include <stdio.h>
#include <stdlib.h>

struct node {
  int num;
  struct node *next;
};

struct node *createFibonacciLL(int);
void printFibonacciLL(struct node *);
struct node *reverseFibonacciLL(struct node *);

int main() {
  int num;
  struct node *head;
  scanf("%d", &num);

  // Create a linked list of Fibonacci numbers
  head = createFibonacciLL(num);

  // Reverses the linked list of Fibonacci numbers
  head = reverseFibonacciLL(head);
  printFibonacciLL(head);

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

// Prints the Fibonacci numbers in the linked list
void printFibonacciLL(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->num);
    p = p->next;
  }
  printf("\n");
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
