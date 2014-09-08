/* bfs serach
S-> Source symbol
D-> Destination Symbol
* -> Wall
count -> current path length
*/

#include <cstdio>
#include <cstring>
#include <queue>

#define MAXR 128
#define MAXC 128
#define INF 100000000

using namespace std;

int n, m;
int maxi;
char arr[MAXR][MAXC];
int visited[MAXR][MAXC];
int cnt[MAXR][MAXC];

void bfs(int i , int j, int count) {
	queue <int> depth;
	queue <pair <int, int> >q;

	q.push ( pair <int ,int> (i, j ));
	depth.push(count);

	while( ! q.empty() ) {
		pair <int, int> V = q.front();
		count = depth.front();

		i = V.first;
		j = V.second; 

		q.pop();
		depth.pop();	
		
		if( visited[i][j] == 1) continue ;
		if(arr[i][j] == 'D') {
			printf("OK %d\n", count);
			cnt[i][j] = count;
			maxi = count;
			return ;
		}

		visited[i][j] = 1;
		cnt[i][j] = count;

		if( j > 0 && arr[i][j-1] != '*') {
			q.push(pair <int, int> (i, j-1));
			depth.push(count+1); 
		} if( j < m-1 && arr[i][j+1] != '*') {
			q.push(pair <int, int> (i, j+1));
			depth.push(count+1); 
		} if( i > 0 && arr[i-1][j] != '*') {
			q.push(pair <int, int> (i-1, j));
			depth.push(count+1); 
		} if( i < n-1 && arr[i+1][j] != '*') {
			q.push(pair <int, int> (i+1, j));
			depth.push(count+1);
		}
	}
} 																																																																																												

int main()
{
	int i ,j;
	int src_i, src_j;	
	int dest_i, dest_j;
	int flag, flag1;
	int len;

	scanf("%d %d", &n, &m);

	memset(arr, 0, sizeof(arr));
	memset(visited, 0, sizeof(visited));
	memset(cnt, -1, sizeof(cnt));

	flag = 1;
	flag1= 0;

	for(i = 0; i < n; i++) {
		scanf("%s", arr[i]);
		if(flag || flag1) {
			for(j = 0; j < m; j++) {
				if(arr[i][j] == 'S') {
					src_i = i;
					src_j = j;
					flag = 0;
				} /*else if( arr[i][j] =='D') {
					dest_i = i;
					dest_j = j;
					flag1  = 0;
				}  */
			}
		}
	}

	printf("%d %d\n", src_i, src_j);

	maxi = INF;
	bfs(src_i, src_j, 0);

	if( maxi == INF) printf("NOT FOUND\n");
	else printf("FOUND path length %d\n", maxi);

	return 0;
}
