#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  long long SX, SY;
  cin >> N >> M >> SX >> SY;
  vector<long long> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
  }
  // hy[x]: X座標がxの家のy座標の集合
  // hx[y]: Y座標がyの家のx座標の集合
  map<long long, set<long long> > hy, hx;
  for (int i = 0; i < N; i++) {
    hy[X.at(i)].insert(Y.at(i));
    hx[Y.at(i)].insert(X.at(i));
  }

  // サンタクロースの位置
  long long y = SY;
  long long x = SX;
  set<pair<long long, long long> > visited;
  for (int j = 0; j < M; j++) {
    char D;
    long long C;
    cin >> D >> C;
    long long dy = 0;
    long long dx = 0;
    vector<long long> remove_ys, remove_xs;
    if (D == 'U' || D == 'D') {
      long long from, to;
      if (D == 'U') {
        from = y;
        to = y + C;
        dy = +1;
      } else {  // D
        from = y - C;
        to = y;
        dy = -1;
      }
      auto it = hy[x].lower_bound(from);
      while (it != hy[x].end() && *it <= to) {
        remove_ys.push_back(*it);
        remove_xs.push_back(x);
        it = next(it);
      }
    } else {
      long long from, to;
      if (D == 'L') {
        from = x - C;
        to = x;
        dx = -1;
      } else {  // R
        from = x;
        to = x + C;
        dx = +1;
      }
      auto it = hx[y].lower_bound(from);
      while (it != hx[y].end() && *it <= to) {
        remove_ys.push_back(y);
        remove_xs.push_back(*it);
        it = next(it);
      }
    }
    // removeの処理
    for (size_t i = 0; i < remove_ys.size(); i++) {
      long long y = remove_ys.at(i);
      long long x = remove_xs.at(i);
      visited.insert(make_pair(y, x));
      hx[y].erase(x);
      hy[x].erase(y);
    }
    // 次の処理
    y += dy * C;
    x += dx * C;
  }
  int K = visited.size();
  cout << x << ' ' << y << ' ' << K << endl;
  return 0;
}
