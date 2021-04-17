#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void deleteFromBegining();

struct node {
  int data;
  struct node *nextNode;
};

struct node *start = NULL;

int main() {
  for (int i = 0; i < 5; i++) {
    create();
  }
  display();
  deleteFromBegining();
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
  printf("\n");
}

void deleteFromBegining() {
  if (start == NULL) {
    printf("LinkedList is empty. Nothing to delete.\n");
    return;
  } else {
    struct node *ptr;
    ptr = start;
    start = ptr->nextNode;
    printf("The deleted value is: %d\n", ptr->data);
    free(ptr);
  }
}
