/* TODO : Correct the error in the rabin karp programs*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 128
#define MAXPTR 64

void str_int(char * st)
{
	int i;
	int len;

	len = strlen(st);

	for ( i = 0; i < len; i++) {
		st[i] = st[i] - '0';
	}

}
long long int mod_exp( long long int n, long long int b, long long int p)
{
	long long int var = 1;
	long long int mult = n;

	while (b > 0) {	
		if ( b%2 == 0 ) {
			var = var * mult % p;
		}
		mult = (mult * mult) % p;
		b = b>>1;
	}
	return var;
}

void rabin_karp ( char * str, char * pattern, int d, long long int prime)
{
	int n;
	int m;
	int s;
	int i;
	int p;
	int t;
	int h;
	int flag;

	n = strlen(str);
	m = strlen(pattern);
	h = mod_exp(d, m-1, prime);
	p = 0;
	t = 0;

	for (i = 0; i < m; i++) {
		p = (d * p + pattern[i]) % prime;
		t = (d * t + str[i] ) % prime;
	}

	printf("%d\n", t);		
	for ( s = 0; s <= n - m; s++) {
		flag = 0;
		if (p == t) {
			for ( i = 0; i < m; i++) {
				if (pattern[i] != str[s+i]) {
			 		flag = 1;
					break;
				}
			}
			if ( flag == 0) {
				printf("Pattern with shift %d\n", s + 1);
			}
		}
		if (s <= n - m) {
			t = (d*(t - str[s + 1] * h) + str[s+m]) % prime;
		}
		printf("%d\n", t);
	}
}

int main()
{
	char * str;
	char * pattern;

	str = (char * ) malloc(sizeof(char) * MAXSTR);
	pattern = (char *) malloc(sizeof(char) * MAXPTR);

	scanf("%s", str);
	scanf("%s", pattern);
	
	str_int(str);
	str_int(pattern);
	
	rabin_karp(str, pattern, 10, 10100101);

	return 0;
}
