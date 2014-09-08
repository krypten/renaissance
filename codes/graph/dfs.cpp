#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>

#define MAXN 100
#define N 100000000
using namespace std;

int arr[MAXN][MAXN];
bool check[N];

vector<int> dfs (int n,int m) {// node start
	int i;
	stack <int> s;
	vector <int> result;
	//s.push(start);

	for(i = n-1; i >= 0; i--) s.push(i);
        
	while( !s.empty()) {
		i = s.top();
		s.pop();
	 
		if(check[i] == false ) {
			result.push_back(i);
			check[i] = true;
		}
          	
        	for(int j = m-1; j >= 0; j--) {
            		if ((i != j) && (arr[i][j] > 0) && check[j] == false ) {
            		        s.push(j);
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

		d = dfs(n,m);
	
		for( i = 0 ; i < d.size(); i++ ) {
			printf("%d ", d[i] + 1);
		}
		d.clear();
	}
	return 0;
}

