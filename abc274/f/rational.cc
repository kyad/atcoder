#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;
#include <boost/rational.hpp>
using namespace boost;

typedef rational<int> rat;

struct Fish {
  int w;
  int x;
  int v;
  bool operator<(const Fish& a) const {
    return x < a.x;
  } 
};

int main() {
  int N;
  int A;
  cin >> N >> A;
  vector<Fish> f(N);
  for (int n = 0; n < N; n++) {
    cin >> f[n].w >> f[n].x >> f[n].v;
  }
  sort(f.begin(), f.end());

  int ans = -1;
  vector<int> ord(N);  // i個目の魚が左から何番目か(0-indexed, i=0, ..., N-1)
  vector<int> sum(N + 1, 0);  // sum[i+1]: 左からi番目(0-indexed)まで魚の和(i=0, ..., N-1)
  for (int n = 0; n < N; n++) {
    ans = max(ans, f[n].w);
    ord[n] = n;
    sum[n + 1] = sum[n] + f[n].w;
  }

  vector<pair<rat, pair<int, int> > > events;
  for (int l = 0; l < N; l++) {
    for (int r = l + 1; r < N; r++) {
      if (f[l].v <= f[r].v) {
        if (f[l].x + A >= f[r].x) {
          events.push_back(make_pair(rat(0), make_pair(l, r)));
        }
      } else {
        // 抜かす
        rat t1(f[r].x - f[l].x, f[l].v - f[r].v);
        events.push_back(make_pair(t1, make_pair(l + N, r)));

        // 追い付く
        rat t0(f[r].x - f[l].x - A, f[l].v - f[r].v);
        events.push_back(make_pair(max(t0, rat(0)), make_pair(l, r)));
      }
    }
  }
  sort(events.begin(), events.end());
  for (size_t k = 0; k < events.size(); k++) {
    int l = events[k].second.first;
    int r = events[k].second.second;
    if (l >= N) {  // 抜かす時
      l -= N;
      sum[ord[l] + 1] = sum[ord[l] + 1] + f[r].w - f[l].w;
      swap(ord[l], ord[r]);
    } else {  // 追い付く時
      int now = sum[ord[r] + 1] - sum[ord[l]];
      ans = max(ans, now);
    }
  }
  cout << ans << endl;
  return 0;
}
