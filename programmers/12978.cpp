
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> map[51];

int dijkstra(int n, int limit) {
    vector<int> dist(n + 1, 1e9);
    priority_queue<pair<int, int>> pq;

    pq.push({0, 1});

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(cost > dist[cur]) continue;

        for(int i = 0; i < map[cur].size(); i++) {
            int next_node = map[cur][i].first;
            int next_cost = cost + map[cur][i].second;

            if(next_cost < dist[next_node]) {
                dist[next_node] = next_cost;
                pq.push({-next_cost, next_node});
            }
        }
    }

    int cnt = 0;
    for(int i = 2; i <= n; i++) {
        if(dist[i] <= limit) cnt++;
    }
    return cnt + 1;
} 

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for(int i = 0; i < road.size(); i++) {
        int n1 = road[i][0];
        int n2 = road[i][1];
        int cost = road[i][2];

        map[n1].push_back({n2, cost});
        map[n2].push_back({n1, cost});
    }

    return dijkstra(N, K);
}