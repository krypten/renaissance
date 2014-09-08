#include <cstdio>
#include <vector>

using namespace std;

struct point {
	int x, y;
};

struct line {
	point p,q;
};

int turn (point p, point q, point r) {
	int result = (r.x - p.x) * (q.y - p.y) - (r.y - p.y)*(q.x - p.x);
	
	if( result > 0) return 1;
	if( result < 0) return -1;
	return 0;
}

bool checkpoint ( point p, point q, point r) {
	return ( ((p.x <= r.x && r.x <= q.x) || (q.x <= r.x && r.x <= p.x)) && ((p.y <= r.y && r.y <= q.y) || (q.y <= r.y && r.y <= p.y)) );
}

bool intersect (line l1, line l2) {
	int tmp1, tmp2, tmp3, tmp4;
	
	tmp1 = turn(l1.p, l1.q, l2.p);
	tmp2 = turn(l1.p, l1.q, l2.q);
	tmp3 = turn(l2.p, l2.q, l1.p);
	tmp4 = turn(l2.p, l2.q, l1.q);

	if( tmp1*tmp2 < 0  && tmp3*tmp4 < 0) return true;

	if( !tmp1 && checkpoint(l1.p, l1.q, l2.p)) return true;
	if( !tmp2 && checkpoint(l1.p, l1.q, l2.q)) return true;
	if( !tmp3 && checkpoint(l2.p, l2.q, l1.p)) return true;
	if( !tmp4 && checkpoint(l2.p, l2.q, l1.q)) return true;

	return false;
}

int main()
{
	struct line l1, l2;

	scanf("%d %d %d %d", l1.p.x, l1.p.y, l1.q.x, l1.q.y);
	scanf("%d %d %d %d", l2.p.x, l2.p.y, l2.q.x, l2.q.y); 
	printf("Intersect %d\n", intersect(l1, l2));

	return 0;
}
