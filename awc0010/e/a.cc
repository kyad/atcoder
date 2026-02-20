#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<vector<int> > C(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> C.at(i).at(j);
    }
  }
  int M = 1;
  for (int i = 0; i < N; i++) {
    M *= N;
  }
  auto encode = [&](vector<int> & P) -> int {
    int ans = 0;
    for (int i = 0; i < N; i++) {
      ans *= N;
      ans += P.at(i);
    }
    return ans;
  };
  auto decode = [&](int z) -> vector<int> {
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
      int j = N - 1 - i;
      P.at(j) = (z % N);
      z /= N;
    }
    return P;
  };
  // 幅優先探索のグラフで行ける所を考える
  // BFS
  vector<int> P0(N);
  for (int i = 0; i < N; i++) {
    P0.at(i) = i;
  }
  int z0 = encode(P0);  // 探索開始ノード
  queue<int> todo;
  vector<int> dist(M, -1);
  dist.at(z0) = 0;
  todo.push(z0);
  int ans = -1;
  while (!todo.empty()) {
    int z = todo.front();
    todo.pop();
    vector<int> P = decode(z);
    // 今の集客効果を求める
    int now = 0;
    for (int i = 0; i < N; i++) {
      int p = P.at(i);
      int q = P.at((i + 1) % N);
      now += C.at(p).at(q);
    }
    ans = max(ans, now);
    if (dist.at(z) >= K) {
      continue;
    }
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        // iとjを入れ替える
        swap(P.at(i), P.at(j));
        int w = encode(P);
        if (dist.at(w) < 0){
          dist.at(w) = dist.at(z) + 1;
          todo.push(w);
        }
        swap(P.at(i), P.at(j));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
