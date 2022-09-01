#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> targets;
unordered_map<int, int> cards;
int n, m;

void input();

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  for (int number : targets)
  {
    auto found = cards.find(number);
    int result = found == cards.end() ? 0 : found->second;
    cout << result << " ";
  }
}

void input()
{
  int temp;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    cards.insert({temp, 1});
  }

  cin >> m;
  targets.resize(m);
  for_each(targets.begin(), targets.end(), [](int &v)
           { cin >> v; });
}
