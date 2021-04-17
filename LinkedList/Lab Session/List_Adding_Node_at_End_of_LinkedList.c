/*
Adding a Node at the End of a Linked List
Description
Let’s say you are a teacher and you want to keep a record of the ranks of all
the students in the final examination in some data structure. You decide to use
a Linked List to maintain this record.
A Linked List is a data structure that can grow or shrink dynamically. Each
node in a Linked List contains a data part and a link part. Write a program to
create the Linked List data structure for maintaining the record of ranks
obtained by all the students in the final examination, such that the rank of a
student is always an integer and forms the data part of the Linked List.
Note that the new node is always added at the end of a given Linked List. And
the newly added node becomes the new tail of the Linked List. For example, if
the given Linked List is 8->7 and you add an item 9 at the end, then the Linked
List becomes 8->7->9.
Your program should be able to take the number of nodes (i.e., the number of
students) in the Linked List from the user as input and then the value of each
node (i.e., the rank of each student) from the user as input. The program
should then traverse the Linked List from the beginning to the end and display
the ranks of all the students.

Input Format:
Input consists of a single positive integer, say N, (i.e., the number of nodes
in a Linked List), followed by N lines, each containing the value of the node
of the Linked List, that is to be added at the end of the Linked List.

Output Format:
The output consists of space-separated integer values stored in the Linked
List, which is traversed from the beginning to the end by the program.

Sample test cases:

Input:
3
8
7
9

Output:
8 7 9
*/

/*
Add a Node at the Beginning of a Linked List

Description
Let’s say you are a teacher and you want to keep a record of the ranks of all
the students in the final examination in some data structure. You decide to use
a Linked List to maintain this record.

A Linked List is a data structure that can grow or shrink dynamically. Each
node in a linked list contains a data part and a link part. Write a program to
create the Linked List data structure for maintaining the record of ranks
obtained by all the students in the final examination, such that the rank of a
student is always an integer and forms the data part of the Linked List.

Note that the new node is always added at the beginning, before the head of the
given Linked List. And the newly added node becomes the new head of the Linked
List. For example, if the given Linked List is 7->8 and you add an item 9 at
the beginning, then the Linked List becomes 9->7->8.

Your program should be able to take the number of nodes (i.e., the number of
students) in the Linked List from the user as input and then the value of each
node (i.e., the rank of each student) from the user as input. The program
should then traverse the Linked List from the beginning to the end and display
the ranks of all the students.

Input Format:
The input consists of a single positive integer, say, N, (i.e., the number of
nodes in a Linked List), followed by N lines, each containing the value of the
node of the Linked List, which is to be added at the beginning of the Linked
List.

Output Format:
The output consists of space-separated integer values stored in the Linked
List, which is traversed from the beginning to the end by the program.

Sample test cases:

Input:
3
8
7
9

Output:
9 7 8
*/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertAtFirst(int);
void insertAtLast(int);
void display();

struct studentNode {
  int studentRank;
  struct studentNode *nextStudentNode;
};

struct studentNode *theStudentList = NULL;

int main() {
  int noOfNodesToAdd = 0;
  scanf("%d", &noOfNodesToAdd);
  for (int i = 0; i < noOfNodesToAdd; i++) {
    int rank = 0;
    scanf("%d", &rank);
    insertAtFirst(rank);
  }
  display();
  return 0;
}

void insertAtFirst(int rank) {
  struct studentNode *temp =
      (struct studentNode *)malloc(sizeof(struct studentNode));

  if (temp == NULL) {
    printf("Out of Memory. Exiting.\n");
    exit(1);
  }

  temp->studentRank = rank;
  temp->nextStudentNode = NULL;

  if (theStudentList == NULL) {
    theStudentList = temp;
  } else {
    temp->nextStudentNode = theStudentList;
    theStudentList = temp;
  }
}

void insertAtLast(int rank) {
  struct studentNode *temp =
      (struct studentNode *)malloc(sizeof(struct studentNode));

  if (temp == NULL) {
    printf("Out of Memory Error. Exiting.\n");
    exit(1);
  }

  temp->studentRank = rank;
  temp->nextStudentNode = NULL;

  if (theStudentList == NULL) {
    theStudentList = temp;
  } else {
    struct studentNode *ptr;
    ptr = theStudentList;
    while (ptr->nextStudentNode != NULL) {
      ptr = ptr->nextStudentNode;
    }
    ptr->nextStudentNode = temp;
  }
}

void display() {
  if (theStudentList == NULL) {
    printf("The LinkedList is empty.\n");
    return;
  } else {
    struct studentNode *ptr;
    ptr = theStudentList;
    while (ptr != NULL) {
      printf("%d ", ptr->studentRank);
      ptr = ptr->nextStudentNode;
    }
  }
}
