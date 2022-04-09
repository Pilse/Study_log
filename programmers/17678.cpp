
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
54
55
56
57
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int to_minute(string t) {
    int h1 = t[0] - '0';
    int h2 = t[1] - '0';
    int m1 = t[3] - '0';
    int m2 = t[4] - '0';

    return (h1 * 10 + h2) * 60 + m1 * 10 + m2;
}

string to_time(int t) {
    string str ="";
    int h1 = (t / 60) / 10;
    int h2 = (t / 60) % 10;
    int m1 = (t % 60) / 10;
    int m2 = (t % 60) % 10;

    str += (char)h1 + 48;
    str += (char)h2 + 48;
    str += ":";
    str += (char)m1 + 48;
    str += (char)m2 + 48;

    return str;
}

string solution(int n, int t, int m, vector<string> timetable) {
    int time[1440] {0};
    int st = 0, en = 540 + (n - 1) * t, ans = 0, tot = 0, bus = 540;

    for(int i = 0; i < timetable.size(); i++) 
        time[to_minute(timetable[i])] ++;    

    for(int i = st; i <= en; i++) {
        tot += time[i];

        if(tot < m) ans = i;

        if(i == bus) {
            tot = tot - m >= 0 ? tot - m : 0;

            bus += t;
        }

        if(bus < en) {
            if(tot - ((en - bus) / t) * m < m) ans = i;
        }
    }

    return to_time(ans);
}
