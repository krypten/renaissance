#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX 100

int max(int a, int b)
{
	if (a > b) 
		return a;
	return b;
}

int CUT_ROD(int * p, int n, int * r)
{
	int q;
	int i;

	if (r[n] != -1) {
		return r[n];
	}
	if (n == 0) {
		q = 0;
	} else {
		q = INT_MIN;
		for ( i = 0; i < n; i++) {
			q = max(q, p[n] + CUT_ROD(p, n - i - 1, r));
		}
	}
	r[n] = q;
	return q;
}

int main()
{
	int n;
	int i;
	int p[MAX];
	int r[MAX];

	printf("Enter the length of rod");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}

	memset(r, -1, sizeof(r));

	printf("%d\n", CUT_ROD(&p[0], n, &r[0]));

	return 0;
}
