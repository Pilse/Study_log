#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

long long get_largest_area(vector<int> heights);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (1)
  {
    int n;
    cin >> n;

    if (!n)
      break;

    vector<int> heights(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
      int t;
      cin >> t;
      heights[i] = t;
    }

    cout << get_largest_area(heights) << '\n';
  }
}

long long get_largest_area(vector<int> heights)
{
  stack<int> st;
  long long largest = 0;

  st.push(0);

  for (int i = 1; i <= heights.size(); i++)
  {
    int height = heights[i];

    while (!st.empty() && heights[st.top()] > height)
    {
      int stacked_index = st.top();
      st.pop();

      largest = max(largest, (long long)(i - st.top() - 1) * heights[stacked_index]);
    }

    st.push(i);
  }

  return largest;
}
