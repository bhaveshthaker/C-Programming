/*
Stack as a Linked List

Description
The stack data structure is a Last In, First Out list, i.e., the element that
is entered last to a stack is the first one that is taken out from it. Write a
program to maintain a stack of integers. Use a Linked List to store the
integers in the stack. Make a provision to perform the following two operations
on the stack: push a new item to the top of stack and pop an existing item from
the top of the stack.
Push the following data into the stack in the same order using the function
push, such that 10 is at the bottom of the stack and 18 is at the top.
10
20
30
5
-1
55
18
Now implement the pop function to pop the top three elements from the stack.
The program should display as output the three elements that have been popped
from the stack.

Hint:
Create a stack using a Linked List. Whenever a new element is pushed into the
stack, add an element at the beginning of the Linked List, and whenever an
element is popped from the stack, remove an element from the beginning of the
Linked List. Note that while popping, node removal should take place from
memory.

Input Format:
No Input

Output Format:
The output consists of three integers, one on each line. These integers
correspond to the three values that have been popped from the final stack. The
first value in the output is the first element that has been popped from the
stack, the second value in the output is the second element that has been
popped from the stack, and so on.

Sample test cases:

Input:
No Input

Output:
18
55
-1
*/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push();
void pop();
void display();

struct myStack {
  int data;
  struct myStack *nextStackNode;
};

struct myStack *theStackList = NULL;

int main() {
  push(10);
  push(20);
  push(30);
  push(5);
  push(-1);
  push(55);
  push(18);
  pop();
  pop();
  pop();
  return 0;
}

void push(int value) {
  struct myStack *temp = (struct myStack *)malloc(sizeof(struct myStack));

  if (temp == NULL) {
    printf("Out of Memory Error. Exiting.\n");
    exit(1);
  }
  temp->data = value;
  temp->nextStackNode = NULL;

  if (theStackList == NULL) {
    theStackList = temp;
  } else {
    struct myStack *ptr = NULL;
    ptr = theStackList;
    while (ptr->nextStackNode != NULL) {
      ptr = ptr->nextStackNode;
    }
    ptr->nextStackNode = temp;
  }
}

void pop() {
  if (theStackList == NULL) {
    printf("List is Empty. Nothing to remove.");
    return;
  }
  struct myStack *ptr, *secondLast;
  ptr = theStackList;
  while (ptr->nextStackNode != NULL) {
    secondLast = ptr;
    ptr = ptr->nextStackNode;
  }
  secondLast->nextStackNode = NULL;
  printf("%d\n", ptr->data);
}

void display() {
  if (theStackList == NULL) {
    printf("The LinkedList is empty.\n");
    return;
  } else {
    struct myStack *ptr;
    ptr = theStackList;
    while (ptr != NULL) {
      printf("%d ", ptr->data);
      ptr = ptr->nextStackNode;
    }
  }
}
