#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

int main() {
  int N;
  cin >> N;
  vector<vector<int> > graph(N);
  vector<int> deg(N, 0);
  for (int m = 0; m < N - 1; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
    deg[U]++;
    deg[V]++;
  }

  int s = find(deg.begin(), deg.end(), 1) - deg.begin();
  vector<int> color(N, -1);
  color[s] = 0;

  // BFS
  queue<int> todo;
  vector<int> dist(N, -1);
  dist.at(s) = 0;
  todo.push(s);
  while (!todo.empty()) {
    int u = todo.front();
    todo.pop();
    for (int v : graph.at(u)) {
      if (dist.at(v) < 0) {
        dist.at(v) = dist.at(v) + 1;
        todo.push(v);
      }
      if (color[v] < 0) {
        color[v] = (color[u] + 1) % 3;
      }
    }
  }

  vector<int> ans;
  for (int n = 0; n < N; n++) {
    if (color[n] == 1) {
      ans.push_back(deg[n]);
    }
  }
  sort(ans.begin(), ans.end());
  dumpvec(ans);
  return 0;
}
