// https://atcoder.jp/contests/abc091/tasks/arc092_a

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int INF = 201;
  int N;
  cin >> N;
  vector<pair<int, int> > AB(N);
  for (int n = 0; n < N; n++) {
    cin >> AB.at(n).first >> AB.at(n).second;
  }
  vector<pair<int, int> > CD(N);
  for (int n = 0; n < N; n++) {
    cin >> CD.at(n).first >> CD.at(n).second;
  }
  sort(AB.begin(), AB.end());
  sort(CD.begin(), CD.end());
  vector<bool> selected(N, false);
  for (int n = N - 1; n >= 0; n--) {
    int a = AB.at(n).first;
    int b = AB.at(n).second;
    int d_min = INF;
    int d_min_idx = -1;
    for (int m = 0; m < N; m++) {
      if (selected.at(m)) {
        continue;
      }
      int c = CD.at(m).first;
      int d = CD.at(m).second;
      if (a < c && b < d && d < d_min) {
        d_min = d;
        d_min_idx = m;
      }
    }
    if (d_min_idx >= 0) {
      selected.at(d_min_idx) = true;
    }
  }
  int ans = 0;
  for (int n = 0; n < N; n++) {
    if (selected.at(n)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
