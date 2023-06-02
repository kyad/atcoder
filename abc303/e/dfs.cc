#include <algorithm>
#include <cassert>
#include <iostream>
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
  vector<int> deg(N, 0);
  for (int m = 0; m < N - 1; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
    deg[U]++;
    deg[V]++;
  }

  int s = -1;
  for (int n = 0; n < N; n++) {
    if (deg[n] == 1) {
      s = n;
      break;
    }
  }
  assert(s >= 0);
  vector<int> color(N, -1);
  color[s] = 0;

  vector<bool> seen(N, false);  // 探索完了フラグ
  auto dfs = [&](auto dfs, int u) -> void {
    seen.at(u) = true;  // 訪問済(訪問完了)
    for (auto v : graph.at(u)) {
      if (seen.at(v)) {
        continue;
      }
      color[v] = (color[u] + 1) % 3;
      dfs(dfs, v);
    }
  };

  dfs(dfs, s);

  vector<int> ans;
  for (int n = 0; n < N; n++) {
    if (color[n] == 1) {
      ans.push_back(deg[n]);
    }
  }
  sort(ans.begin(), ans.end());
  dumpvec(ans);
  return 0;
}
