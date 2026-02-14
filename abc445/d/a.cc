#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  set<tuple<int, int, int> > st1, st2;
  vector<int> h(N), w(N);
  for (int i = 0; i < N; i++) {
    cin >> h.at(i) >> w.at(i);
    st1.insert(make_tuple(h.at(i), w.at(i), i));
    st2.insert(make_tuple(w.at(i), h.at(i), i));
  }
  vector<int> x(N, -1), y(N, -1);
  for (int i = 0; i < N - 1; i++) {
    auto [h1, w1, i1] = *st1.rbegin();
    auto [w2, h2, i2] = *st2.rbegin();
    if (h1 == H) {
      y.at(i1) = 0;
      x.at(i1) = W - w1;
      W -= w1;
      st1.erase(*st1.rbegin());
      st2.erase(make_tuple(w1, h1, i1));
    } else if (w2 == W) {
      y.at(i2) = H - h2;
      x.at(i2) = 0;
      H -= h2;
      st1.erase(make_tuple(h2, w2, i2));
      st2.erase(*st2.rbegin());
    }
  }
  for (int i = 0; i < N; i++) {
    if (x.at(i) < 0) {
      cout << 1 << ' ' << 1 << '\n';
    } else {
      cout << (y.at(i) + 1) << ' ' << (x.at(i) + 1) << '\n';
    }
  }
  return 0;
}

