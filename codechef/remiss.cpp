#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	int a, b;

	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << (a>b?a:b) << " " << a + b << "\n"; 
	}

	return 0;
}