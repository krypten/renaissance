#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

#define MAXN 100
#define N 100000000
using namespace std;

int arr[MAXN][MAXN];
bool check[N];

vector<int> bfs (int n,int m) {// node start
	int i;
	queue <int> q;
	vector <int> result;
	//s.push(start);

	q.push(0);
        
	while( !q.empty()) {
		i = q.front();
		q.pop();
 
		if(check[i] == false ) {
			result.push_back(i);
			check[i] = true;
		}
          	
        	for(int j = 0; j < m; j++) {
            		if ((i != j) && (arr[i][j] > 0) && check[j] == false ) {
            		        q.push(j);
            		}
       		}
	}
        
	return result;
}

int main()
{
	int i,j;
	int n,m;
	int t;
	vector <int> d;
	
	scanf("%d", &t);
	while( t--) {
		memset(check,false, sizeof(check));
		scanf("%d %d", &n, &m);

		for( i = 0; i< n; i++) {
			for( j = 0; j < m; j++ ) {
				scanf("%d", &arr[i][j]);
			}
		}

		d = bfs(n,m);
	
		for( i = 0 ; i < d.size(); i++ ) {
			printf("%d ", d[i] + 1);
		}
		d.clear();
	}
	return 0;
}

