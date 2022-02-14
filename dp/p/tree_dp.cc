// https://atcoder.jp/contests/dp/tasks/dp_p

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

vector<vector<int> > graph;
// dp[i][j]: iの色をjとしたときのiより葉側の組合せの総数
// j==0: 黒, j==1: 白
vector<vector<long long> > dp;

void dfs(int u, int parent) {
  dp[u][0] = 1;
  dp[u][1] = 1;
  for (size_t i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (v == parent) {
      continue;
    }
    dfs(v, u);
    dp[u][0] *= dp[v][1];
    dp[u][0] %= MOD;
    dp[u][1] *= (dp[v][0] + dp[v][1]);
    dp[u][1] %= MOD;
  }
}
    
int main() {
  int N;
  cin >> N;
  graph.resize(N);
  for (int n = 0; n < N - 1; n++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  dp.resize(N, vector<long long>(2, 0));
  dfs(0, -1);
  long long ans = 0;
  for (int j = 0; j < 2; j++) {
    ans += dp[0][j];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
