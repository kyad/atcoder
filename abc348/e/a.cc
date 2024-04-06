#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> C;

/**
 * 全方位木DP。(Rerooting)
 * uを根と思って木DPした時の根のDP値dp_top[u]を全て計算する。
 * 計算量はO(N)。
 */
using Data = pair<long long, long long>;  // DPの型●  値, C[v]
const Data IDENTITY = make_pair(0, 0); // Dataの単位元●
// Dataの二項演算。dp_u = f(dp_u, dp_v)する。結合則が成り立つこと。●
void dp_merge(Data &dp_u, const Data &dp_v) {
  dp_u.first += dp_v.first;
  dp_u.second += dp_v.second;
}
// DPの遷移式。dp_u = f(dp_u, dp_v)とする。●
void dp_apply(Data &dp_u, const Data &dp_v) {
  dp_u.first += dp_v.first + dp_v.second;
  dp_u.second += dp_v.second;
}

vector<vector<int> > graph;

// iを根と思った時、iからスタートした時の最大値
vector<Data> dp(N);
void dfs0(int u, int parent) {
  dp[u].first = 0;  // 葉の値。●
  dp[u].second = C[u];  // 葉の値。●
  for (auto v : graph[u]) {
    if (v == parent) {
      continue;
    }
    dfs0(v, u);
    dp_apply(dp[u], dp[v]);
  }
}
    
vector<Data> dp_top;  // dp_top[u]は、uを根と思って木DPした時のdp[u]の値。これを高速に計算するのが目標。
void dfs1(int u, int parent) {
  int K = graph[u].size();
  // uを根と思って木DPした時のdp[u](dp_top[u])を計算する。
  dp_top[u].first = 0;  // 葉の値。●
  dp_top[u].second = C[u];  // 葉の値。●
  for (int k = 0; k < K; k++) {
    auto v = graph[u][k];
    dp_apply(dp_top[u], dp[v]);
  }
  // Rerootingの準備として、子のDP値の累積和を左右から計算する。
  vector<Data> left(K), right(K);  // 子のDP値の累積和。
  for (int k = 0; k < K; k++) {
    auto v = graph[u][k];
    left[k] = right[k] = dp[v];  // 初期値は子の値。
  }
  for (int k = 1; k < K; k++) {  // 左からの累積和を計算する。
    dp_merge(left[k], left[k - 1]);
  }
  for (int k = K - 2; k >= 0; k--) {  // 右からの累積和を計算する。
    dp_merge(right[k], right[k + 1]);
  }
  for (int k = 0; k < K; k++) {
    auto v = graph[u][k];
    if (v == parent) {
      continue;
    }
    // Rerooting
    // Update dp[u]
    dp[u].first = 0;  // 葉の値。●
    dp[u].second = C[u];  // 葉の値。●
    if (k >= 1) {  // 左からの累積和でまとめて更新する。
      dp_apply(dp[u], left[k - 1]);
    }
    if (k <= K - 2) {  // 右からの累積和でまとめて更新する。
      dp_apply(dp[u], right[k + 1]);
    }
    // Update dp[v]
    dfs1(v, u);
  }
}

int main() {
  cin >> N;
  const long long INF = 4e18;
  dp.resize(N, make_pair(INF, 0));
  dp_top.resize(N, make_pair(INF, 0));
  graph.resize(N);
  for (int m = 0; m < N - 1; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
  }
  C.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
  }
  dfs0(0, -1);
  dfs1(0, -1);
  long long ans = INF;
  for (int i = 0; i < N; i++) {
    long long now = dp_top[i].first;
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
