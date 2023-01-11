#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long fill_box(int length, int width, int height, vector<pair<int, int>> &cubes);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<pair<int, int>> cubes;
    int length, width, height, n;
    
    cin >> length >> width >> height >> n;

    
    for(int i = 0; i < n; i++) {
        int t, cnt;
        cin >> t >> cnt;
        cubes.push_back({t, cnt});
    }
    
    cout << fill_box(length, width, height, cubes) << '\n';
}


long long fill_box(int length, int width, int height, vector<pair<int, int>> &cubes) {
    if(height == 0) return 0;
    
    int min_size = min({length, width, height});
    int max_size_cube_idx = log2(min_size);
    
    while(max_size_cube_idx >= 0 && !cubes[max_size_cube_idx].second) max_size_cube_idx--;
    
    if(max_size_cube_idx == -1) return -1;
    
    int max_size_cube = (int)pow(2, cubes[max_size_cube_idx].first);
    cubes[max_size_cube_idx].second --;
    
    long long cnt1 = 0, cnt2 = 0, cnt3 = 0;
    if(length - max_size_cube) {
        cnt1 = fill_box(length - max_size_cube, max_size_cube, max_size_cube, cubes);
        if(cnt1 == -1) return -1;
    }
    
    if(width - max_size_cube) {
        cnt2 = fill_box(length, width - max_size_cube, max_size_cube, cubes);
        if(cnt2 == -1) return -1;
    }
    
    if(height - max_size_cube) {
        cnt3 = fill_box(length, width, height - max_size_cube, cubes);
        if(cnt3 == -1) return -1;
    }
    return 1 + cnt1 + cnt2 + cnt3;
}


