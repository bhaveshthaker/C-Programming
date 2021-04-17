#include <stdio.h>
#include <stdlib.h>
struct node {
  int rank;
  struct node *next;
};
struct node *start = NULL;
void insert(int n);
void display();
int main() {
  int n, temp, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &temp);
    insert(temp);
  }
  display();
  return 0;
}
void insert(int n) {
  struct node *ptr;
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->rank = n;
  temp->next = NULL;
  if (start == NULL) {
    start = temp;
  } else {
    ptr = start;
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
}
void display() {
  struct node *ptr;
  ptr = start;
  while (ptr != NULL) {
    printf("%d ", ptr->rank);
    ptr = ptr->next;
  }
}
