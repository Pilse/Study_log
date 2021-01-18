#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001

using namespace std;

queue<pair<pair<int,int>,int>> q;
int arr[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int M,N;
bool visited[MAX][MAX];
int cnt;

void bfs(){
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        cnt = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx <0 || ny < 0 || nx >= N || ny >= M) continue;
                if(arr[nx][ny] == 0 && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push(make_pair(make_pair(nx,ny), cnt+1));
                }
        }
    }
}

void check(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(arr[i][j]==0 && !visited[i][j])
            {
                 cnt = -1;
                 break;
            }
        }
    }
}



int main(void){
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                visited[i][j] = true;
                q.push(make_pair(make_pair(i,j),0));
            }
        }
    }
    bfs();
    check();
    cout<<cnt;
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001

using namespace std;

queue<pair<pair<int,int>,int>> q;
int arr[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int M,N;
bool visited[MAX][MAX];
int cnt;

void bfs(){
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        cnt = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx <0 || ny < 0 || nx >= N || ny >= M) continue;
                if(arr[nx][ny] == 0 && !visited[nx][ny]){
                    //arr[nx][ny] = 1;
                    visited[nx][ny] = true;
                    q.push(make_pair(make_pair(nx,ny), cnt+1));
                }
        }
    }
}

void check(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(arr[i][j]==0 && !visited[i][j])
            {
                 cnt = -1;
                 break;
            }
        }
    }
}



int main(void){
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                visited[i][j] = true;
                q.push(make_pair(make_pair(i,j),0));
            }
        }
    }
    bfs();
    check();
    cout<<cnt;
    return 0;
}
