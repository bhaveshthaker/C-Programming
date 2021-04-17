/*
Array Input/Output
==================
Description
Write a program that creates an integer array using input values and prints
the values stored in the array as output. The program should be able to
take the number of elements to be stored in the array, and then the integer
value of each element of the array, as input from the user. After storing
all the values in the array, the program should traverse the array from the
beginning to the end and display all of its elements as output.

Input Format:
The input consists of a single positive integer, say N (i.e., the number of
elements in the array, or the size of the array), followed by N integers,
which are to be stored in an array.

Output Format:
The output consists of N space-separated elements of the array, when the
array is traversed from the beginning to the end.

Sample test case:
Input:
5 10 11 12 13 14
Output:
10 11 12 13 14

Explanation:
The first value in the input, 5 in this case, represents the number of
elements in the array, and the subsequent values, 10, 11, 12, 13 and 14,
represent the values of each of the elements that are to be stored in the
array. The output, 10 11 12 13 14, represents the value of each of the
elements that were stored in the array.
*/
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int *, int);
void swap(int *, int *);
void printArray(int *, int);

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  // Note that you need to explicitly return 0 in main() function,
  // otherwise your solution won't get accepted

  int N = 0;
  scanf("%u", &N);

  int *array = malloc(N * sizeof(int));

  for (int i = 0; i < N; i++) {
    scanf("%u", &array[i]);
  }

  // sort(array, N);
  printArray(array, N);

  return 0;
}

void sort(int *array, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
      }
    }
  }
}

void swap(int *p, int *q) {
  int temp;
  temp = *p;
  *p = *q;
  *q = temp;
}

void printArray(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  putchar('\n');
}

/*
// SOLUTION

#include <stdio.h>
#include <stdlib.h>

int main( )
{
    int num,i;

    scanf("%d",&num);
        int arr[ num ];

    for ( i = 0 ; i < num ; i++ )
        scanf("%d",&arr[i]);

    for ( i = 0 ; i < num ; i++ )
    printf("%d ",arr[i]);

    return 0;
}

*/
