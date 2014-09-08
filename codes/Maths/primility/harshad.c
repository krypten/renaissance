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
			var  = (var*mult)%q;
		}
		mult = (mult*mult)%q;
		n = n>>1;
	}
	return var;
}

int power2 ( type n , type * u)
{
	type var;
	for (var = 0; n%2 == 0; (n = n>>1)&& var++);
	*u = n;
	return var;
}

int witness(type a,type n)
{
	type i;
	type t;
	type u;
	type x;
	type y;

	t = power2(n-1, &u);
	y = mod_exp(a, u, n);
	
	for (i = 0; i < t; i++) {
		x = y*y%n ;
		if (x == 1 && y != 1 && y != n-1) {
			return 1;
		}
		y = x;
	}
	if ( y != 1 ) {
		return 1;
	}
	
	return 0;
}

int miller_rabin(type n)
{
	type j;
	type a;

	if(n<2) return 0;
	//if(n == 2) return 1;
	if(n != 2 && n%2 == 0) return 0;

	for (j = 0; j < 2; j++) {
		a = rand() % (n-1) + 1 ;
		if ( witness(a, n) ) {
			return 0;
		}
	}
	return 1;
}

 int main()
 {
        int *v;
        v= (int *)malloc(sizeof(int)*1000001);
        int j1, j2, j3, j4, j5, j6, s, n=0;
        int s1, s2, s3, s4, s5;
        for (j6=0; j6<10; j6++) {
            for (j5=0; j5<10; j5++) {
            s5 = j6 + j5;
                for (j4=0; j4<10; j4++) {
                s4 = s5 + j4;
                    for (j3=0; j3<10; j3++) {
                    s3 = s4 + j3;
                        for (j2=0; j2<10; j2++) {
                        s2 = s3 + j2;
                            for (j1=0; j1<10; j1++) {
                                v[s2 + j1 + n++] = 1;
                            }
                        }
                    }
                }
            }
        }
v[1] = 1;
       int t;
        scanf("%d", &t);
        while(t--){
           int m,n;
           scanf("%d%d", &m, &n);

           int count =0;
           int num;
        for(num = m; num <= n; num++){
          if(v[num] == 0){
		printf("%d\n", num);
            if(num % 2 == 0){
                continue;
            } else if(miller_rabin(num)){
                    count ++;
			printf("\t%d\n", num);
                }
            }
        }
            printf("%d\n",count);
        }
        return 0;
 }

