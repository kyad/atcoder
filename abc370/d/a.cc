#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int H, W, Q;
  cin >> H >> W >> Q;
  auto f = [&](set<int> &row, int x, vector<set<int> > &cols, int y) {  // (y, x)に爆弾を置いた時の処理
    if (row.contains(x)) {
      row.erase(x);
      return;
    }
    {
      // xの次の壁を探す
      set<int>::iterator it = row.lower_bound(x);
      if (it != row.end()) {
        int nx = *it;
        row.erase(nx);
        assert(cols[nx].contains(y));
        cols[nx].erase(y);
      }
    }
    {
      // xの前の壁を探す
      set<int>::iterator it = row.lower_bound(x);
      if (it != row.begin()) {
        int nx = *prev(it);
        row.erase(nx);
        assert(cols[nx].contains(y));
        cols[nx].erase(y);
      }
    }
  };
  vector<set<int> > rows(H);
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      rows[y].insert(x);
    }
  }
  vector<set<int> > cols(W);
  for (int x = 0; x < W; x++) {
    for (int y = 0; y < H; y++) {
      cols[x].insert(y);
    }
  }
  for (int q = 0; q < Q; q++) {
    int y, x;  // R, C
    cin >> y >> x;
    y--; x--;
    f(rows[y], x, cols, y);
    f(cols[x], y, rows, x);
  }
  int ans1 = 0;
  int ans2 = 0;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (rows[y].contains(x)) {
        ans1++;
      }
      if (cols[x].contains(y)) {
        ans2++;
      }
    }
  }
  assert(ans1 == ans2);
  cout << ans1 << endl;
  return 0;
}
