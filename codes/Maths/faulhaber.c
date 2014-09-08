/*
algo : faulhaber's theorem
	sum of n to each power k
*/

#include <stdio.h>
#include <math.h>

int mod = 1000000007; 

int faul[] = { 1, 0.5, 1.0/6.0, 0, -1.0/30.0 , 0 ,1.0/42.0, 0, -1.0/30, 0, 5.0/66.0 , 0 };
int mod_inv[] = {1 , 2^-1, 3^-1, 4^-1, 5^-1, 6^-1, 7^-1, 8^-1, 9^-1 }; 

int cnr ( int n, int r) {
}

int main()
{
	int i;
	int n, k;

	scanf("%d %d", &n, &k);

	ans = 0;
	for (i = 0; i < k; i++) {
		ans = ans + cnr(k+1, 0) * mod(n, k- i, mod) * faul[i];
	}

	ans  = ans * mod_inv[k-1];

	printf("%d\n", ans);

	return 0;
}
