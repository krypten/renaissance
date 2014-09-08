#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 128
#define MAXPTR 64

void naive_matcher( char * str, char * pattern)
{
	int n;
	int m;
	int s;
	int i;
	int flag = 0;

	n = strlen(str);
	m = strlen(pattern);

	for (s = 0; s <= n - m; s++) {
		flag = 0;
		for (i = 0; i < m; i++) {
			if (pattern[i] != str[s+i]) {
				flag = 1;
				break;
			}

		}
		if ( flag == 0) {
			printf("Pattern with shift %d\n", s + 1);
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

	naive_matcher(str, pattern);

	return 0;
}
