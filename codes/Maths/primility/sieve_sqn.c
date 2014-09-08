#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int main()
{
	int i, j;
	int t,n,m;
	int prime[4000];
	int size;
	int tmp;
	int start;

	size = 0;
	prime[size++] = 2;

	for( i = 3; i < 32000; i++) {
		bool flagp = true;
		tmp = sqrt(i);
		for( j = 0; j < size; j++) {
			if(prime[j] >= tmp) break;
			if(i%prime[j] == 0) {
				flagp = false;
			}
		}
		if(flagp == true) {
			prime[size++] = i;
		}
	}

	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &m, &n);
		if(m<2) m = 2;
		
		tmp = sqrt(n) + 1;
		
		bool isprime[100001];
		memset(isprime, true, sizeof(isprime));

		for( i = 0; i < size; i++) {
			int p = prime[i];

			if( p >= tmp) break;
			
			if(p >= m) start = p*2;
			else start = m + ((p - m%p)%p);
			
			for( j = start; j <=n; j += p) {
				isprime[j-m] = false;
			}
		}	

		for( i = m; i <= n; i++) {
			if(isprime[i-m] == true) {
				printf("%d\n", i);
			}
		}
		printf("\n");
  	}
	return 0;
}
