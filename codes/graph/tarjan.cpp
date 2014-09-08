#include <vector>
#include <stack>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector <ii> vii;

vector <vii> AdjList;
vector <int> d_num;
vector <int> d_low;
vector <int> visited;
stack <int> S;

int ctr;
int ctr2;

void tarjanSCC( int u) {
	int i,j;

	d_low[u] = d_num[u] = ctr++;
	S.push(u);
	visited[u] = 1;

	//printf("OK");

	for(int j = 0; j < (int) AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if( d_num[v.first] == -1) {
			tarjanSCC(v.first);}
		if(visited[v.first]) {
			d_low[u] = min(d_low[u], d_low[v.first]);
		}
	}

	if(d_low[u] == d_num[u]) {
		printf("SCC %d: " , ++ctr2);
		while(!S.empty() && S.top() != u) {
			int vt = S.top();
			S.pop();
			printf("%d ", vt);
			if( u == vt) break;
		}
		printf("\n");
	}
} 

int main()
{
	int n, m;
	int i, j;
	int u, v;
	ctr = 0;

	scanf("%d %d", &n, &m);
	
	d_num.assign(n+1, -1);
	d_low.assign(n+1, -1);
	visited.assign(n+1, 0);
	AdjList.assign(n+1, vii());

	for( i = 0; i < m; i++) {
		scanf("%d %d", &u ,&v);
		AdjList[u].push_back(ii (v, 1));
		//AdjList[v].push_back(ii (u, 1));
	//	printf("%d", 21);
	}

	ctr = 0;
	ctr2 = 0;

	tarjanSCC(0);
	printf("\n%d\n", ctr2);

	return 0;
}
