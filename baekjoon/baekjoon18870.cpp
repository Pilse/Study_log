#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> Coord;

void input();

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  vector<int> temp = Coord;

  sort(Coord.begin(), Coord.end());
  Coord.erase(unique(Coord.begin(), Coord.end()), Coord.end());

  for (int num : temp)
    cout << lower_bound(Coord.begin(), Coord.end(), num) - Coord.begin() << " ";
}

void input()
{
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int temp;
    cin >> temp;
    Coord.push_back(temp);
  }
}
