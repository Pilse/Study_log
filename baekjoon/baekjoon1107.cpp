#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void input();
bool check_break(int n);
void brute_force(string s, int step);

int N, M, L;
int Min;
vector<int> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    brute_force("", 0);
    
    cout << Min << '\n';
    
}

void input()
{
    cin >> N;
    cin >> M;
    
    for(int i = 0; i < M; i++)
    {
        int temp;
        
        cin >> temp;
        
        V.push_back(temp);
    }
    
    L = (int)(to_string(N).length());
    Min = abs(100 - N);
}

bool check_break(int n)
{
    for(int j = 0; j < V.size(); j++)
    {
        if(n == V[j])
            return true;
    }
    
    return false;
}

void brute_force(string s, int step)
{
    for(int i = 0; i < 10; i++)
    {
        if(check_break(i)) continue;
        
        string cur_s = s + to_string(i);
        
        Min = min(Min, abs(N - stoi(cur_s)) + (int)cur_s.length());
        
        if(step < 6)
            brute_force(cur_s, step + 1);
    }
}
