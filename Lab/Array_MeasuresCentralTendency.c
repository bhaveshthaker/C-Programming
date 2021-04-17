/*
Measures of Central Tendency
============================
Description
If 25 integers are entered through the keyboard, then write a program to
calculate the three measures of central tendency, mean, median and mode
values, for these integers.
Mean is the average of 25 numbers.
Median is the value at the centre of the 25 numbers when they are arranged
in an ascending or a descending order.
Mode is the number that occurs most often in the set of 25 numbers.

Hint:
Store all the 25 input integers in an array. Mean can be calculated by
finding the average of all the elements in the array. Median can be
calculated by finding the element at the middle of the sorted array. And
mode can be calculated by finding the element that occurs most often in the
array. If more than one element occurs most often in the array, then the
mode will be the element that is the greatest among all of them.

Input Format:
The input contains 25 integers, which should be stored in an array.
Output Format:
The output consists of three lines. The first line prints the mean of the
25 input numbers. The second line prints the median of the 25 input
numbers. The third line prints the mode of the 25 input numbers.

Sample test cases:
Input:
12 12 12 12 12 13 13 13 14 15 15 15 15 15 15 15 15 15 16 16 16 17 17 17 17

Output:
14
15
15

Explanation:
The value in the first line of the output, 14, is the mean of the given
input values. The value in the second line corresponds to the median of the
input values, and the value in the third line of the output is the mode of
the given input values.
*/
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mean(int a[], int);
void swap(int *, int *);
void sort(int a[], int);
int mode(int a[], int);

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  // Note that you need to explicitly return 0 in main() function,
  // otherwise your solution won't get accepted
  int SIZE = 25;
  int arr[SIZE];
  /*
  int arr[] = {12, 12, 12, 12, 12, 13, 13, 13, 14, 15, 15, 15, 15,
               15, 15, 15, 15, 15, 16, 16, 16, 17, 17, 17, 17};
  */
  // int arrSize = sizeof(arr) / sizeof(arr[0]);
  int arrSize = SIZE;
  for (int i = 0; i < arrSize; i++) {
    scanf("%d", &arr[i]);
  }

  printf("%d\n", mean(arr, arrSize));
  int msize = arrSize;
  sort(arr, msize);
  msize = (msize + 1) / 2 - 1;
  printf("%d\n", arr[msize]);
  printf("%d\n", mode(arr, arrSize));
  return 0;
}

int mean(int a[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum / n;
}

void swap(int *p, int *q) {
  int t;

  t = *p;
  *p = *q;
  *q = t;
}

void sort(int a[], int n) {
  int i, j, temp;

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1])
        swap(&a[j], &a[j + 1]);
    }
  }
}

int mode(int a[], int n) {
  int maxValue = 0, maxCount = 0, i, j;

  for (i = 0; i < n; ++i) {
    int count = 0;
    for (j = 0; j < n; ++j) {
      if (a[j] == a[i])
        ++count;
    }

    if (count > maxCount) {
      maxCount = count;
      maxValue = a[i];
    }
  }

  return maxValue;
}
