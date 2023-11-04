#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N);
  vector<int> A(M), B(M);
  for (int n = 0; n < M; n++) {
    cin >> A.at(n);
    A.at(n)--;
  }
  for (int n = 0; n < M; n++) {
    cin >> B.at(n);
    B.at(n)--;
  }
  for (int m = 0; m < M; m++) {
    graph[A[m]].push_back(B[m]);
    graph[B[m]].push_back(A[m]);
  }


  vector<bool> seen(N, false);  // 探索完了フラグ
  vector<int> color(N, -1);
  auto dfs = [&](auto dfs, int u) -> void {
    seen.at(u) = true;  // 訪問済(訪問完了)
    // if () {
    //   return;
    // }
    int ncolor = 1 - color[u];
    for (int v : graph.at(u)) {
      if (seen.at(v)) {
        if (color[v] != ncolor){
          cout << "No" << endl;
          exit(0);
        }
        continue;
      }
      color[v] = ncolor;
      dfs(dfs, v);
    }
  };
  for (int u = 0; u < N; u++) {
    if (!seen[u]) {
      color[u] = 0;  // 最初の色は0に固定する
      dfs(dfs, u);
    }
  }
  cout << "Yes" << endl;
  return 0;
}
