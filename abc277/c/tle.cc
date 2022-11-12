// https://atcoder.jp/contests/abc277/tasks/abc277_c
// TLE

#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<int, vector<int> > graph;
  for (int n = 0; n < N; n++) {
    int A, B;
    cin >> A >> B;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
  // DFS
  set<int> seen;
  stack<int> todo;
  todo.push(1);
  int ans = 1;
  while (!todo.empty()) {
    int u = todo.top();
    seen.insert(u);
    todo.pop();
    ans = max(ans, u);
    for (int v : graph[u]) {
      if (seen.count(v) > 0) {
        continue;
      }
      todo.push(v);
    }
  }
  cout << ans << endl;
  return 0;
}
