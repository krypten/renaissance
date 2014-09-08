#include <stdio.h>
#include <string.h>

#define MAX 100

int LCS_LENGTH(char * s1, char * s2)
{
	int length[MAX][MAX];
	int i;
	int j;
	int n;
	int m;

	m = strlen(s1);
	n = strlen(s2);

	for (i = 0; i <= m; i++) {
		length[i][0] = 0;
	}
	for (i = 0; i <= n; i++) {
		length[0][i] = 0;
	}
	
	for (i = 1; i <= m; i++) { 
		for (j = 1; j <= n; j++) {
			if (s1[i-1] == s2[j-1]) {
				length[i][j] = length[i-1][j-1] + 1;
			} else if (length[i-1][j] < length[i][j-1]) {
				length[i][j] = length[i][j-1];
			} else {
				length[i][j] = length[i-1][j];
			}
			/*printf("%d", length[i][j]);*/
		}
		/*printf("\n"); */
	}

	return length[m][n];
}

int main()
{
	char str1[MAX];
	char str2[MAX];

	scanf("%s", str1);
	scanf("%s", str2);

	printf("%d\n", LCS_LENGTH(str1, str2));
	return 0;
}
