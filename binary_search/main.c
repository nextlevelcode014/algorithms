#include <stdio.h>

int binary_search(int arr[], int n, int len)
{
  int l = 0;
  int r = len - 1;
  int steps = 0;

  while (l <= r)
  {
    // If l and r are large integers, then l + r can exceed the maximum value an int can hold, causing overflow.
    int mid = l + (r - l) / 2;
    steps++;
    if (arr[mid] == n)
    {
      printf("steps: %d\n", steps);
      return mid;
    }
    else if (arr[mid] < n)
    {
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }

  return -1;
}

int main(void)
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int len = sizeof(arr) / sizeof(arr[0]);

  int result = binary_search(arr, 9, len);
  printf("result: %d", result);

  return 0;
}
