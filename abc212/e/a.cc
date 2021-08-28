// https://atcoder.jp/contests/abc212/tasks/abc212_e

#include <bits/stdc++.h>
using namespace std;

int main() {
  const int MOD = 998244353;
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<long long> > graph(N);
  for (int m = 0; m < M; m++) {
    int U, V;
    cin >> U >> V;
    graph.at(U - 1).push_back(V - 1);
    graph.at(V - 1).push_back(U - 1);
  }
  vector<vector<long long> > dp(K + 1, vector<long long>(N));
  dp[0][0] = 1;
  for (int k = 1; k <= K; k++) {
    long long total = 0;
    for (int n = 0; n < N; n++) {
      total += dp[k - 1][n];
    }
    for (int n = 0; n < N; n++) {
      dp[k][n] = total - dp[k - 1][n];
      for (size_t i = 0; i < graph.at(n).size(); i++) {
	dp[k][n] -= dp[k - 1][graph.at(n).at(i)];
      }
      dp[k][n] %= MOD;
    }
  }
  cout << dp[K][0] << endl;
  return 0;
}
