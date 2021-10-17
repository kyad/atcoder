#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N);
  vector<unordered_set<int> > in_set(N);
  for (int m = 0; m < M; m++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    if (in_set[B].count(A) == 0) {
      graph[A].push_back(B);
      in_set[B].insert(A);
    }
  }
  priority_queue<int, vector<int>, greater<int> > pq;
  for (int n = 0; n < N; n++) {
    if (in_set[n].size() == 0) {
      pq.push(n);
    }
  }
  vector<bool> visited(N, false);
  vector<int> ans;
  while (!pq.empty()) {
    int v = pq.top();
    pq.pop();
    visited[v] = true;
    ans.push_back(v);
    for (size_t i = 0; i < graph[v].size(); i++) {
      int w = graph[v][i];
      if (visited[w]) {
        cout << -1 << endl;
        return 0;
      }
      if (in_set[w].count(v)) {
        in_set[w].erase(v);
        if (in_set[w].size() == 0) {
          pq.push(w);
        }
      }
    }
  }
  if ((int)ans.size() != N) {
    cout << -1 << endl;
    return 0;
  }
  for (size_t i = 0; i < ans.size(); i++) {
    cout << (ans[i] + 1) << (i == (ans.size() - 1) ? '\n' : ' ');
  }
  return 0;
}
