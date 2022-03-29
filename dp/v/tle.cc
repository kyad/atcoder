// https://atcoder.jp/contests/dp/tasks/dp_v

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N;
int MOD;
vector<vector<int> > graph;
// dp[(u, v)]: uを根で、uが黒の時、uからvに向かう方向で、条件を満たす個数
map<pair<int, int>, long long> dp;

// uni.pyの入力に対して、頂点2で計算する時(mainでs==1)、
// dfs(1, -1) --> dfs(0, 1)となって、dfs(0, 1)のforループがO(N)回になる。
// 頂点sが3以降でも、
// dfs(s, -1) --> dfs(0, s)となって、dfs(0, s)のforループがO(N)回になる。
// よって、全体の計算量はO(N^2)になって、TLEになる。
long long dfs(int u, int parent) {
  long long ans = 1;
  for (size_t i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (v == parent) {
      continue;
    }
    long long now;
    if (dp.count(make_pair(u, v)) == 0) {
      dfs(v, u);
    }
    now = dp[make_pair(u, v)];
    ans *= now;
    ans %= MOD;
  }
  ans++;
  ans %= MOD;
  if (parent != -1) {
    dp[make_pair(parent, u)] = ans;
  }
  return ans;
}

int main() {
  cin >> N >> MOD;
  graph.resize(N);
  for (int n = 0; n < N - 1; n++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  // 全枝について、dpを求める
  for (int s = 0; s < N; s++) {
    long long ans = dfs(s, -1);
    ans = (ans + MOD - 1) % MOD;
    cout << ans << endl;
  }
  return 0;
}
