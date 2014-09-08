#include <cstdio>
#include <queue>
#include <vector>

#define MAXN 100028
using namespace std;

typedef pair<int,int> ii;

priority_queue <pair <int, ii > >  EdgeList;
vector <int> pset(MAXN);

void initset(int u) {
      for( int i = 0; i < u; i++) {
            pset[i] = i;
      }
}

int findset(int u) {
      return ( (pset[u] == u) ? u : (pset[u] = findset(pset[u])));
}

void unionset( int u, int v) {
      pset[findset(u)] = findset(v);
}

bool sameset(int u , int v) {
      return (findset(u) == findset(v));
}

int main()
{
      int u, v;
      int n, m;
      int weigth;
      long long int mst_cost;

      scanf("%d %d", &n, &m);

      for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &weigth);
            EdgeList.push( pair<int , ii> (-weigth, ii (u , v)));
      }

      mst_cost = 0;
      initset(n+1);

      while(!EdgeList.empty()) {
            pair<int, ii > front = EdgeList.top();
            EdgeList.pop();

            if(!sameset(front.second.first, front.second.second)) {
                  mst_cost -=  front.first;
                  unionset(front.second.first, front.second.second);
            }
      }

      printf("%lld\n", mst_cost);

      return 0;
}
