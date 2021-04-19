/*
Binary Search in an Array
=========================
Description
Now that you have learnt how to search for an element in an array using a
linear search, write a program to perform a binary search on an array.
Implement the binarysearch() function, which uses a binary search algorithm
to search for a given key (or element) in an array. The program should take
the number of integer elements to be stored in the array, the value of each
of the elements and the key (or the element) that needs to be searched for
in the array as user input. The binarysearch() function should take the
array, the size of the array and the key to be searched for in the array as
input. This function should then search for a given key in the array using
a binary search algorithm. If the key being searched for is found in the
array, then the binarysearch() function should return the index of the key
in the array, and this index should be displayed as output. If the key
being searched for is not found in the array, then the binarysearch()
function should return -1 and the message ‘Number not found in array’
should be displayed.
Note that in order to search for a given key (or element) in an array using
a binary search algorithm, the elements of the array should mandatorily be
sorted in ascending or descending order. So, the first step in the
following program should be to sort the array in ascending order, in this
question, as the input array is unsorted.
Make use of the library function qsort() to sort the numbers in the array.
While using the qsort() function, you will need to define a comparison
function. This function should return the difference between the two
numbers that are being compared. Once qsort() has been used to sort the
array, the sorted array should be printed on the screen, and then this
array should be used further for binary search. Also note that the binary
search is performed on the sorted array, and the index of the key, if
found, has to be returned from the sorted array and not the original
array.

Hint:
Assuming the array is sorted in ascending order, to search for a key (or an
element) in the binary search algorithm, compare the key with the element
at the centre of the array. If they both match, then the search is
successful. Otherwise, the elements are divided into two halves: one from
the 0th element to the central element (the first half) and another from
the central element to the last element (the second half).
The search then proceeds in either of these two halves in the same manner
depending upon whether the key is lesser or greater than the central
element. If the key is greater than the central element, then the second
half should be scanned further in the same manner; else, if the key is less
than the central element, then the first half should be scanned further in
the same manner. The same process of comparing the key with the central
element, and then dividing the elements into two halves if the key is not
found is repeated for either the first half or the second half. This
procedure is repeated either till the element is found or the repeated
division of the halves yields one element.

Input Format:
The input consists of a single positive integer, say N (i.e., the number of
elements in the array, or the size of the array), followed by N integers,
which are to be stored in an array. The last value in the input represents
the key that needs to be searched for in the array.

Output Format:
The output consists of two lines. The first line consists of N
space-separated integers, which represent the values of the array from the
beginning to the end, after the array is sorted in ascending order.
The second line of output consists of an integer ranging from 0 to N-1,
which represents the index of the key, if it is found in the array. Note
that the elements are stored in the array on the basis of zero-indexing.
Also note that the binary search is performed on the sorted array, and the
index of the key, if found, has to be returned from the sorted array and
not the original array.

In case the key is not found in the array during the binary search, the
message ‘Number not found in array’ is displayed.

Sample test case:
Input:
5 11 10 14 12 13 10
Output:
10 11 12 13 14
0

Explanation:
The first value in the input, 5 in this case, represents the number of
elements in the array, and the subsequent values, 11, 10, 14, 12 and 13,
represent the values of each of the elements that are to be stored in the
array. The last value in the input, 10 in this case, is the key that needs
to be searched for in the array. The first line of output has the values 10
11 12 13 14, which are obtained by sorting the input values, 11, 10, 14, 12
and 13, in ascending order. The second line of output has the value 0,
which indicates that the key (10) was found at index 0, in the sorted
array. Note that the index value displayed for 10 is 0, considering the
sorted array, and not 1, which is the index of 10 in the original array.
*/
#include <stdio.h>
#include <stdlib.h>

int compareFunction(const void *a, const void *b);
int binarysearch(int a[], int size, int key);

int main() {
  int num, i, pos, key;

  scanf("%d", &num);
  int arr[num];

  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);

  scanf("%d", &key);

  // Sort the array
  qsort(arr, num, sizeof(int), compareFunction);
  // Printing the sorted array
  for (i = 0; i < num; i++)
    printf("%d ", arr[i]);
  printf("\n");

  // Perform binary search
  pos = binarysearch(arr, num, key);
  if (pos == -1)
    printf("Number not found in array\n");
  else
    printf("%d\n", pos);

  return 0;
}

int compareFunction(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

/*
Pseudocode
==========
Procedure binary_search
   A ← sorted array
   n ← size of array
   x ← value to be searched

   Set lowerBound = 1
   Set upperBound = n

   while x not found
      if upperBound < lowerBound
         EXIT: x does not exists.

      set midPoint = lowerBound + ( upperBound - lowerBound ) / 2

      if A[midPoint] < x
         set lowerBound = midPoint + 1

      if A[midPoint] > x
         set upperBound = midPoint - 1

      if A[midPoint] = x
         EXIT: x found at location midPoint
   end while

end procedure
*/
int binarysearch(int a[], int size, int key) {
  // int pos = -2;
  int pos = -1;
  int lowerBound = 0;
  int upperBound = size;

  // while (pos == -2) {
  while (lowerBound <= upperBound) {
    if (upperBound < lowerBound) {
      pos = -1;
    }
    int midPoint = lowerBound + (upperBound - lowerBound) / 2;
    if (a[midPoint] == key) {
      pos = midPoint;
      break;
    }
    if (a[midPoint] < key) {
      lowerBound = midPoint + 1;
    }
    if (a[midPoint] > key) {
      upperBound = midPoint - 1;
    }
  }
  return pos;
}
