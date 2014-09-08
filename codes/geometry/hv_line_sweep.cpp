/* 
	check if horizontal and vertical lines intersect
*/

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
	

vector <point> sweep ( vector <line> ln) {
	int i;	
	int siz = ln.size();	
	vector <event> events;
	vector <point> ans;
	multiset <int> active;

// initialise the event data structure
 
	for (i = 0; i < siz; i++) {
		if (ln[i].p.y != ln[i].q.y) {
			events.push_back(init_event(EVENT_INTER, ln[i].p.x , i));
		} else {
			events.push_back(init_event(EVENT_START, ln[i].p.x , i));
			events.push_back(init_event(EVENT_END, ln[i].q.x , i));
		}
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
				break;

			case EVENT_END:
				active.erase(active.find(ln[iter->l].p.y));
				break;
			case EVENT_INTER:
				first = active.lower_bound(ln[iter->l].p.y);
				last = active.upper_bound(ln[iter->l].q.y);

				for (k = first; k != last; ++k) {
					tmp.x = iter->x; tmp.y = *k;
					ans.push_back(tmp);
				}
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
