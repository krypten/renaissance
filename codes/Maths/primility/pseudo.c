/* Fermet little theorem based pseudo primility testing
*/

#include <stdio.h>
#include <stdlib.h>

#define type long long int

type mod_exp (type a, type n, type q)
{
	type var = 1;
	type mult = a;
	while ( n != 0 ) {
		if (n%2 == 1) {
			var  = var * mult % q;
		}
		mult = mult * mult % q;
		n = n>>1;
	}
	return var;
}

int pseudoprime( type n)
{
	if (mod_exp(2, n-1, n) == 1){
		if(n > 16) {
			if (mod_exp(rand()%n,n-1, n) == 1)
			return 1;
		} else {
			return 1;
		}
	}
	return 0;
}

int main()
{
	type in;
	type tmp;
	scanf("%lld", &in);
	tmp = pseudoprime(in);
	if ( tmp == 0 ) {
		printf("Composite\n");
	} else {
		printf("Prime\n");
	}

	return 0;
}
