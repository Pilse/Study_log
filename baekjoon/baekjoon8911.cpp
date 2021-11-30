#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    string str;
    
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        cin >> str;
        
        int min_x = 0;
        int min_y = 0;
        int max_x = 0;
        int max_y = 0;
        int cur_x = 0;
        int cur_y = 0;
        int dir = 0;
        
        for(int j = 0; j < str.length(); j++)
        {
            char command = str[j];
            
            switch (command)
            {
                case 'F':
                    switch (dir)
                    {
                        case 0:
                            cur_y++;
                            break;
                        case 1:
                            cur_x++;
                            break;
                        case 2:
                            cur_y--;
                            break;
                        case 3:
                            cur_x--;
                            break;
                        default:
                            break;
                    }
                    min_x = min(cur_x, min_x);
                    max_x = max(cur_x, max_x);
                    min_y = min(cur_y, min_y);
                    max_y = max(cur_y, max_y);
                    break;
                    
                case 'B':
                    switch (dir)
                    {
                        case 0:
                            cur_y--;
                            break;
                        case 1:
                            cur_x--;
                            break;
                        case 2:
                            cur_y++;
                            break;
                        case 3:
                            cur_x++;
                            break;
                        default:
                            break;
                    }
                    min_x = min(cur_x, min_x);
                    max_x = max(cur_x, max_x);
                    min_y = min(cur_y, min_y);
                    max_y = max(cur_y, max_y);
                    break;
                    
                case 'R':
                    dir = (dir + 1) % 4;
                    break;
                    
                case 'L':
                    dir = dir - 1 >= 0 ? dir - 1 : 3;
                    break;
                    
                default:
                    break;
            }
        }
        
//        cout << min_x << " " << max_x << " " << min_y << " " << max_y << '\n';
        cout << (max_x - min_x) * (max_y - min_y) << '\n';
        
    }
    
}
