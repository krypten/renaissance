#include <cstdio>
#include <map>
#include <vector>

#define BLACK 1
#define WHITE -1

using namespace std;
typedef vector <pair<int,int> > vii;

vector <vii> AdjList;
vector <int> bfs_num;

void bfs(int u) {
	printf("%d", u);
	dfs_num[u] = BLACK;
	for( vii::iterator it = AdjList[u].begin(); it != AdjList[u].end(); it++ ) {
		if(dfs_num[it->first] == WHITE ) {
			dfs(it->first);
		}
	}
}

int main()
{
	int i, j;
	int n;
	int source;
	int weigth;

	scanf("%d", &n);

	bfs_num.assign(n, WHITE);
  	AdjList.assign(n, vii());
	
	for (i = 0; i < n; i++) {
    		for (j = 0; j < n; j++) {
      			scanf("%d", &weigth);
			if( weigth != 0) AdjList[i].push_back(pair <int, int> (j, weigth));
    		}
  	}

	source = 0;
	bfs(source);

	for (i = 0; i < n; i++) {
		printf("%d ", bfs_num[i]);
	}
	return 0;
}
