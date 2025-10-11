#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
using T = vector<string>;

int main() {
  int H, W;
  cin >> H >> W;
  T S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }

  auto move_x = [&](int dx, const T& u, T& v) {
    for (int y = 0; y < H; y++) {
      for (int x = 0; x < W; x++) {
        int px = x - dx;
        if (px < 0 || px >= W) {
          if (u.at(y).at(x) == 'T') {
            v.at(y).at(x) = 'T';
          } else {
            v.at(y).at(x) = '.';
          }
          continue;
        }
        // 汚れるか判定
        if (u.at(y).at(x) == 'T') {
          if (u.at(y).at(px) == '#') {
            return false;
          } else {
            v.at(y).at(x) = 'T';
          }
        } else {
          if (u.at(y).at(px) == 'T') {
            v.at(y).at(x) = '.';
          } else {
            v.at(y).at(x) = u.at(y).at(px);
          }
        }
      }
    }
    return true;
  };

  auto move_y = [&](int dy, const T& u, T& v) {
    for (int x = 0; x < W; x++) {
      for (int y = 0; y < H; y++) {
        int py = y - dy;
        if (py < 0 || py >= H) {
          if (u.at(y).at(x) == 'T') {
            v.at(y).at(x) = 'T';
          } else {
            v.at(y).at(x) = '.';
          }
          continue;
        }
        // 汚れるか判定
        if (u.at(y).at(x) == 'T') {
          if (u.at(py).at(x) == '#') {
            return false;
          } else {
            v.at(y).at(x) = 'T';
          }
        } else {
          if (u.at(py).at(x) == 'T') {
            v.at(y).at(x) = '.';
          } else {
            v.at(y).at(x) = u.at(py).at(x);
          }
        }
      }
    }
    return true;
  };

  auto printT = [&](const T& u) {
    for (int y = 0; y < H; y++) cerr << u.at(y) << endl;
  };

  // BFS
  T s = S;  // 探索開始ノード
  queue<T> todo;
  map<T, int> dist;
  dist[s] = 0;
  todo.push(s);
  while (!todo.empty()) {
    T u = todo.front();
    todo.pop();
    T v(u);  // uと同じサイズの領域確保
    // 右に移動
    if (move_x(1, u, v)) {
      if (!dist.contains(v)) {
        dist[v] = dist[u] + 1;
        todo.push(v);
      }
    }
    // 左に移動
    if (move_x(-1, u, v)) {
      if (!dist.contains(v)) {
        dist[v] = dist[u] + 1;
        todo.push(v);
      }
    }
    // 下に移動
    if (move_y(1, u, v)) {
      if (!dist.contains(v)) {
        dist[v] = dist[u] + 1;
        todo.push(v);
      }
    }
    // 上に移動
    if (move_y(-1, u, v)) {
      if (!dist.contains(v)) {
        dist[v] = dist[u] + 1;
        todo.push(v);
      }
    }
  }
  // 終点
  T t(S);
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (t.at(y).at(x) != 'T') {
        t.at(y).at(x) = '.';
      }
    }
  }
  int ans = -1;
  if (dist.contains(t)) {
    ans = dist[t];
  }
  cout << ans << endl;
  return 0;
}
