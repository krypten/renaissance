#include <stdio.h>
#include <string.h>
#include <math.h>

short int arr[1000000004];

void seive(long long int n) {
	long long int i;
	long long int j;
	long long int tmp;
	tmp = sqrt(n);

	for( i = 2; i < tmp; i++) {
		if(arr[i] == 0) {
		for(j = i+i; j < n; j = j + i ) {
			arr[j] = 1;}}
	}
}		


int main()
{
	int t;
	long long int i;
	long long int n;
	long long int m;
//	time_t time1;
//	time_t time2;

	memset(arr , 0 , sizeof(arr));
	arr[0] = 1;
	arr[1] = 1;

//	(void) time(&time1);
	seive(1000000002);
	scanf("%d", &t);
//	(void) time(&time2);
//	printf("%ld\n", time2 - time1);

	while(t--) {
		scanf("%lld %lld", &m, &n);
		for( i = m; i <= n; i++ ) {
			if(arr[i] == 0) {
				printf("%lld\n", i);
			}
		}
		printf("\n");
	}
	return 0;
}
