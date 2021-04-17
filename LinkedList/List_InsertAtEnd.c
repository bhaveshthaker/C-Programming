#include <stdio.h>
#include <stdlib.h>

void create();
void display();

struct node {
  int data;
  struct node *nextNode;
};

struct node *start = NULL;

int main() {
  create();
  create();
  create();
  create();
  display();
}

void create() {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL) {
    printf("Out of Memory Error. Exiting.\n");
    exit(1);
  }

  printf("Enter integer number to add: ");
  scanf("%d", &(temp->data));
  temp->nextNode = NULL;

  if (start == NULL) {
    start = temp;
  } else {
    struct node *ptr;
    ptr = start;
    while (ptr->nextNode != NULL) {
      ptr = ptr->nextNode;
    }
    ptr->nextNode = temp;
  }
}

void display() {
  if (start == NULL) {
    printf("The LinkedList is empty.\n");
    return;
  } else {
    struct node *ptr;
    ptr = start;
    printf("The list elements are:\t");
    while (ptr != NULL) {
      printf("%d\t", ptr->data);
      ptr = ptr->nextNode;
    }
  }
}
