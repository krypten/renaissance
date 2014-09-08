/* Fermet little theorem based pseudo primility testing
*/

#include <stdio.h>

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

int main()
{
	type in;
	type tmp;
	tmp = mod_exp(128, 32, 1000000007);

	if ( tmp == 0 ) {
		printf("Composite\n");
	} else {
		printf("%lld\n", tmp);
	}

	return 0;
}
