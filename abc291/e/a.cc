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
  vector<int> indeg(N, 0);
  vector<int> out_deg(N, 0);
  for (int m = 0; m < M; m++) {
    int X, Y;
    cin >> X >> Y;
    X--; Y--;
    graph[X].push_back(Y);
    out_deg[X]++;
    indeg[Y]++;
  }

  int n_leaf = 0;
  int n_top = 0;
  for (int n = 0; n < N; n++) {
    if (out_deg[n] == 0) {
      n_leaf++;
    }
    if (indeg[n] == 0) {
      n_top++;
    }
  }
  if (n_leaf != 1 || n_top != 1) {
    cout << "No" << endl;
    return 0;
  }

  // Topological sort
  priority_queue<int> todo;
  for (int n = 0; n < N; n++) {
    if (indeg.at(n) == 0) {
      todo.push(n);
    }
  }
  vector<int> order;
  while (!todo.empty()) {
    int u = todo.top();
    todo.pop();
    order.push_back(u);
    for (size_t i = 0; i < graph.at(u).size(); i++) {
      int v = graph.at(u).at(i);
      indeg.at(v)--;
      if (indeg.at(v) == 0) {
        todo.push(v);
      }
    }
  }

  cout << "Yes" << endl;

  vector<int> ans(N);
  for (int i = 0; i < N; i++) {
    ans[order[i]] = i + 1;
  }
  
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " \n"[i == N - 1];
  }
  return 0;
}
