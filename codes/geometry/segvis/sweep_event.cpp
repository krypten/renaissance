#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair <int, int> pii;

vector <pair <int, pii > > seg;
multiset <int> status;
multiset <int> :: iterator iter, prev, tmp;

int ans;

void handle(int y2, int y1, int x) {

}

int main()
{
	int siz;
	int t, n;
	int i, j;
	int y1, y2, x;
	int flag, ctr;

	scanf("%d", &t);
	
	while (t--) {
		seg.clear();
		ctr  = 0;

		scanf("%d", &n);
		seg.resize(n);
		ans = 0;

		for( i = 0; i < n; i++) {
			scanf("%d %d %d", &y1, &y2, &x); 
			seg[i] = pair <int, pii > (y1, pii (y2, x));
		}

		sort(seg.begin(), seg.end());

/*
		for( i = 0; i < n; i++) printf("%d %d\n", seg[i].first, seg[i].second.first);
*/
		status.insert(seg[0].second.first);
		for( i = 1; i < n; i++) {
			y1 = seg[i].first; y2 = seg[i].second.first;

			if (ctr <= i) {
				flag = 1;
				ctr = i; 
				while ( seg[ctr+1].first  == y1) ctr++;
				if (ctr-i > 1) flag = 3;
				if (ctr-i > 0) flag = 2;  
			} 

			iter = status.lower_bound(y1);
			if (flag == 1 && iter != status.end() && ++iter == status.end()) ans++;
			else if (flag == 2 && iter == status.end()) ans++;
			
//			printf ("%d size left\n", siz);

			status.insert(y2);

//			printf("Inserted\n");

			iter = status.upper_bound(y1);

//			printf("Searched %d results %d\n", y1, *iter);
			//if(iter != status.begin()) --iter;

			for (tmp = status.begin(); tmp != iter;) {
				prev = tmp;
				if (iter == ++tmp) break;
// repetitive delete
				if (*prev != *(tmp)) {
					status.erase(prev);	
					status.begin() = tmp;
				} else if(*prev == *tmp && (++tmp) == iter) {
					status.erase(prev);
					status.begin() = (--tmp);
		
		//			printf("%d %d\n", *tmp, *iter);
		
					ans++;
				} else { 
					while(*prev == *tmp && *prev == *(++tmp)) {
						prev = tmp;
						status.erase(--tmp);
						tmp = prev;
					}
				}
			}

			iter = status.begin();
			if (*iter < y1) {
				prev == ++iter; 
				status.erase(--iter);
				iter == prev;
			}
			//status.begin() == iter;
		}

		// exit condition repairing the ones left;
		iter = status.begin();
		while (iter != status.end() && status.size() > 1) {
			prev = iter;
			if (*prev != *(++iter)) {
				status.erase(prev);	
				status.begin() = iter;
			} else if(*prev == *iter && status.size() == 2) {
				status.erase(iter);
				ans++;
			} else { 
				while(*prev == *iter) {
					tmp = ++iter;
					status.erase(--iter);
					iter = tmp;
				}
			}		
		}
		
		//for (iter = status.begin(); iter != status.end(); ++iter) printf("%d ", *iter); 

		printf("%d\n", ans);
	}
	return 0;
}
