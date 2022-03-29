// https://atcoder.jp/contests/dp/tasks/dp_v
// https://blog.hamayanhamayan.com/entry/2019/01/12/152428
// 全方位木DP

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N;
int MOD;
vector<vector<int> > graph;
// dp[u]: uが黒で、u以下で条件を満たす個数
vector<long long> dp;

// 頂点0を根としたDP
void dfs1(int u, int parent) {
  long long ans = 1;
  for (size_t i = 0; i < graph.at(u).size(); i++) {
    int v = graph.at(u).at(i);
    if (v == parent) {
      continue;
    }
    dfs1(v, u);
    ans *= (dp.at(v) + 1);
    ans %= MOD;
  }
  dp.at(u) = ans;
}

// 全方位木DP
vector<long long> ans;
void dfs2(int u, int parent) {
  // 正解を求める
  ans.at(u) = 1;
  for (size_t i = 0; i < graph.at(u).size(); i++) {
    int v = graph.at(u).at(i);
    ans.at(u) *= (dp.at(v) + 1);
    ans.at(u) %= MOD;
  }
  // 遷移の前処理
  int K = graph.at(u).size();
  vector<long long> left(K), right(K);
  for (int k = 0; k < K; k++) {
    left.at(k) = right.at(k) = (dp[graph[u][k]] + 1);
  }
  for (int k = 1; k < K; k++) {
    left.at(k) *= left.at(k - 1);
    left.at(k) %= MOD;
  }
  for (int k = K - 2; k >= 0; k--) {
    right.at(k) *= right.at(k + 1);
    right.at(k) %= MOD;
  }
  // 遷移
  for (int k = 0; k < K; k++) {
    int v = graph.at(u).at(k);
    if (v == parent) {
      continue;
    }
    // vを根として処理する時の状態にdp[u]を変更する
    dp.at(u) = 1;
    if (k > 0) {
      dp.at(u) *= left.at(k - 1);
      dp.at(u) %= MOD;
    }
    if (k + 1 < K) {
      dp.at(u) *= right.at(k + 1);
      dp.at(u) %= MOD;
    }
    dfs2(v, u);
  }
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
  dp.resize(N, 0);
  dfs1(0, -1);
  ans.resize(N, 0);
  dfs2(0, -1);
  for (int n = 0; n < N; n++) {
    cout << ans.at(n) <<endl;
  }
  return 0;
}
