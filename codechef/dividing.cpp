#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int n;
	int t;
	long long int sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		sum += t;
	}
	if ((sum*2) == (n*(n+1))) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}