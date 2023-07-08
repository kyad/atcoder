#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N1, N2, M;
  cin >> N1 >> N2 >> M;
  int N = N1 + N2;
  vector<vector<int> > graph(N);
  for (int m = 0; m < M; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
  }

  // BFS
  auto bfs = [&](int s) -> int {
    //int s = 0;  // 探索開始ノード
    queue<int> todo;
    vector<int> dist(N, -1);
    int mx = 0;
    dist.at(s) = 0;
    todo.push(s);
    while (!todo.empty()) {
      int u = todo.front();
      todo.pop();
      for (int v : graph.at(u)) {
        if (dist.at(v) < 0) {
          dist.at(v) = dist.at(u) + 1;
          mx = max(mx, dist.at(v));
          todo.push(v);
        }
        // if (dist.at(v) == dist.at(u) + 1) {  // 前に、uと同じ距離のノードからvに訪れていた場合の処理
        // }
      }
    }
    return mx;
  };

  int mx1 = bfs(0);
  int mx2 = bfs(N - 1);
  int ans = mx1 + mx2 + 1;
  cout << ans << endl;
  return 0;
}
