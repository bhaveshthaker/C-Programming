#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
};
struct node *start = NULL;
void push(int n);
int pop();
void display();
int main() {
  push(10);
  push(20);
  push(30);
  push(5);
  push(-1);
  push(55);
  push(18);
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());
}
void push(int n) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = n;
  temp->next = NULL;
  if (start == NULL) {
    start = temp;
  } else {
    temp->next = start;
    start = temp;
  }
}
int pop() {
  int temp;
  struct node *ptr;
  ptr = start;
  temp = ptr->data;
  start = start->next;
  free(ptr);
  return (temp);
}
