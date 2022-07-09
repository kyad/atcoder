#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> D(N);
  for (int n = 0; n < N; n++) {
    cin >> D.at(n);
  }
  vector<vector<pair<int, int> > > graph(N);
  for (int n = 0; n < N - 1; n++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
  }
  // dp[u][j], 0<=u<N, j=0, 1
  // uを根と考えた時、uに接続する辺を高々D[u]-j個取る時の最大値
  vector<vector<long long> > dp(N, vector<long long>(2, -1));
  const long long INF = 4e18;
  auto dfs = [&](auto dfs, int u, int parent) -> void {
    dp[u][0] = 0;
    dp[u][1] = 0;
    vector<long long> cand;  // 取らない→取るに変更する方法の候補
    for (size_t i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i].first;
      int w = graph[u][i].second;
      if (v == parent) {
        continue;
      }
      dfs(dfs, v, u);
      dp[u][0] += dp[v][0];
      dp[u][1] += dp[v][0];
      cand.push_back(-dp[v][0] + dp[v][1] + w);  // u-vの枝を取らないから取るに変更した時のスコアの増分
    }
    sort(cand.rbegin(), cand.rend());
    for (int j = 0; j < 2; j++) {
      if (j == 1 && D[u] == 0) {
        dp[u][1] = -INF;
        break;
      }
      int edges = 0; // 取らないから取るに変更した枝の数
      for (size_t i = 0; i < cand.size(); i++) {
        if (cand[i] <= 0) {
          break;
        }
        if (edges >= D[u] - j) {
          break;
        }
        dp[u][j] += cand[i];
        edges++;
      }
    }
  };
  long long ans = 0;
  dfs(dfs, 0, -1);
  cout << dp[0][0] << endl;
  return 0;
}
