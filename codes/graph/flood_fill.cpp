#include <cstdio>
#include <map>
#include <vector>

using namespace std;

typedef pair <int,int> ii;
typedef vector <ii> vii;
vector <vii> AdjList;
vector <int> d;

void flood_fill(int u, int color) {
	int i;
	d[u] = color;
	for( i = 0; i < AdjList[u].size() ; i++) {
		ii v= AdjList[u][i];
		if( d[v.first] == -1) {
			flood_fill(v.first, color);
		}
	}
}

int main()
{
	int i, j;
	int n;
	int weigth;
	int ncomponents = 0;

	scanf("%d", &n);

	d.assign(n, -1);
	AdjList.assign(n, vii());

	for ( i = 0 ; i < n;i++ ) {
		for ( j = 0 ; j < n;j++ ) {
			scanf("%d", &weigth);
			AdjList[i].push_back(ii (j, weigth));
		}
	}

	for( i = 0; i < n; i++) {
		if( d[i] == -1) {
		flood_fill( i, ++ncomponents);
		}
	}

	return 0;
}

