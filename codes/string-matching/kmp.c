/* TODO : CORECT THE Algorithm for 1 length string patter*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 128
#define MAXPTR 64

void compute_prefix(char * st , int * pie)
{
	int len;
	int k;
	int q;
	
	len = strlen(st);
	
	pie[0] = 0;

	k = 0;

	for (q = 1; q < len; q++) {
		while(k  > 0 && st[k+1] != st[q]) {
			k = pie[k];
		}
		if ( st[k+1] == st[q] ) {
			k++;
		}
		pie[q] = k;
	}
}

void kmp_matcher( char * str, char * pattern)
{
	int n;
	int m;
	int q;
	int i;
	int * pie;

	n = strlen(str);
	m = strlen(pattern);
	q = 0;

	pie = (int *) malloc(sizeof(int)*m);
	compute_prefix(pattern, pie);

	for (i = 0; i <n; i++) {
		while ( q > 0 && pattern[q+1] != str[i]) {
			q = pie[q];
		}
		if (pattern[q+1] == str[i]) {
			q++;
		} if ( q == m - 1) {
			printf("Pattern with shift %d\n", i - m + 2);
			q = pie[q];
		}
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

	kmp_matcher(str, pattern);

	return 0;
}
