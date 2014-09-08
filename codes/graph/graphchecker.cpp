#include <cstdio>
#include <map>
#include <vector>

using namespace std;

typedef pair <int,int> ii;
typedef vector <ii> vii;
vector <vii> AdjList;
vector <int> d;
vector <int> parent;

void graphchecker(int u) {
	int i;
	d[u] = 2;
	for( i = 0; i < AdjList[u].size() ; i++) {
		ii v= AdjList[u][i];
		if( d[v.first] == -1) {
			//printf("TREE EDGE\n");
			parent[v.first] = u;
			graphchecker(v.first);
		}
		else if(d[v.first] == 2) {
			if( v.first == parent[u]) {
				//printf("BIDIRECTIONAL\n");
			} else {
				//printf("Back edge\n");
			}
		} else if(d[v.first] == 1) {
			//printf("FORWARD or CROSS\n");
		}	
	}
	d[u] = 1;
}

int main()
{
	int i, j;
	int n;
	int weigth;
	int source;
	int ncomponents = 0;

	scanf("%d", &n);

	d.assign(n, -1);
	parent.assign(n, -1);
	AdjList.assign(n, vii());

	for ( i = 0 ; i < n;i++ ) {
		for ( j = 0 ; j < n;j++ ) {
			scanf("%d", &weigth);
			AdjList[i].push_back(ii (j, weigth));
		}
	}

	source = 0;
	graphchecker(source);

	return 0;
}

