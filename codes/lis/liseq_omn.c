#include <stdio.h>
#include <string.h>

#define MAX 100

int LCS_LENGTH(int * s1, int m, int * s2, int n)
{
	int length[MAX][MAX];
	int i;
	int j;

	for (i = 0; i <= m; i++) {
		length[i][0] = 0;
	}
	for (i = 0; i <= n; i++) {
		length[0][i] = 0;
	}
	
	for (i = 1; i <= m; i++) { 
		for (j = 1; j <= n; j++) {
			if (s1[i-1] < s2[j-1]) {
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
	int str1[MAX];
	int str2[MAX];
	int len1;
	int len2;

	scanf("%d %d", &len1,&len2);

	for (i = 0; i < len1; i++) {
		scanf("%d", &str1[i]);
	} for (i = 0; i < len2; i++) {
		scanf("%d", &str2[i]);
	}

	printf("%d\n", LCS_LENGTH(str1, len1, str2, len2));
	return 0;
}
