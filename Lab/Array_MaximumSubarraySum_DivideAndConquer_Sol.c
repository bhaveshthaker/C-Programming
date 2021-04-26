#include <limits.h>
#include <stdio.h>
int max(int num1, int num2) { return (num1 > num2) ? num1 : num2; }
int maxCrossingSum(int *arr, int l, int m, int h) {
  int sum = 0;
  int left_sum = INT_MIN;

  for (int i = m; i >= l; i--) {
    sum = sum + arr[i];
    if (sum > left_sum) {
      left_sum = sum;
    }
  }

  sum = 0;
  int right_sum = INT_MIN;
  for (int i = m + 1; i <= h; i++) {
    sum = sum + arr[i];
    if (sum > right_sum) {
      right_sum = sum;
    }
  }

  return max(left_sum + right_sum, max(left_sum, right_sum));
}

int maxSubArraySum(int *arr, int l, int h) {
  if (l == h) {
    return arr[l];
  }

  int m = (l + h) / 2;

  return max(max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m + 1, h)),
             maxCrossingSum(arr, l, m, h));
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
