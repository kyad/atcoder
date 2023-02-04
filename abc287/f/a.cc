#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > graph(N);
  for (int n = 0; n < N - 1; n++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  using vvm = vector<vector<mint> >;
  auto dfs = [&](auto dfs, int u, int parent) -> vvm {
    vvm dp(2, vector<mint>(2, 0));
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int v : graph[u]) {
      if (v == parent) {
        continue;
      }
      vvm r = dfs(dfs, v, u);
      int pn = dp.size();
      int rn = r.size();
      vvm p(pn + rn - 1, vector<mint>(2, 0));
      swap(p, dp);  // p, r -> dp
      for (int j0 = 0; j0 < pn; j0++) {
        for (int j1 = 0; j1 < rn; j1++) {
          if (j0 + j1 - 1 >= 0) {
            dp[j0 + j1 - 1][1] += p[j0][1] * r[j1][1];
          }
          dp[j0 + j1][1] += p[j0][1] * r[j1][0];
          dp[j0 + j1][0] += p[j0][0] * (r[j1][0] + r[j1][1]);
        }
      }
    }
    return dp;
  };
  vvm dp = dfs(dfs, 0, -1);
  for (int x = 1; x <= N; x++) {
    mint ans = dp[x][0] + dp[x][1];
    cout << ans.val() << '\n';
  }
  return 0;
}
