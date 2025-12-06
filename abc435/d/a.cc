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
    graph.at(V).push_back(U);
  }

  vector<bool> seen(N, false);  // 探索完了フラグ
  auto dfs = [&](auto dfs, int u) -> void {
    seen.at(u) = true;  // 訪問済(訪問完了)
    // if () {
    //   return;
    // }
    for (int v : graph.at(u)) {
      if (seen.at(v)) {
        continue;
      }
      dfs(dfs, v);
    }
  };

  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int type, v;
    cin >> type >> v;
    v--;
    if (type == 1) {
      if (!seen.at(v)) {
        dfs(dfs, v);
      }
    } else if (type == 2) {
      bool ans = seen.at(v);
      cout << (ans ? "Yes" : "No") << '\n';
    }
  }
  return 0;
}
