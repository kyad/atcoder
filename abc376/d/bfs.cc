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
  for (int m = 0; m < M; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph.at(U).push_back(V);
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
      } else {
        if (v == 0) {
          cout << dist.at(u) + 1 << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
