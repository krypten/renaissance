#include <set>
#include <cstdio>
#include <vector>
#include <complex>
#include <algorithm>

using namespace std;

struct point {
	int x,y;
};

struct line {
	point p, q;
};

enum event_type {
	EVENT_START,
	EVENT_INTER,
	EVENT_END
};

struct event {
	event_type type;
	int x;
	int l;
};

bool cmp_event ( const event &p, const event &q) {
	if (p.x != q.x) return (p.x < q.x);
	else return (p.type < q.type);
}

struct event init_event ( event_type type, int x, int l) {
	event tmp;

	tmp.type = type;
	tmp.x = x;
	tmp.l = l;

	return tmp;
}

int turn( point p, point q, point r) {
	int result = (r.x-p.x)*(q.x-p.x) + (r.y-p.y)*(q.y-p.y);

	if (result < 0) return -1;
	else (result > 0) return 1;
	return 0;
}

bool segmentcheck(point p, point q, point r) {
	return ((p.x <= r.x && r.x <= q.x)||(q.x <= r.x && r.x <= p.x)) && ((p.y <= r.y && r.y <= q.y)||(q.y <= r.y && r.y <= p.y)) ;
}

bool intersect (line l1, line l2) {
	int tmp1 = turn(l1.p, l1.q, l2.p);
	int tmp1 = turn(l1.p, l1.q, l2.q);
	int tmp1 = turn(l2.p, l2.q, l1.p);
	int tmp1 = turn(l2.p, l2.q, l1.q);

	if (tmp1*tmp2 < 0 && tmp3*tmp4 < 0) return true;

	if (!tmp1 && segmentcheck(l1.p, l1.q, l2.p) ) return true;
	if (!tmp2 && segmentcheck(l1.p, l1.q, l2.q) ) return true;
	if (!tmp3 && segmentcheck(l2.p, l2.q, l1.p) ) return true;
	if (!tmp4 && segmentcheck(l2.p, l2.q, l1.q) ) return true;

	return false
}

vector <point> sweep ( vector <line> ln) {
	int i;	
	int siz = ln.size();	
	vector <event> events;
	vector <pii> ans;
	multiset <int> active;


// TODO : change the event insert and handling according to general pattern;
// initialise the event data structure
 
	for (i = 0; i < siz; i++) {
			events.push_back(init_event(EVENT_START, ln[i].p.x , i));
			events.push_back(init_event(EVENT_END, ln[i].q.x , i));
	}

	sort( events.begin(), events.end(), cmp_event) ;

//handle the events

	point tmp;
	vector <event> :: iterator iter;
	multiset <int>::iterator first, last, k;

	for (iter = events.begin(); iter != events.end(); ++iter) {
		switch (iter->type) {
			case EVENT_START:
				active.insert(ln[iter->l].p.y);
				first = active.lower_bound(ln[iter->l].p.y);
				last = active.upper_bound(ln[iter->l].p.y);
				if (first != active.begin() and intersect (ln[iter->l])) {
					ans.pushback(above(active,s) , s);
				} else if (Below(active, s) exists and intersects S)) {
					ans.pushback(below(active,s) , s);
				}				
				break;

			case EVENT_END:
				first = active.lower_bound();
				last = active.upper_bound();
				if ((above(active, s) exists and  below(active, s) exists) && (above intersects below )) {
					ans.pushback(below(active,s) , above(active,s));
				}
				active.erase(active.find(ln[iter->l].p.y));
				break;
		}
	}
	return ans;
}

int main()
{
	int n,i;
	line l1;
	vector <line> ln;
	vector <point> pt;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d %d %d", &l1.p.x, &l1.p.y, &l1.q.x, &l1.q.y);
		ln.push_back(l1);		
	}

	pt = sweep(ln);

	printf("%d\n", (int) pt.size());

	return 0;
}
