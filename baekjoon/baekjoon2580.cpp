#include <iostream>
#include <vector>

using namespace std;

int sudoku[9][9];
int end_flag = 0;
vector<pair<int,int> > v;


void make_sudoku(vector<pair<int,int> > vec)
{
    if(end_flag)
        return;
    if(vec.empty())
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<sudoku[i][j]<<" ";
            }
            cout<<'\n';
        }
        end_flag=1;
        return;
    }
    
    for(int i=0;i<vec.size();i++)
    {
        sudoku[vec[i].first][vec[i].second] = 0;
    }
    
    int flag[9]={0,0,0,0,0,0,0,0,0};
    pair<int,int> t = vec[vec.size()-1];
    vec.pop_back();

    for(int i=0;i<9;i++)
    {
        flag[sudoku[t.first][i]-1]=1;
        flag[sudoku[i][t.second]-1]=1;
    }
    for(int i=3*(t.first/3);i<=3*(t.first/3)+2;i++)
    {
        for(int j=3*(t.second/3);j<=3*(t.second/3)+2;j++)
        {
            if(i==t.first && j==t.second)
                break;
            flag[sudoku[i][j]-1]=1;
        }
    }
    
    for(int i=0;i<9;i++)
    {
        if(!flag[i])
        {
            sudoku[t.first][t.second]=i+1;
            make_sudoku(vec);
        }
    }

}

int main() {
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>sudoku[i][j];
            if(sudoku[i][j]==0)
                v.push_back(make_pair(i,j));
        }
    }

    make_sudoku(v);
}
