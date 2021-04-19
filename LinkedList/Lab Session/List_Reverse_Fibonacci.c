/*
Reverse a Linked List
=====================
Description
In a Fibonacci series, each new term is obtained by adding the two previous
terms of the same series. The first two terms in the series are 0 and 1.
The third term is obtained by adding the first and the second term, which
gives 1 (0+1). The fourth term in the series is obtained by adding the
second and the third term, which gives 2 (1+1), and so on.
Fibonacci series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55...
A linked list is a data structure that can grow or shrink dynamically. Each
node in a linked list contains a data part and a link part. Write a
program, which creates a linked list such that the data part of each node
in the linked list stores each term of the above Fibonacci series.
Since the Fibonacci series given above is an infinite series, there should
be a bound to it. The program should take a single positive integer as
input from the user, such that all the terms of the Fibonacci series are
less than or equal to this integer. For instance, if a user enters 13 as an
input, then the Fibonacci series would look like this:
0, 1, 1, 2, 3, 5, 8, 13
Each term of this series should now be stored in the linked list as its
data part. The linked list created in this case would look like this:
Original Linked List: 0-> 1-> 1-> 2-> 3-> 5-> 8-> 13
After the linked list is created with the value of each node mapped to each
term of the Fibonacci series, the program should then reverse the linked
list. Hence, the linked list would look like this after reversal:
Reversed Linked List: 13-> 8-> 5-> 3-> 2-> 1-> 1-> 0
The program should then traverse the linked list from the beginning to the
end, and print the value of each node of the reversed linked list.
Note that the first two terms of a Fibonacci series are 0 and 1.
You may use the code from the previous question to create a linked list and
then map its data part with each term of the Fibonacci series. You just
need to add a piece of code that reverses the original linked list, and
then print all the nodes in that reversed linked list, traversing from the
beginning to the end.

Input format:
The input contains a single positive integer (greater than 0) such that all
the terms of the Fibonacci series are less than or equal to this integer.
Output format:
The output consists of N space-separated elements of the reversed linked
list, when the reversed linked list is traversed from the beginning to the
end.

Sample test case:
Input:
4
Output:
3 2 1 1 0

Explanation:
The input value, 4 in this case, indicates that the last term in the
Fibonacci series should be less than or equal to 4. Hence, the generated
Fibonacci series would look like this:
0 1 1 2 3
The original linked list is created with five nodes, such that the data
part of each node maps to each term of the Fibonacci series, and the
original linked list created in this case would look like this:
0-> 1-> 1-> 2-> 3
The original linked list is reversed, and, therefore, the reversed linked
list would look like this:
3-> 2-> 1-> 1-> 0
The reversed linked list is then traversed from the beginning to the end,
and you get the following output:
3 2 1 1 0
 */
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateFibonacciSeries(int num);
// bool isMemoryAllocated(struct node *temp);
void display();
void reverse();

struct node {
  int data;
  struct node *nextNode;
};

struct node *fibonacciSeries = NULL;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  // Note that you need to explicitly return 0 in main() function,
  // otherwise your solution won't get accepted
  int num;

  scanf("%d", &num);

  generateFibonacciSeries(num);
  reverse();
  display();
  return 0;
}

void generateFibonacciSeries(int num) {

  int a, b, c;
  a = 0, b = 1;

  if (fibonacciSeries == NULL) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 0;
    temp->nextNode = NULL;
    fibonacciSeries = temp;
    temp = NULL;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 1;
    temp->nextNode = NULL;
    fibonacciSeries->nextNode = temp;
  }

  while (true) {
    c = a + b;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = c;
    temp->nextNode = NULL;

    struct node *ptr;
    ptr = fibonacciSeries;
    while (ptr->nextNode != NULL) {
      ptr = ptr->nextNode;
    }
    if (c <= num) {
      ptr->nextNode = temp;
    } else {
      break;
    }

    a = b;
    b = c;
  }
}

/*
bool isMemoryAllocated(struct node *temp) {
  if (temp == NULL) {
    printf("Out of Memory Error. Exiting.\n");
    return false;
  } else {
    return true;
  }
}
*/

void display() {
  if (fibonacciSeries == NULL) {
    printf("The LinkedList is empty.\n");
    return;
  } else {
    struct node *ptr;
    ptr = fibonacciSeries;
    while (ptr != NULL) {
      printf("%d ", ptr->data);
      ptr = ptr->nextNode;
    }
  }
}

void reverse() {
  struct node *prev = NULL;
  struct node *current = fibonacciSeries;
  struct node *next;
  while (current != NULL) {
    next = current->nextNode;
    current->nextNode = prev;
    prev = current;
    current = next;
  }
  fibonacciSeries = prev;
}
