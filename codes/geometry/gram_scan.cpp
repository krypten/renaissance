#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

struct point  {
	int x, y;
};

point pivot;

int turn( point p, point q, point r ) {
	int result = (r.x - q.x)*(p.y - q.y) - (r.y - q.y)*(p.x - q.x);
	
	if( result < 0 ) return -1;
	if( result > 0 ) return 1;
	return 0;
}

bool left_turn (point p, point q, point r) {
	return (turn(p,q,r) > 0);
}

int area( point p, point q, point r) {
	return (p.x*q.y - p.y*q.x + q.x*r.y - q.y*r.x + r.x*p.y - r.y*p.x );
}

int dist( point p, point q) {
	int d1 = p.x - q.x;
	int d2 = p.y - q.y;
	return (d1*d1 + d2*d2);
}

bool ang_cmp (point p, point q) {
	if( area(pivot, p , q) == 0) {
		return (dist(pivot, p) < dist(pivot, q) );
	}

	int d1x = p.x - pivot.x ; 
	int d1y = p.y - pivot.y ;
	int d2x = q.x - pivot.x ; 
	int d2y = q.y - pivot.y ;

	return ( atan2((double) d1y, (double) d1x) - atan2((double) d2y, (double) d2x) < 0);
}

vector <point> grahamscan( vector <point> poly ) {
	int i, p = 0;
	int  n = poly.size();

	for( i = 1; i < n; i++) {
		if( poly[i].y < poly[p].y || ( poly[i].y == poly[p].y && poly[i].x > poly[p].x) ) {
			p = i;
		}
	}

	point temp = poly[0];
	poly[0] = poly[p];
	poly[p] = temp;

	pivot = poly[0];
	
	sort( ++poly.begin(), poly.end(), ang_cmp ) ;

	stack <point> S;
	point prev, now;

	S.push(poly[n-1]);
	S.push(poly[0]);

	i = 1;
	while (i < n) {
		now  = S.top();
		S.pop();
		prev = S.top();
		S.push(now);

		if ( left_turn ( prev, now, poly[i]) ) {
			S.push(poly[i]);
			i++;
		}
		else S.pop();
	}

	vector<point> hull;
	while( !S.empty() ) {
		hull.push_back(S.top());
		S.pop();
	}

	hull.pop_back();

	return hull;
}

int main() {
	int n;
	point tmp;
	vector <point> polygon;
	vector <point> result;
	
	scanf("%d", &n);

	for( int i = 0; i < n; i++) {
		scanf("%d %d", &tmp.x, &tmp.y);
		polygon.push_back(tmp);
	}

	result = grahamscan( polygon );

	return 0;
}
