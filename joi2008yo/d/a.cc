// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_d

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int m;
  cin >> m;
  vector<int> sx(m), sy(m);
  for (int i = 0; i < m; i++) {
    cin >> sx.at(i) >> sy.at(i);
  }
  int n;
  cin >> n;
  vector<int> px(n), py(n);
  for (int j = 0; j < n; j++) {
    cin >> px.at(j) >> py.at(j);
  }
  // dx = px - sx
  vector<int> dx, dy;
  for (int j = 0; j < n;j++) {
    dx.push_back(px.at(j) - sx.at(0));
    dy.push_back(py.at(j) - sy.at(0));
  }
  for (size_t k = 0; k < dx.size(); k++) {
    set<pair<int, int> > s;
    for (int i = 0; i < m; i++) {
      s.insert(make_pair(sx[i] + dx[k], sy[i] + dy[k]));
    }
    for (int j = 0; j < n; j++) {
      pair<int, int> p = make_pair(px[j], py[j]);
      if (s.count(p) > 0) {
        s.erase(p);
      }
    }
    if (s.empty()) {
      cout << dx[k] << ' ' << dy[k] <<endl;
      break;
    }
  }
  return 0;
}
