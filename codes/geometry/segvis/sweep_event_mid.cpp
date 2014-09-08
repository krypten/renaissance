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
	int t, n;
	int i, j;
	int y1, y2, x;

	scanf("%d", &t);
	
	while (t--) {
		seg.clear();

		scanf("%d", &n);
		seg.resize(n);
		ans = 0;

		for( i = 0; i < n; i++) {
			scanf("%d %d %d", &y1, &y2, &x); 
			seg[i] = pair <int, pii > (y1, pii (y2, x));
		}

		sort(seg.begin(), seg.end());

		for( i = 0; i < n; i++) printf("%d %d\n", seg[i].first, seg[i].second.first);

		status.insert(seg[0].second.first);
		for( i = 1; i < n; i++) {
			y1 = seg[i].first; y2 = seg[i].second.first;
			status.insert(y2);
			printf("Inserted\n");
			iter = status.lower_bound(y1);
			printf("Searched %d\n", *iter);
			//if(iter != status.begin()) --iter;
			for (tmp = status.begin(); tmp != iter) {
				/*prev = --iter;
				printf("Erased %d \n", *(++iter));
				status.erase(iter);
				iter = prev;*/
			}/*
			if (*iter < y1) {
				prev == ++iter; 
				status.erase(--iter);
				iter == prev;
			}*/
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
		
		for (iter = status.begin(); iter != status.end(); ++iter) printf("%d ", *iter); 

		printf("\n%d\n", ans);
	}
	return 0;
}
