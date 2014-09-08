#include <stdio.h>
#include <string.h>

#define length (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));

int initialise (int node,  int b, int e, int *m, int *a, int n)
{
	if(b == e) m[node] = b;
	else {
		initialise(2*node, b, (b+e)/2 , m, a, n);
		initialise(2*node + 1, (b+e)/2 +1, e, m, a, n);

		if( a[m[2*node]] <= a[m[2*node +1]] ) 
			m[node] = m[2*node];
		else 
			m[node] = m[2*node] + 1;
	}
}

//TODO :: O(log(n)) update function

int query(int node, int b, int e, int *m, int *a, int i, int j)
{
	int p1,p2;
	
	if(i > e || j < b) return -1;

	if(b >= i && e <= j) return m[node];
	
	p1 = query(2*node, b, (b+e)/2, m, a, i, j);
	p2 = query(2*node +1, (b+e)/2, e, m, a, i, j);

	if ( p1 == -1) return m[node] = p2;
	if ( p2 == -1) return m[node] = p1;
	if( a[p1]  < a[p2]) return m[node] = p1;
	
	return m[node] = p2;
	
}
int main()
{
	int a[100];
	int m[100];
	int n;
	n = 10;

	memset(m , -1 , sizeof(m));

	initialise (1, 0 , n-1, m, a, n);	

	return 0;
}
