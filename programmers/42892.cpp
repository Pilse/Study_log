#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> m;
vector<int> lc(10001, -1);
vector<int> rc(10001, -1);

bool compare(vector<int> a, vector<int> b)
{
  if (a[1] == b[1])
    return a[0] < b[0];
  return a[1] > b[1];
}

string coor_to_str(vector<int> v)
{
  int n1 = v[0];
  int n2 = v[1];
  string str = "";

  while (n1 >= 10)
  {
    str += (n1 % 10) + '0';
    n1 /= 10;
  }
  str += n1 + '0';

  str += ',';

  while (n2 >= 10)
  {
    str += (n2 % 10) + '0';
    n2 /= 10;
  }
  str += n2 + '0';

  return str;
}

void make_tree(vector<int> parent, vector<vector<int> > nodes)
{
  int px = parent[0];
  vector<vector<int> > ln;
  vector<vector<int> > rn;
  for (int i = 0; i < nodes.size(); i++)
  {
    if (nodes[i][0] > px)
      rn.push_back(nodes[i]);
    else
      ln.push_back(nodes[i]);
  }

  if (!ln.empty())
  {
    lc[m[coor_to_str(parent)]] = m[coor_to_str(ln[0])];
    vector<int> lparent = ln[0];
    ln.erase(ln.begin());
    if (!ln.empty())
      make_tree(lparent, ln);
  }
  if (!rn.empty())
  {
    rc[m[coor_to_str(parent)]] = m[coor_to_str(rn[0])];
    vector<int> rparent = rn[0];
    rn.erase(rn.begin());
    if (!rn.empty())
      make_tree(rparent, rn);
  }
}

void preorder(vector<int> &arr, int cur)
{
  arr.push_back(cur);
  if (lc[cur] != -1)
    preorder(arr, lc[cur]);
  if (rc[cur] != -1)
    preorder(arr, rc[cur]);
}

void postorder(vector<int> &arr, int cur)
{
  if (lc[cur] != -1)
    postorder(arr, lc[cur]);
  if (rc[cur] != -1)
    postorder(arr, rc[cur]);
  arr.push_back(cur);
}

vector<vector<int> > solution(vector<vector<int> > nodeinfo)
{
  for (int i = 0; i < nodeinfo.size(); i++)
    m[coor_to_str(nodeinfo[i])] = i + 1;

  sort(nodeinfo.begin(), nodeinfo.end(), compare);
  vector<int> root = nodeinfo[0];
  nodeinfo.erase(nodeinfo.begin());
  make_tree(root, nodeinfo);

  vector<vector<int> > answer(2);
  preorder(answer[0], m[coor_to_str(root)]);
  postorder(answer[1], m[coor_to_str(root)]);
  return answer;
}