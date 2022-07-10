// https://atcoder.jp/contests/abc259/tasks/abc259_f
// WA

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
    vector<tuple<long long, int, bool> > cand;  // 取り方の候補
    for (size_t i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i].first;
      long long w = graph[u][i].second;
      if (v == parent) {
        continue;
      }
      dfs(dfs, v, u);
      cand.push_back(make_tuple(dp[v][0], v, false));  // u-vの枝を取らない時
      cand.push_back(make_tuple(dp[v][1] + w, v, true));  // u-vの枝を取る時
    }
    sort(cand.begin(), cand.end(), greater<tuple<long long, int, bool> >());
    for (int j = 0; j < 2; j++) {
      if (j == 1 && D[u] == 0) {
        dp[u][1] = -INF;
        break;
      }
      set<int> st; // 使った子
      int edges = 0; // uと接続する子の数
      for (size_t i = 0; i < cand.size(); i++) {
        long long score = get<0>(cand[i]);
        int v = get<1>(cand[i]);
        bool use = get<2>(cand[i]);
        if (st.count(v) >= 1) {
          continue;
        }
        if (use && edges >= D[u] - j) {
          continue;
        }
        st.insert(v);
        dp[u][j] += score;
        if (use) {
          edges++;
        }
      }
    }
  };
  long long ans = 0;
  for (int u = 0; u < N; u++) {
    if (dp[u][0] >= 0) {
      continue;
    }
    dfs(dfs, u, -1);
    ans += max(dp[u][0], dp[u][1]);
  }
  cout << ans << endl;
  return 0;
}
