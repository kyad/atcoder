#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int> >graph(N + 1);
  for (int q = 0; q < Q; q++) {
    int l, r;
    cin >> l >> r;
    l--;
    graph[l].push_back(r);
    graph[r].push_back(l);
  }
  // DFS
  vector<bool> seen(N + 1, false);
  stack<int> todo;
  todo.push(0);
  while (!todo.empty()) {
    int u = todo.top();
    seen[u] = true;
    todo.pop();
    for (size_t i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      if (seen[v]) {
        continue;
      }
      todo.push(v);
    }
  }
  if (seen[N]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
