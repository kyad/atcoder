#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> U(M);
  vector<int> V(M);
  for (int m = 0; m < M; m++) {
    cin >> U[m] >> V[m];
    U[m]--; V[m]--;
  }
  vector<int> W(N);
  for (int i = 0; i < N; i++) {
    cin >> W.at(i);
  }
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<vector<int> > graph(N);
  for (int m = 0; m < M; m++) {
    int u = U[m];
    int v = V[m];
    if (W[u] > W[v]) {  // 大→小
      graph[u].push_back(v);
    } else if (W[u] < W[v]) {
      graph[v].push_back(u);
    }
  }

  // f(u): uからスタートした時の最大値
  vector<long long> memo(N, -1);
  // 初期値
  for (int u = 0; u < N; u++) {
    if (graph[u].size() == 0) {
      memo[u] = 1;
    }
  }
  auto f = [&](auto f, int u) -> long long {
    if (memo.at(u) >= 0) {
      return memo.at(u);
    }
    int M = graph[u].size();

    // 全部の隣接でfを計算しておく
    for (int v: graph[u]) {
      f(f, v);
    }

    // dp[i][j]: uからスタートしてi番目(1-indexed)まで見て重さの合計jの最大値
    // 0<=i<=M, 0<=j<=W[u]-1
    vector<vector<long long> > dp(M + 1, vector<long long>(W[u], 0));
    dp[0][0] = 1;
    for (int i = 1; i <= M; i++) {
      int v = graph.at(u).at(i - 1);
      for (int j = 0; j <= W[u] - 1; j++) {
        if (dp[i - 1][j] > 0) {
          chmax(dp[i][j], dp[i - 1][j]);  // i(v)を取らない
        }
        if (j - W[v] >= 0) {
          if (dp[i - 1][j - W[v]] > 0) {
            chmax(dp[i][j], dp[i - 1][j - W[v]] + f(f, v));  // i(v)を取る
          }
        }
      }
    }
    long long ans = *max_element(dp[M].begin(), dp[M].end());
    return memo.at(u) = ans;
  };

  // 全部のfを計算しておく
  for (int u = 0; u < N; u++) {
    f(f, u);
  }

  long long ans = 0;
  for (int u = 0; u < N; u++) {
    ans += A[u] * f(f, u);
  }
  cout << ans << endl;
  return 0;
}
