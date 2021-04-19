/*
Minimum Number of Terms in a Fibonacci Series
=============================================
Description
Now that you have learnt how to create a linked list and map the data part
of each node to each term of a Fibonacci series, write a program to find
the minimum number of terms in a Fibonacci series that add up to a given
number, say, N. This program should take a single positive integer, say, N,
as input, such that you need to find out the minimum number of terms in the
Fibonacci series that add up to N. You can use only those terms of the
Fibonacci series that are less than or equal to N. Therefore, the program
should generate a Fibonacci series whose terms are all less than or equal
to N. The program should then store each element of the series in a linked
list. You may use the code from the previous questions to create a linked
list and map its data part with each term of the Fibonacci series. You just
need to add a piece of code that helps you find the minimum number of terms
in this Fibonacci series that add up to N.

Note:
The Fibonacci numbers could be used multiple times to obtain the sum. And
it is guaranteed that you can always find such Fibonacci numbers, which add
up to N.

Example:
If the given number, N, is 75, then the Fibonacci series with each term
less than or equal to 75 would contain the integers 0, 1, 1, 2, 3, 5, 8,
13, 21, 34 and 55.
The minimum number of Fibonacci terms to give the number 75 would be equal
to 4 as 75 can be obtained as 55 + 13 + 5 + 2.

Input format:
The input contains a single positive integer (greater than 0) such that you
need to find out the minimum number of terms in the Fibonacci series that
add up to this integer. This integer also implies that you can use only
those terms of the series that are either less than or equal to it.
Output format:
The output contains a single positive integer, which represents the minimum
number of terms in the Fibonacci series that add up to the given input
integer.

Sample test case:
Input:
4
Output:
2

Explanation:
The input value, 4 in this case, implies that you need to find the minimum
number of terms in the Fibonacci series that add up to 4. This integer also
implies that you can use only those terms of the series that are either
less than or equal to 4. The complete Fibonacci series is 0 1 1 2 3 5 8
13…. However, since the last number to be generated in the series must be
less than or equal to the input, 4 in this case, the Fibonacci series is
generated only up to 3, i.e., 0 1 1 2 3. The numbers 5 8 13... are neither
less than nor equal to the input, 4 and, thus, they are not added to the
Fibonacci series in this case. The linked list is then created with five
nodes such that the data part of each node maps to each term of the
Fibonacci series, and the linked list created in this case would look like
this:
0-> 1-> 1-> 2-> 3
Since 4 can be obtained using 1 and 3 (1+3=4), the minimum number of terms
in this series that can be added to give the value 4 is 2. Therefore, 2 is
displayed as output.
*/
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int num;
  struct node *next;
};

struct node *createFibonacciLL(int);
void printFibonacciLL(struct node *);
struct node *reverseFibonacciLL(struct node *);
int findMinTermsFromFibonacciLL(struct node *, int);

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  // Note that you need to explicitly return 0 in main() function,
  // otherwise your solution won't get accepted
  int num, count;
  struct node *head;
  scanf("%d", &num);

  // Create a linked list of Fibonacci numbers
  head = createFibonacciLL(num);

  // Reverses the linked list of Fibonacci numbers
  head = reverseFibonacciLL(head);

  // Count the Minimum Number of Terms in a Fibonacci Series required for a
  // number
  count = findMinTermsFromFibonacciLL(head, num);
  printf("%d\n", count);

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

// Prints the Fibonacci numbers in the linked list
void printFibonacciLL(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->num);
    p = p->next;
  }
  printf("\n");
}

// Count the Minimum Number of Terms
int findMinTermsFromFibonacciLL(struct node *head, int k) {
  int count = 0;
  struct node *t;
  t = head;
  while (k > 0) {
    count += k / t->num;
    k %= t->num;
    t = t->next;
  }
  return count;
}
