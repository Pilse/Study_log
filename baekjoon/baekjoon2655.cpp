#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct block {
    int area;
    int height;
    int weight;
    int idx;
};

bool compare(block a, block b)
{
    return a.area < b.area;
}

vector<int> dp;
vector<int> parent;

int check(vector<block> &blocks, int cur);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    dp.resize(n + 1, -1);
    parent.resize(n + 1, 0);
    
    vector<block> blocks(n + 1);
    for(int i = 1; i < blocks.size(); i++)
    {
        cin >> blocks[i].area >> blocks[i].height >> blocks[i].weight;
        blocks[i].idx = i;
        parent[i] = i;
    }
    sort(next(blocks.begin(), 1), blocks.end(), compare);
    
    blocks[0].height = 0;
    blocks[0].weight = -1;
    check(blocks, 0);
    
    vector<int> answer;
    int idx = 0;
    do {
        idx = parent[idx];
        answer.push_back(blocks[idx].idx);
    } while(parent[idx] != idx);
    cout << answer.size() << '\n';
    for(auto &a : answer) cout << a << '\n';
}

int check(vector<block> &blocks, int cur)
{
    if(dp[cur] != -1) return dp[cur];
    dp[cur] = blocks[cur].height;
    for(int i = cur + 1; i < blocks.size(); i++)
    {
        if(blocks[cur].weight > blocks[i].weight) continue;
        int n_height = check(blocks, i) + blocks[cur].height;
        if(n_height > dp[cur])
        {
            dp[cur] = n_height;
            parent[cur] = i;
        }
    }
    return dp[cur];
}
