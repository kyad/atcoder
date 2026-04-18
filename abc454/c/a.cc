#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N);
  for (int j = 0; j < M; j++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    graph.at(A).push_back(B);
  }
  // BFS
  int s = 0;  // 探索開始ノード
  queue<int> todo;
  vector<int> dist(N, -1);
  dist.at(s) = 0;
  todo.push(s);
  while (!todo.empty()) {
    int u = todo.front();
    todo.pop();
    for (int v : graph.at(u)) {
      if (dist.at(v) < 0) {
        dist.at(v) = dist.at(u) + 1;
        todo.push(v);
      }
      // if (dist.at(v) == dist.at(u) + 1) {  // 前に、uと同じ距離のノードからvに訪れていた場合の処理
      // }
    }
  }
  int ans = 0;
  for (int u = 0; u < N; u++) {
    if (dist.at(u) >= 0) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
