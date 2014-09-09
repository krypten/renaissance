/*
Input:
	2
	1 1 10 10
	11 11 20 20
	1 1 20 20
	11 11 30 30

Output:
	162
	641
*/

#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int x;
	int y;
} point;


int swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

int main()
{
	int t;
	int i, j;
	point p, q, r, s;

	cin >> t;
	while (t--) {
		cin >> p.x >> p.y >> q.x >> q.y;
		cin >> r.x >> r.y >> s.x >> s.y;

		bool area[1001][1001] = {0};

		// min
		if (p.x > q.x)
			swap(p.x, q.x);

		if (p.y > q.y)
			swap(p.y, q.y);

		if (r.x > s.x)
			swap(r.x, s.x);

		if (r.y > s.y)
			swap(p.x, q.x);

		// mark
		for (i = p.x; i < q.x; i++) {
			for (j = p.y; j < q.y; j++) {
				area[i][j] = true;
			}
		}

		for (i = r.x; i < s.x; i++) {
			for (j = r.y; j < s.y; j++) {
				area[i][j] = true;
			}
		}

		int sum = 0;
		for (i = 0; i < 1001; i++) {
			for (j = 0; j < 1001; j++) {
				if (area[i][j] == true) {
					sum++;
					area[i][j] = false;
				}
			}
		}
		cout << sum << "\n";
	}

	return 0;
}