#include <iostream>
using namespace std;

int get_cost(int n)
{
  if (n == 1 || n == 2)
    return 1;

  if (n % 2 == 0)
    return get_cost(n / 2);
  else
    return get_cost(n - 1) + 1;
}

int solution(int n)
{
  return get_cost(n);
}