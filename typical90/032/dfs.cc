#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > A(N, vector<int>(N, true));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A.at(i).at(j);
    }
  }
  int M;
  cin >> M;
  vector<vector<int> > ok(N, vector<int>(N, true));
  for (int m = 0; m < M; m++) {
    int X, Y;
    cin >> X >> Y;
    X--; Y--;
    ok.at(X).at(Y) = false;
    ok.at(Y).at(X) = false;
  }
  const int INF = 1000 * N + 1;
  int ans = INF;
  vector<bool> used(N, false);
  // prev: 前のノード
  // depth: 何人目まで走り終わったか(0 .. N)
  // value: 今までの時間の合計
  auto dfs = [&](auto dfs, int prev, int depth, int value) -> void {
    if (depth == N) {  // 探索終了
      ans = min(ans, value);
      return;
    }
    for (int v = 0; v < N; v++) {
      if (used[v]) {
        continue;
      }
      if (prev >= 0 && !ok[prev][v]) {
        continue;
      }
      used[v] = true;
      dfs(dfs, v, depth + 1, value + A[v][depth]);
      used[v] = false;
    }
  };
  dfs(dfs, -1, 0, 0);
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
