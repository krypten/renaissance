#define MAXV 1000000000

using namespace std;
typedef vector <pair <int, int> > vii;

vector <vii>  AdjList;
vector <int> dist;
queue <int> q;

int main()
{
	int i;
	int n, m;
	int u, v;
	int source;

	scanf("%d %d", &n, &m);

	dist(n, MAXV);
	AdjList.assign(n, vii());
	q.clear();

	for( i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		AdjList[u].push_back( pair<int, int> (v, 1));
	}

	source = 0;
	q.push(source);
	dist[s] = 0;

	while( !q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < (int) AdjList[u].size(); i++) {
			pair<int, int> v = AdjList[u][i];
			if( dist[v.first] == MAXV) {
				dist[v.first] = dist[u] + 1;
			}
			q.push(v.first);
		}
	}

	return 0;
}
