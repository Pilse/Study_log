### 뽀문도로 기법

```cpp
#include <iostream>
using namespace std;

int main()
{
	int m, a, b;
	int result=0;
	cin >> m;
	cin >> a >> b;
	for (;;)
	{
		if (a > m)
		{
			result = result + m;
			break;
		}
		else
		{
			result = result + a;
			m = m - a;
			m = m - b;
			if (m <= 0)
				break;
		}
		
	}
	cout << result;

}
```
### 우리가 할로윈과 크리스마스를 혼동하는 이유

```cpp
#include <iostream>
#include <string.h>
using namespace std;

int make_value(string c, int l)
{
	int result = 0;
	int d = 1;
	for (int i = c.length() - 1; i >= 0; i--)
	{
		result = result + (d * (c[i] - '0'));
		d = d * l;
	}
	return result;

}
int long_(string c)
{
	int clong = 0;
	for (int i = 0; i < c.length(); i++)
	{
		int s = c[i] - '0';
		if (s > clong)
			clong = s;
	}
	return clong + 1;

}

int main()
{
	string S;
	string T;
	int slong = 0;
	int tlong = 0;
	cin >> S;
	cin >> T;
	slong = long_(S);
	tlong = long_(T);

	int sv = 0;
	int tv = 0;
	int cnt = 0;
	for (int i = slong; i <= 10; i++)
	{
		sv = make_value(S, i);
		for (int j = tlong; j <= 10; j++)
		{
			tv = make_value(T, j);
			if (sv == tv)
			{
				cnt++;
			}
		}

	}
	cout << cnt;
}
```

### 문기의 크리스마스 난제

```cpp
#include <iostream>
using namespace std;

int main()
{
	int n;
	string s;
	int cnt = 0;

	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0')
		{
			cnt++;
			s[i] = '1';
			if (s[i + 1] == '0')
				s[i + 1] = '1';
			else
				s[i + 1] = '0';
		}
	}
	if (s[n - 1] == '0')
		cout << "-1";
	else
		cout << cnt;
}
```

### 연웅의 할로윈 난제

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int, int>> location;
vector <pair<int, int>> moving;
int* visited;
queue <int> q;

int search()
{
	int cnt = 0;
	int index = 0;
	int xshort = location[0].first - moving[0].first;
	int xlong = location[0].first + moving[0].first;
	int yshort= location[0].second - moving[0].second;
	int ylong= location[0].second + moving[0].second;
	for (int i = 0; i < location.size(); i++)
	{
			}
	for (int i = xshort; i < xlong; i++)
	{
		for (int j = yshort; j < ylong; j++)
		{
			for (index=0; index < location.size(); index++)
			{
				if (abs(i - location[index].first) <=moving[index].first && abs(j - location[index].second) <= moving[index].second)
				{
					cnt++;

				}
			}
			if (cnt == location.size())
			{
				cout << i << " " << j;
				return 1;
				
			}
			cnt = 0;
		}

	}
	return 0;

}

int main()
{
	int N;
	cin >> N;
	visited = new int[N];
	memset(visited, 0, N);
	for (int i = 0; i < N; i++)
	{
		int temp1, temp2, temp3, temp4;
		cin >> temp1 >> temp2 >> temp3 >> temp4;
		location.push_back({ temp1,temp2 });
		moving.push_back({ temp3,temp4 });
	}

	if (!search())
		cout << "impossible";
	

}

```
