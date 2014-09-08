#include <stdio.h>

#define MAX 5

void floyd(int (*d)[][MAX],int (*pie)[][MAX], int n)
{
      int i;
      int j;
      int k;

      for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                  for (j = 0; j < n; j++) {
                        if ((*d)[i][k] + (*d)[k][j] < (*d)[i][j]) {
                              (*d)[i][j] = (*d)[i][k] + (*d)[k][j];
                              (*pie)[i][j] = (*pie)[k][j];
                        }
                  }
            }
      }
}

void print_shortest_path(int pie[][MAX], int s, int v)
{
      if (s == v) {
            printf("%d\n", s);
      }
      else if (pie[s - 1][v - 1] == s) {
            printf("-> %d", v);
      } else {
           printf("-> %d", pie[s - 1][v - 1]);
           print_shortest_path( pie, pie[s - 1][v - 1], v);
      }
}


int main()
{
      int i;
      int j;
      int n;
      int source;
      int destination;
      int adj[MAX][MAX] = {0};
      int pie[MAX][MAX] = {0};

      n = 3;
/*      scanf("%d", &n);      */

      for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                  scanf("%d", &adj[i][j]);
            }
      }
      scanf("%d %d", &source, &destination);

       for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                  if (i == j)
                        pie[i][i] = 0;
                  else
                        pie[i][j] = i + 1;
            }
      }

      floyd(&adj, &pie, n);

      for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                  printf("%d ", adj[i][j]);
            }
            printf("\n");
      }
      printf("%d ", source);
      print_shortest_path(pie, source, destination);

      return 0;
}
