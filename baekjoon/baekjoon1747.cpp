#include <iostream>
#include <string>
#include <cmath>

#define MAXIMUM 2000000

using namespace std;

void input();
void filter_prime_number();
void find_min_palindrome();
bool is_palindrome(int n);

int N;
int Number[2000001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  filter_prime_number();

  find_min_palindrome();
}

void input()
{
  cin >> N;
}

void filter_prime_number()
{
  Number[1] = 1;

  for (int i = 2; i <= sqrt(MAXIMUM); i++)
  {
    if (Number[i])
      continue;

    for (int j = i * i; j <= MAXIMUM; j = j + i)
    {
      Number[j] = 1;
    }
  }
}

void find_min_palindrome()
{
  for (int i = N; i <= MAXIMUM; i++)
  {
    if (!Number[i] && is_palindrome(i))
    {
      cout << i << '\n';
      return;
    }
  }
}

bool is_palindrome(int n)
{
  string str = to_string(n);

  int length = (int)str.length();

  for (int i = 0; i < length / 2; i++)
  {
    if (str[i] != str[length - i - 1])
      return false;
  }

  return true;
}
