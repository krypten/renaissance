/* sieve bit wise with space optimisation

MAX -> largest prime possible in range;
LMT-> sqrt of largest possible prime;
LEN-> no. of prime till largest possible prime;
flag[] -> range MAX/64;
prime[] -> list of prime i.e. prime[1] = 2, prime[2] = 3;

*/

#include <stdio.h>
#include <stdlib.h>

const int MAX = 86044176;
const int LMT = 9267;
const int LEN = 5000000;

int flag[1344440];
int prime[5000005];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve()
{
      int i,j,k;
      for(i = 3; i < LMT;i+=2) {
            if(!ifc(i))
            for(j = i*i, k = i<<1; j <MAX; j+= k)
                  isc(j);
      }
      prime[1] = 2;
      for(i = 3,j = 2; i <MAX && j<= LEN; i+=2)
            if(!ifc(i))
                  prime[j++] = i;
}

int main() {
      int t;
      int n;
      scanf("%d", &t);
      sieve();

      while(t--) {
            scanf("%d", &n);
            printf("%d\n", prime[n]);
      }
      return 0;
}
