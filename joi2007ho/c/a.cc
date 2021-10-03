// https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> X(n), Y(n);
  set<pair<int, int> > s;
  for (int i = 0; i < n; i++) {
    cin >> X.at(i) >> Y.at(i);
    s.insert(make_pair(X.at(i), Y.at(i)));
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      int x0 = X.at(i);
      int y0 = Y.at(i);
      int x1 = X.at(j);
      int y1 = Y.at(j);
      int dx = x1 - x0;
      int dy = y1 - y0;
      int x2 = x0 - dy;
      int y2 = y0 + dx;
      int x3 = x0 + dx - dy;
      int y3 = y0 + dx + dy;
      if (s.count(make_pair(x2, y2)) > 0 && s.count(make_pair(x3, y3)) > 0) {
        ans = max(ans, dx * dx + dy * dy);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
