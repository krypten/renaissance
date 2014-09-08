#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
  int V, E, s, u, v, w;
  vector<vii> AdjList;

  scanf("%d %d", &V, &E);
s = 0;
  AdjList.assign(V, vii()); // assign blank vectors of pair<int, int>s to AdjList
  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &u, &v, &w);
    AdjList[u-1].push_back(ii(v-1, 100-w));
    AdjList[v-1].push_back(ii(u-1, 100-w));                              //undirected graph
  }

  // Dijkstra routine
  vi dist(V, INF); dist[s] = 0;
  vi parent(V, INF); parent[s] = -1;                    // INF = 1B to avoid overflow
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(dist[s], s));
                             // ^to sort the pairs by increasing distance from s
  while (!pq.empty()) {                                             // main loop
    ii front = pq.top(); pq.pop();     // greedy: pick shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d > dist[u]) continue;   // this check is important, see the explanation
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      ii v = AdjList[u][j];                       // all outgoing edges from u
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second;
		parent[v.first] = u;                 // relax operation
        pq.push(ii(dist[v.first], v.first));
  } } }  // note: this variant can cause duplicate items in the priority queue
int p;
int tmp;
double qw = 100;
p = V-1;
printf("%d\n", AdjList[4][2].second);
while ( p != 0) {

	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		tmp = parent[p];		
		if ( tmp == AdjList[p][j].first)	
			qw = (qw*(100-AdjList[p][j].second))/100.0;
printf("%d\n", AdjList[p][j].second);
			break;
		}

		std::cout << tmp << p << " " << qw; 
	p = tmp;
}
  for (int i = 0; i < V; i++) // index + 1 for final answer
    printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);

	printf("%lf percent\n", qw); 
  return 0;
}
