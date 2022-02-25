#include "stdio.h"
#include "stdbool.h"

// Array Abtract Data Type
struct Array
{
  int data[20];
  int size;
  int length;
};

void Display(struct Array arr)
{
  printf("Elements are: ");
  for (int i = 0; i < arr.length; i++)
    printf("%d ", arr.data[i]);

  printf("\n");
}

void Push(struct Array *arr, int x)
{
  if (arr->length < arr->size)
    arr->data[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
  if (index >= 0 && index <= arr->length)
  {
    for (int i = arr->length; i > index; i--)
      arr->data[i] = arr->data[i - 1];

    arr->data[index] = x;
    arr->length++;
  }
}

int Delete(struct Array *arr, int index)
{
  int x = 0;
  if (index >= 0 && index < arr->length)
  {
    x = arr->data[index];

    for (int i = index; i < arr->length - 1; i++)
      arr->data[i] = arr->data[i + 1];

    arr->length--;
  }

  return x;
}

void swap(int *x, int *y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

// Linear Search
int FindIndex(struct Array arr, int key)
{
  for (int i = 0; i < arr.length; i++)
  {
    if (arr.data[i] == key)
      return i;
  }

  return -1;
}

// Linear Search
int FindIndexImproved(struct Array *arr, int key, bool transposition)
{
  for (int i = 0; i < arr->length; i++)
  {
    if (arr->data[i] == key)
    {
      if (transposition)
      {
        // Apply transposition
        swap(&arr->data[i], &arr->data[i - 1]);
        return i - 1;
      }
      else
      {
        // Apply move to front/head
        swap(&arr->data[i], &arr->data[0]);
        return 0;
      }
    }
  }

  return -1;
}

int BinarySearch(struct Array arr, int key)
{
  int lower = 0;
  int higher = arr.length;
  int mid = (lower + higher) / 2;

  while (lower < higher)
  {
    if (arr.data[mid] == key)
      return mid;
    else if (arr.data[mid] < key)
      lower = mid + 1;
    else
      higher = mid - 1;

    mid = (lower + higher) / 2;
  }

  return -1;
}

int RecursiveBinarySearch(struct Array arr, int l, int h, int key)
{
  int mid;

  if (l <= h)
  {
    mid = (l + h) / 2;
    if (key == arr.data[mid])
      return mid;
    else if (key < arr.data[mid])
      return RecursiveBinarySearch(arr, l, mid - 1, key);
    else
      return RecursiveBinarySearch(arr, mid + 1, h, key);
  }

  return -1;
}

int Get(struct Array arr, int index)
{
  if (index >= 0 && index < arr.length)
    return arr.data[index];

  return -1;
}

int Set(struct Array *arr, int index, int key)
{
  if (index >= 0 && index < arr->length)
    arr->data[index] = key;
  else
    return -1;

  return 0;
}

int Max(struct Array arr)
{
  int max = arr.data[0];

  for (int i = 1; i < arr.length; i++)
  {
    if (arr.data[i] > max)
      max = arr.data[i];
  }

  return max;
}

int Min(struct Array arr)
{
  int min = arr.data[0];

  for (int i = 1; i < arr.length; i++)
  {
    if (arr.data[i] < min)
      min = arr.data[i];
  }

  return min;
}

int Sum(struct Array arr)
{
  int total = 0;

  for (int i = 0; i < arr.length; i++)
    total += arr.data[i];

  return total;
}

float Avg(struct Array arr)
{
  return (float)Sum(arr) / arr.length;
}

void Reverse(struct Array *arr)
{
  int b[arr->length];

  for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
    b[j] = arr->data[i];

  for (int i = 0; i < arr->length; i++)
    arr->data[i] = b[i];
}

void SwapReverse(struct Array *arr)
{
  for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    swap(&arr->data[i], &arr->data[j]);
}

void LeftShift(struct Array *arr)
{
  for (int i = 0; i < arr->length - 1; i++)
    arr->data[i] = arr->data[i + 1];

  arr->length--;
  arr->data[arr->length] = 0;
}

void LeftRotate(struct Array *arr)
{
  int tmp = arr->data[0];

  for (int i = 0; i < arr->length - 1; i++)
    arr->data[i] = arr->data[i + 1];

  arr->data[arr->length - 1] = tmp;
}

int main()
{
  struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};

  LeftRotate(&arr);

  Display(arr);

  return 0;
}