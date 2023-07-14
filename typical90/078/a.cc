#include <algorithm>
#include <cassert>
#include <iostream>
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
    graph[U].push_back(V);
    graph[V].push_back(U);
  }
  int ans = 0;
  for (int u = 0; u < N; u++) {
    int now = 0;
    for (int v : graph[u]) {
      if (v < u) {
        now++;
      }
    }
    if (now == 1) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
