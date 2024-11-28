#include <stdio.h>

int binarySearch(int array[], int x, int low, int high, int *count) {
  // Increment the count each time the function is called
  (*count)++;

  // Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(array) / sizeof(array[0]);
  int x = 4;
  int count = 0; // Initialize count variable to 0
  printf("Suruchi Sharma:\n");
  int result = binarySearch(array, x, 0, n - 1, &count); 
  // Pass count by reference

  if (result == -1)
    printf("Element is not found\n");
  else
    printf("Element is found at index %d\n", result);

  printf("Function binarySearch was called %d times.\n", count);

  return 0;
}
