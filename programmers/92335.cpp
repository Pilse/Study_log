#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(long long num)
{
  if (num < 2)
    return false;

  for (int i = 2; i <= sqrt(num); i++)
    if (num % i == 0)
      return false;

  return true;
}

bool check_condition(string &target, string &src, int idx)
{
  int right = idx + 1;
  int left = idx - target.length();

  if (left < 0 && right >= src.length())
    return true;
  if (left >= 0 && right >= src.length() && src[left] == '0')
    return true;
  if (left < 0 && right < src.length() && src[right] == '0')
    return true;
  if (left >= 0 && right < src.length() && src[left] == '0' && src[right] == '0')
    return true;
  return false;
}

int solution(int n, int k)
{
  int answer = 0;

  vector<int> converted;
  while (n > k)
  {
    converted.push_back(n % k);
    n /= k;
  }
  converted.push_back(n);
  reverse(converted.begin(), converted.end());

  string k_str;
  for (auto i : converted)
    k_str += to_string(i);

  string num_str = "";
  for (int i = 0; i < k_str.length(); i++)
  {
    if (k_str[i] == '0')
    {
      num_str = "";
      continue;
    }

    num_str += k_str[i];

    if (!is_prime(stoll(num_str)))
      continue;

    if (check_condition(num_str, k_str, i))
      answer++;
  }

  return answer;
}