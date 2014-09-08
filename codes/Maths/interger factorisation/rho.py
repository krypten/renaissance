import random

def gcd (a, b):
	if(a%b == 0):
		return b
	return gcd(b, a%b)

def pollard(n):
	x = [1 for i in range(n*n+1)];
	i = 1
	x[1] = random.randrange(n)
	y = x[1];
	k = 2;
	d = 1
	while d == 1:
		i += 1
		x[i] = ((x[i-1])**2 - 1) % n;
		d = gcd( y - x[i], n)
		if( d != 1 and d != n) :
			print d
		if( i == k ):
			y = x[i]
			k = 2*k

pollard(1024)
		
