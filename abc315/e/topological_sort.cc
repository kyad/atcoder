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
  vector<vector<int> > graph2(N);
  vector<int> indeg(N, 0);
  for (int u = 0; u < N; u++) {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
      int P;
      cin >> P;
      P--;
      indeg.at(u)++;
      graph[P].push_back(u);
      graph2[u].push_back(P);
    }
  }
  // Topological sort
  //priority_queue<int, vector<int>, greater<int> > todo;  // Lexical order
  priority_queue<int> todo;
  for (int n = 0; n < N; n++) {
    if (indeg.at(n) == 0) {
      todo.push(n);
    }
  }
  vector<int> ans;
  while (!todo.empty()) {
    int u = todo.top();
    todo.pop();
    ans.push_back(u);
    for (size_t i = 0; i < graph.at(u).size(); i++) {
      int v = graph.at(u).at(i);
      indeg.at(v)--;
      if (indeg.at(v) == 0) {
        todo.push(v);
      }
    }
  }
  // Check if graph have loop
  if (ans.size() != (size_t)N) {
    assert(false);
    cout << -1 << endl;
    return 0;
  }
  // dfs
  vector<bool> seen(N, false);  // 探索完了フラグ
  auto dfs = [&](auto dfs, int u) -> void {
    seen.at(u) = true;  // 訪問済(訪問完了)
    for (int v : graph2.at(u)) {
      if (seen.at(v)) {
        continue;
      }
      dfs(dfs, v);
    }
  };
  dfs(dfs, 0);
  vector<int> ans2;
  for (size_t i = 0; i < ans.size(); i++) {
    if (seen[ans[i]] == false) {
      continue;
    }
    if (ans[i] == 0) {
      continue;
    }
    ans2.push_back(ans[i] + 1);
  }
  dumpvec(ans2);
  return 0;
}
