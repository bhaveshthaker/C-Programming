/*
Linear Search in an Array
=========================
Description
Now that you have learnt how to create an array and store in it elements
that are passed by a user as input, write a program to perform a linear
search on an array. Implement the linearsearch() function, which uses a
linear search algorithm to search for a given key (or element) in the
array. The program should take the number of integer elements to be stored
in the array, the value of each of the elements and the key (or the
element) that needs to be searched for in the array as user input. The
linearsearch() function should take the array, the size of the array, and
the key to be searched for in the array as input. This function should then
search for a given key in the array using a linear search algorithm. If the
key being searched for is found in the array, then the linearsearch()
function should return the index of the key in the array, and this index
should be displayed as output. And if the key being searched for is not
found in the array, then the linearsearch() function should return -1 and
the message ‘Number not found in array’ should be displayed.

Input Format:
The first value in the input is a positive integer, say N (i.e., the number
of elements in the array, or the size of the array), followed by N
integers, which are to be stored in an array. These N integers are then
followed by the last value which represents the key that needs to be
searched for in the array.
Output Format:
The output consists of an integer ranging from 0 to N-1, which represents
the index of the key, if it is found in the array. Note that the elements
are stored in the array on the basis of zero-indexing.
In case the key is not found in the array during the linear search, the
message ‘Number not found in array’ is displayed.

Sample test case:
Input:
5 10 11 12 13 14 12
Output:
2

Explanation:
The first value in the input, 5 in this case, represents the number of
elements in the array, and the subsequent values, 10, 11, 12, 13 and 14,
represent the values of each of the elements that are to be stored in the
array. The last value in the input, 12 in this case, is the key that needs
to be searched for in the array. The output, 2, represents the index of the
key, 12 in this case, in the array.
*/
#include <stdio.h>
#include <stdlib.h>

int linearsearch(int a[], int size, int n);

int main() {
  int num, i, pos, key;

  scanf("%d", &num);
  int arr[num];

  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);

  scanf("%d", &key);

  pos = linearsearch(arr, num, key);
  if (pos == -1)
    printf("Number not found in array\n");
  else
    printf("%d\n", pos);

  return 0;
}
