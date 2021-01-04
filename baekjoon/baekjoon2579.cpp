#include <iostream>

using namespace std;

#define EL "\n"

#define FOR(i, j) for(int i = 0; i < j; i++)

int stairs[300];
int scores[300];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	FOR(i, N)
		cin >> stairs[i];

	FOR(i, N) {
		if (i == 0)
			scores[i] = stairs[i];
		else if (i == 1)
			scores[i] = stairs[i - 1] + stairs[i];
		else if (i == 2) {
			if (stairs[i - 1] > stairs[i - 2])
				scores[i] = stairs[i - 1] + stairs[i];
			else
				scores[i] = stairs[i - 2] + stairs[i];
		}
		else {
			if (scores[i - 3] + stairs[i - 1] > scores[i - 2])
				scores[i] = scores[i - 3] + stairs[i - 1] + stairs[i];
			else
				scores[i] = scores[i - 2] + stairs[i];
		}
	}

	cout << scores[N - 1] << EL;

	return 0;
}