#include <stdio.h>

int binary_search(int arr[], int n, int l, int len)
{
    int r = len - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == n)
        {
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

int exponential_search(int *arr, int target, int len)
{
    if (arr[0] == target)
    {
        return 0;
    }
    int i = 1;
    int left = 0;

    while (i < len && arr[i] <= target)
    {
        left = i;
        i *= 2;
    }

    if (arr[i] == target)
    {
        return i;
    }

    return binary_search(arr, target, left, len < i ? len : i);
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int target = 15;
    int len = sizeof(arr) / sizeof(arr[0]);
    int result = exponential_search(arr, target, len);
    if (result != -1)
    {
        printf("Element found at index: %d\n", result);
    }
    else
    {
        printf("Element not found in the array.\n");
    }
    printf("result: %d\n", result);
    return 0;
}