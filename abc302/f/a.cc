#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > S(N + 1); // 1-indexed, 0=super s
  vector<vector<int> > ns(M + 1);  // 整数s(1-indexed, 1<=s<=M) --> ノード番号n(1-indexed, 1<=n<=N)
  S[0].push_back(1);
  //ns[1].push_back(0);
  for (int n = 1; n <= N; n++) {  // 1-indexed
    int A;
    cin >> A;
    for (int i = 0; i < A; i++) {
      int s;
      cin >> s;  // 1<=s<=M
      S[n].push_back(s);  // 1<=n<=N
      ns[s].push_back(n);  // 1<=s<=M
    }
  }
  // bfs
  auto bfs = [&]() -> int {
    vector<bool> s_used(M + 1, false);  // 1<=s<=M
    queue<int> todo;
    vector<int> dist(N + 1, -1);  //1<=n<=N
    dist[0] = 0;
    todo.push(0);
    while (!todo.empty()) {
      int v = todo.front();
      todo.pop();
      for (int s : S[v]) {
        if (s_used[s]) {
          continue;
        }
        s_used[s] = true;
        if (s == M) {
          return dist[v];
        }
        for (int x : ns[s]) {
          if (dist[x] < 0) {
            dist[x] = dist[v] + 1;
            todo.push(x);
          }
        }
      }
    }
    return -1;
  };
  int ans = bfs();
  if (ans > 0) {
    ans--;
  }
  cout << ans << endl;
  return 0;
}
