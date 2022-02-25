#include "stdio.h"

void func(int n)
{
  if (n > 0)
  {
    printf("%d\n", n);
    func(n - 1);
  }
}

void fun2(int n)
{
  if (n > 0)
  {
    // 1. phase one: calling
    fun2(n - 1);
    printf("%d\n", n * 2); // multipling will be done once the function returns
    // 2. phase two: returning
  }
}

void main()
{
  int x = 3;
  fun2(x);
}