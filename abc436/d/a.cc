#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  // ワープ
  const int C = 26;
  // (wy[c], wx[c]): cの文字のワープの場所
  vector<set<pair<int, int> > > w(C);
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if ('a' <= S.at(y).at(x) && S.at(y).at(x) <= 'z') {
        int ci = S.at(y).at(x) - 'a';
        w.at(ci).insert(make_pair(y, x));
      }
    }
  }
  int sy = 0;
  int sx = 0;
  // BFS
  const int dy[4] = { 0, -1,  0, +1};
  const int dx[4] = {+1,  0, -1,  0};
  queue<pair<int, int> > todo;
  vector<vector<int> > dist(H, vector<int>(W, -1));
  dist.at(sy).at(sx) = 0;
  todo.push(make_pair(sy, sx));
  while (!todo.empty()) {
    auto [y, x] = todo.front();
    todo.pop();
    for (int k = 0; k < 4; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
        continue;
      }
      // 壁の条件
      if (S[ny][nx] == '#') {
        continue;
      }
      if (dist.at(ny).at(nx) < 0) {
        dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
        todo.push(make_pair(ny, nx));
        if ('a' <= S.at(ny).at(nx) && S.at(ny).at(nx) <= 'z') {
          int ci = S.at(ny).at(nx) - 'a';
          pair<int, int> p = make_pair(ny, nx);
          assert(w.at(ci).contains(p));
          w.at(ci).erase(p);
        }
      }
    }
    // ワープ
    if ('a' <= S.at(y).at(x) && S.at(y).at(x) <= 'z') {
      int ci = S.at(y).at(x) - 'a';
      vector<pair<int, int> > removes;
      for (auto [ny, nx] : w.at(ci)) {
        if (ny == y && nx == x) {
          continue;
        }
        if (dist.at(ny).at(nx) < 0) {
          dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
          todo.push(make_pair(ny, nx));
          removes.push_back(make_pair(ny, nx));
        }
      }
      for (auto [y, x]: removes) {
        w.at(ci).erase(make_pair(y, x));
      }
    }
  }
  int ans = dist.at(H - 1).at(W - 1);
  cout << ans << '\n';
  return 0;
}
