#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<tuple<int, long long, long long > > > graph(N);
  for (int m = 0; m < M; m++) {
    int A, B;
    long long X, Y;
    cin >> A >> B >> X >> Y;
    A--; B--;
    graph[A].push_back(make_tuple(B, X, Y));
    graph[B].push_back(make_tuple(A, -X, -Y));
  }

  vector<bool> seen(N, false);  // 探索完了フラグ
  vector<long long> X(N, 0), Y(N, 0);
  auto dfs = [&](auto dfs, int u) -> void {
    seen.at(u) = true;  // 訪問済(訪問完了)
    // if () {
    //   return;
    // }
    for (auto [v, dx, dy] : graph.at(u)) {
      if (seen.at(v)) {
        continue;
      }
      X[v] = X[u] + dx;
      Y[v] = Y[u] + dy;
      dfs(dfs, v);
    }
  };
  dfs(dfs, 0);
  for (int n = 0; n < N; n++) {
    if (seen[n]) {
      cout << X[n] << ' ' << Y[n] << '\n';
    } else {
      cout << "undecidable\n";
    }
  }
  return 0;
}
