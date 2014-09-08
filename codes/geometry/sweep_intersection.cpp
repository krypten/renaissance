#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

#define HUGE_VAL 2100
using namespace std;

struct point {
      int x,y;
};

struct cmp_x {
      bool operator() (const point &a, const point b) {
            if (a.x != b.x)
                  return (a.x < b.x);
            else
                  return (a.y < b.y);
      }
};

struct cmp_y {
      bool operator() ( const point &a, const point &b) {
            if (a.y != b.y) {
                  return (a.y < b.y);
            } else {
                  return (a.x < b.x);
            }
      }
};

int closet(const vector <point> &S) {
      int n = S.size();
      vector <point> Sx = S;
      set <point, cmp_y> Sy;
      int tail = 0;
      point tmp1, tmp2;

      sort(Sx.begin(), Sx.end(), cmp_x());
      int h = HUGE_VAL;

      for( int  i = 0; i < n; i++) {

            while (Sx[i].x - Sx[tail].x > h) {
                  Sy.erase(Sx[tail]);
                  tail++;
            }


            tmp1.x = -HUGE_VAL; tmp1.y = Sx[i].y - h;
            tmp2.x = HUGE_VAL;  tmp2.y = Sx[i].y + h;

            set <point, cmp_y> :: const_iterator y1,y2;
            y1 = lower_bound( Sy.begin(), Sy.end(), tmp1, cmp_y());
            y2 = upper_bound( Sy.begin(), Sy.end(), tmp2, cmp_y());

            for( set<point, cmp_y>::const_iterator j = y1; j != y2; ++j) {
                  h = min(h, abs(Sx[i].x - (*j).x));
            }

            Sy.insert(Sx[i]);
      }
      return h;
}

int main()
{

      return 0;
}
