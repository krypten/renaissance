#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>	
using namespace std;
typedef vector <pair<int,int> > vii;
typedef pair <int, int> ii;

vector <vii> AdjList;
vector <int> d_num;
vector <int> topo;

void toposort(int u) {
	int i;
	printf("%d ", u);
	d_num[u] = 1;
	for(i = 0; i < (int) AdjList[u].size(); i++) {
		ii v = AdjList[u][i];		
		if(d_num[v.first] == -1 ) {
			toposort(v.first);
		}
	}
	topo.push_back(u);
}

int main()
{
	int i;
	int n, m;
	int u, v;
	//int source;

	scanf("%d %d", &n, &m);

	topo.clear();
	d_num.assign(n+1, -1);
  	AdjList.assign(n+1, vii());
	
	for (i = 0; i < m; i++) {
    		scanf("%d %d", &u, &v);
		AdjList[u].push_back(pair <int, int> (v, 1));
    		AdjList[v].push_back(pair <int, int> (u, 1));
  	}

	for(i = 0; i < n; i++) {
		if( d_num[i] == -1) {
			toposort(i);
		}
	}

	reverse(topo.begin(), topo.end());

	for( i = 0; i < (int) topo.size(); i++) {
		printf("%d\n", topo[i]);
	}

	return 0;
}
