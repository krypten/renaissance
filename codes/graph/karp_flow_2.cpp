#include <map>
#include <queue>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cstring>
#include <algorithm>

#define INF 1000000
#define MAX_V 40

using namespace std;

int f, s, t;
int p[MAX_V];
int AdjMat[MAX_V][MAX_V];
vector< vector<int> > AdjList;

void augment(int u, int minedge) {
      if (u == s) {
            f = minedge;
            return;
      } else if (p[u] != -1) {
            augment(p[u], min(minedge, AdjMat[p[u]][u]));
            AdjMat[p[u]][u] -= f;
            AdjMat[u][p[u]] += f;
      }
}

int main()
{
      int v, w, n;
      int m, i, j;

      scanf("%d %d %d", &n, &s, &t);
      memset(AdjMat, 0, sizeof(AdjMat));
      AdjList.assign(n, vector <int>() );

      for (i = 0; i < n; i++) {
            scanf("%d", &m);
            for (j = 0; j < m; j++) {
                  scanf("%d %d", &v, &w);
                  AdjMat[i][v] = w;
                  AdjList[i].push_back(v);
            }
      }

      int max_flow = 0;
      while (1) {
            f = 0;
            bitset <MAX_V> dist;
            queue <int> q;

            q.push(s);
            dist[s] = true;
            while (!q.empty()) {
                  int u = q.front();
                  q.pop();

                  if (u == t) break;

                  for (int j = 0; j < AdjList[u].size(); j++) {
                        v = AdjList[u][j];
                        if (AdjMat[u][v] > 0 && !dist[v]) {
                              dist[v] = true;
                              p[v] = u;
                              q.push(v);
                        }
                  }
            }

            augment(t, INF);
            if (f == 0) break;
            max_flow += f;
      }

      printf("%d\n", max_flow);
      return 0;
}
