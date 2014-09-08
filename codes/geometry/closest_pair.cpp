#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits>

#define INF numeric_limits<double>::max()

typedef struct point {
	double x,y;
	int ind;
} point;

double best;
point * strip;
point * pointbyx, *pointbyy;
point result1, result2;

using namespace std;
double dist (point p, point q) {
	return sqrt( (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y) );
}

bool order_x( const point &p, const point &q) {
	return (p.x < q.x);
}

bool order_y(point p, point q) {
	if (p.y < q.y) return true;
	else if (p.y > q.y) return false;
	return (p.x < q.x);
}

void merge( int low, int mid, int high) {

	int i, j, k ;	

	for (i = low; i <= high; i++) {
		strip[i] = pointbyy[i];
	}

	i = low; j = mid+1; k = low;

	while ( i < (mid+1) && j <= high) {
		pointbyy[k++] = order_y(strip[i], strip[j]) ? strip[i++] : strip[j++] ;
	}

	while (i < (mid+1)) {
		pointbyy[k++] = strip[i++];
	}
}

double closest_pair (int low, int high) {
	if (high <= low) return INF;

	int mid = (high+low)/2 ;

	double delta1 = closest_pair( low, mid );
	double delta2 = closest_pair( mid+1, high );

	if (delta2 < delta1) {
		delta1 = delta2;
	}

	merge (low, mid, high); 

	int m = 0; 
	int i, j;
	for (i = low; i <= high; i++) {
		if (abs(pointbyy[i].x - pointbyx[mid].x) < delta1) {
			strip[m++] = pointbyy[i];
		}
	}

	double distance;
	for (i = 0; i < m; i++) {
		for (j = i+1; (j < m && ((strip[j].y - strip[i].y) < delta1)); j++) {
			distance = dist(strip[i], strip[j]);
			if (distance < delta1) {
				delta1 = distance;
				if (delta1 < best) {
					best = delta1;
					result1 = strip[i];
					result2 = strip[j];
				}
			}
		}
	}

	return delta1;
}
  
int main()
{
	int n, i;
	scanf("%d", &n);

	pointbyx = new point[n];

	for (i = 0; i < n; i++) {
		scanf("%lf %lf", &pointbyx[i].x, &pointbyx[i].y);
		pointbyx[i].ind = i;
	}

	if (n <= 1) return 0;

	sort( pointbyx, pointbyx + n, order_x);

	pointbyy = new point[n];
	strip = new point[n];

	for (i = 0; i< n; i++) {
		pointbyy[i] = pointbyx[i]; 
	}

	best = INF;

	closest_pair(0,n-1);

	printf("%lf %lf\n", result1.x, result1.y);
	printf("%lf %lf\n", result2.x, result2.y);

	printf("%lf\n", best);

	return 0;
}
