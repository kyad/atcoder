#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
  }

  int N2 = 1<<N;

  vector<bool> seen(N2, false);  // 探索完了フラグ
  vector<int> dp(N2, -1);  // -1: 未確定 1:そこに行った人が勝ち 0:そこに行った人が負け
  auto dfs = [&](auto dfs, int u) -> void {
    seen.at(u) = true;  // 訪問済(訪問完了)
    // uから行く可能性のある先の全てのvを求め、dfsしておく
    vector<int> vs;
    for (int i = 0; i < N; i++) {
      if (!((u>>i)&1)) {
        continue;
      }
      for (int j = i + 1; j < N; j++) {
        if (!((u>>j)&1)) {
          continue;
        }
        if (A.at(i) != A.at(j) && B.at(i) != B.at(j)) {
          continue;
        }
        int v = u ^ (1<<i) ^ (1<<j);
        assert(v < u);
        vs.push_back(v);
        // v: 次の状態
        if (seen.at(v)) {
          assert(dp[v] >= 0);
          continue;
        }
        dfs(dfs, v);
      }
    }
    // dp[u]を計算する
    dp[u] = 0; // 基本負け
    for (int v: vs) {
      assert(dp[v] >= 0);
      if (dp.at(v) == 0) {  // 1個でも遷移先に負けがあれば勝ち
        dp.at(u) = 1;
      }
    }
  };

  int root = N2 - 1;
  dfs(dfs, root);
  string ans;
  if (dp[root] == 1) {
    ans = "Takahashi";
  } else {
    ans = "Aoki";
  }

  cout << ans << endl;
  return 0;
}
