/* dfs serach -> little optimised to overcome subproblem
S-> Source symbol
D-> Destination Symbol
* -> Wall
count -> current path length
*/

#include <cstdio>
#include <cstring>

#define MAXR 128
#define MAXC 128
#define INF 100000000

int n, m;
int maxi;
char arr[MAXR][MAXC];
int visited[MAXR][MAXC];

void dfs( int i , int j, int count) {
	if( visited[i][j] == 1) return ;
	if( count > maxi)  return;
	if(arr[i][j] == 'D') {
		printf("OK %d\n", count);
		if(count < maxi) maxi = count;
		return ;
	}
	visited[i][j] = 1;

	if( j > 0 && arr[i][j-1] != '*')
		dfs(i, j-1, count + 1); 
	if( j < m-1 && arr[i][j+1] != '*')
		dfs(i, j+1, count + 1); 
	if( i > 0 && arr[i-1][j] != '*')
		dfs(i-1, j, count + 1); 
	if( i < n-1 && arr[i+1][j] != '*')
		dfs(i+1, j, count + 1);  
	visited[i][j] = 0;
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
	dfs(src_i, src_j, 0);

	if( maxi == INF) printf("NOT FOUND\n");
	else printf("FOUND path length %d\n", maxi);

	return 0;
}
