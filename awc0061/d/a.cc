#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M, S, T;
  cin >> N >> M >> S >> T;
  S--;
  T--;
  vector<vector<int>> A(M);
  for (int j = 0; j < M; j++) {
    int K;
    cin >> K;
    for (int k = 0; k < K; k++) {
      int a;
      cin >> a;
      a--;
      A.at(j).push_back(a);
    }
  }
  vector<vector<int>> js(N); // js[u]: uを通るバス路線の集合
  for (int j = 0; j < M; j++) {
    for (int a : A.at(j)) {
      js.at(a).push_back(j);
    }
  }
  // BFS
  int s = S;  // 探索開始ノード
  queue<int> todo;
  vector<int> dist(N, -1);
  dist.at(s) = 0;
  todo.push(s);
  vector<bool> used(M, false);
  while (!todo.empty()) {
    int u = todo.front();
    todo.pop();
    for (int j : js.at(u)) { // j: uを通るバス路線
      if (used.at(j)) {
        continue;
      }
      for (int v : A.at(j)) {
        if (dist.at(v) < 0) {
          dist.at(v) = dist.at(u) + 1;
          todo.push(v);
        }
      }
      used.at(j) = true;
    }
  }
  int ans = dist.at(T);
  cout << ans << '\n';
  return 0;
}
