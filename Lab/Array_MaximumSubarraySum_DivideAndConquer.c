/*
Maximum Subarray Sum (Divide and Conquer)
=========================================
Description
You are given an array containing 'n' elements. The array can contain both
positive and negative integers. Determine the sum of the contiguous
subarray with the maximum sum.
Consider the array {8, -9, 3, 6, 8, -5, 7, -6, 1, -3}.
The maximum subarray will be 3, 6, 8, -5, 7.
The maximum subarray sum will be 3+6+8+(-5)+7 = 19

Input Format:
The input contains the number of elements in the array, followed by the
elements in the array.

Output Format:
The output contains the maximum subarray sum.

Sample Test Cases:
Input:
10 8 -9 3 6 8 -5 7 -6 1 -3
Output:
19

Input:
5 8 9 4 5 7
Output:
33
*/
#include <limits.h>
#include <math.h>
#include <stdio.h>

// Utility function to find maximum of two numbers
int max(int x, int y) {
  if (x > y) {
    return x;
  } else {
    return y;
  }
}

int maxSubArraySum(int arr[], int low, int high) {
  // If array contains only one element
  if (high == low) {
    return arr[low];
  }

  // Find middle element of the array
  int mid = (low + high) / 2;

  // Find maximum subarray sum for the left subarray
  // including the middle element
  int left_max = INT_MIN;
  int sum = 0;
  for (int i = mid; i >= low; i--) {
    sum += arr[i];
    if (sum > left_max) {
      left_max = sum;
    }
  }

  // Find maximum subarray sum for the right subarray
  // excluding the middle element
  int right_max = INT_MIN;
  sum = 0;
  for (int i = mid + 1; i <= high; i++) {
    sum += arr[i];
    if (sum > right_max) {
      right_max = sum;
    }
  }

  // Recursively find the maximum subarray sum for left subarray
  // and right subarray and take maximum
  int max_left_right =
      max(maxSubArraySum(arr, low, mid), maxSubArraySum(arr, mid + 1, high));

  // return maximum of the three
  return max(max_left_right, left_max + right_max);
}

int main() {
  // printf("Hello, World!\n");
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  printf("%d", maxSubArraySum(arr, 0, n - 1));
  return 0;
}
