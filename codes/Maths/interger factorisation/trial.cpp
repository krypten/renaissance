#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef pair <long long int, int> ii;
vector <ii> v;

#define MAX 31629376
#define LMT 5624
#define LEN 1952340

int flag[MAX/64];
int prime[LEN];
unsigned int pri;

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
	pri= j;
}

int main()
{
	int i;
	int ctr;
	long long int n;
	long long int tmp2;
	long long int tmp;
	sieve();
	while(1) {
		scanf("%lld", &n);
		if( n == 0) break;
		v.clear();
		
		for ( i = 1; i < pri && prime[i] <= (n); i++) {
			if(n%prime[i] == 0) {
				ctr = 0;
				while((n%prime[i]) == 0 && n > 0) {
					n = n/prime[i];
					ctr++;
				}
				v.push_back(ii (prime[i], ctr));
			}
		}
		if(n>1) v.push_back(ii (n, 1)) ;

		for( i = 0; i <	 (int) v.size() - 1; i++) {
			printf("%lld^%d ", v[i].first, v[i].second);
		}
		printf("%lld^%d\n", v[i].first, v[i].second);
	}
	return 0;
}
