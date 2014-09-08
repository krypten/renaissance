#include <stdio.h>
#include <limits.h>

#define MAX 100

int max(int a, int b)
{
	if (a > b) 
		return a;
	return b;
}

int BOTTOM_CUT(int * p, int n)
{
	int r[MAX];
	int i;
	int j;
	int q;

	r[0] = 0;

	for (i = 0; i < n; i++) {
		q = INT_MIN;
		for (j = 0; j < i; j++) {
			q = max(q, p[j] + r[i - j]);
		}
		r[i] = q;
	}

	return r[n];
}

int main()
{
	int n;
	int i;
	int p[MAX];

	printf("Enter the length of rod");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}

	printf("%d\n", BOTTOM_CUT(&p[0], n));

	return 0;
}
