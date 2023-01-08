#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > graph;
vector<bool> seen;
int ans = 0;

void dfs(int u) {
  seen[u] = true;  // 訪問済(訪問完了)
  ans++;
  if (ans >= 1000000) {
    cout << 1000000 << endl;
    exit(0);
  }
  for (size_t i = 0; i < graph[u].size(); i++) {  // 訪問先の候補
    int v = graph[u][i];
    if (seen[v]) {
      continue;
    }
    dfs(v);
    seen[v] = false;
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  graph.resize(N);
  seen.assign(N, false);
  for (int m = 0; m < M; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
  }
  dfs(0);
  cout << ans << endl;
  return 0;
}
