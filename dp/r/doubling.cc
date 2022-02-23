// https://atcoder.jp/contests/dp/tasks/dp_r

#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MOD = 1000000007;
  int N;
  long long K;
  cin >> N >> K;
  // log(10^18)/log2 = 59.79..
  // dp2[k][u][v]: uからvに2^k歩で行ける個数
  vector<vector<vector<long long> > > dp2(60, vector<vector<long long> >(N, vector<long long>(N, 0)));
  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) {
      cin >> dp2[0][u][v];
    }
  }
  for (int k = 0; k < 59; k++) {
    for (int u = 0; u < N; u++) {
      for (int v = 0; v < N; v++) {
        for (int w = 0; w < N; w++) {
          dp2[k + 1][u][v] += dp2[k][u][w] * dp2[k][w][v];
          dp2[k + 1][u][v] %= MOD;
        }
      }
    }
  }
  // dp[u][v]: uからvに行ける個数
  vector<vector<long long> > dp(N, vector<long long>(N, 0));
  bool is_first = true;
  for (int k = 0; k < 60; k++) {
    long long r = K % 2;
    K /= 2;
    if (r == 0) {
      continue;
    }
    if (is_first) {
      for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
          dp[u][v] = dp2[k][u][v];
        }
      }
      is_first = false;
      continue;
    }
    vector<vector<long long> > next(N, vector<long long>(N, 0));
    for (int u = 0; u < N; u++) {
      for (int v = 0; v < N; v++) {
        for (int w = 0; w < N; w++) {
          next[u][v] += dp[u][w] * dp2[k][w][v];
          next[u][v] %= MOD;
        }
      }
    }
    // Copy next to dp
    for (int u = 0; u < N; u++) {
      for (int v = 0; v < N; v++) {
        dp[u][v] = next[u][v];
      }
    }
  }
  long long ans = 0;
  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) {
      ans += dp[u][v];
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
