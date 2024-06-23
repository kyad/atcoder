// https://www.youtube.com/watch?v=4-TEF7DPvEY&t=5643s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, L, R;
  cin >> N >> L >> R;
  int N2 = 1<<N;

  // BFS
  int s = L;  // 探索開始ノード
  queue<int> todo;
  vector<int> dist(N2 + 1, -1);
  vector<int> prev(N2 + 1, -1);
  dist.at(s) = 0;
  todo.push(s);
  while (!todo.empty()) {
    int u = todo.front();
    todo.pop();

    auto push = [&](int v) {
      if (v < 0 || v > N2) {
        return;
      }
      if (dist[v] >= 0) {
        return;
      }
      dist[v] = dist[u] + 1;
      todo.push(v);
      prev[v] = u;
    };

    // グラフがつながっている点を探索
    push(u + 1);
    push(u - 1);
    for (int i = 0; i < N; i++) {
      if (u>>i&1) {
        break;
      }
      int width = 1<<(i + 1);
      push(u + width);
      push(u - width);
    }
  }

  int r = R + 1;
  int ans = 0;
  while (r != L) {
    int l = prev[r];
    assert(0 <= l && l <= N2);
    int sign = 1;
    int ql = l;
    int qr = r;
    if (ql > qr) {
      swap(ql, qr);
      sign = -1;
    }
    // ql, qr --> i, j
    int i = 0;
    int width = qr - ql;
    int j = ql;
    while (width % 2 == 0) {
      width /= 2;
      i++;
      j /= 2;
    }
    cout << "? " << i << ' ' << j << endl;
    int T;
    cin >> T;
    ans = (ans + 100 + sign * T) % 100;
    r = l;
  }
  cout << "! " << ans << endl;
  return 0;
}
