// https://atcoder.jp/contests/abc265/tasks/abc265_e

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;  // p (prime, > n)

int main() {
  int N, M;
  cin >> N >> M;
  long long A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  vector<long long> X(M, 0);
  vector<long long> Y(M, 0);
  for (int m = 0; m < M; m++) {
    cin >> X.at(m) >> Y.at(m);
  }

  // p, q, rはそれぞれ(+A,+B),(+C,+D),(+E,+F)の移動回数
  // (p, q, r) (p+q+r=n) に障害物があるか
  vector<vector<vector<bool> > > obstacle(N + 1, vector<vector<bool> >(N + 1, vector<bool>(N + 1, false)));
  for (int n = 1; n <= N; n++) {
    for (int p = 0; p <= N; p++) {
      for (int q = 0; q <= N; q++) {
        int r = n - p - q;
        if (r < 0) {
          continue;
        }
        for (int m = 0; m < M; m++) {
          long long x = A * p + C * q + E * r;
          long long y = B * p + D * q + F * r;
          if (x == X.at(m) && y == Y.at(m)) {
            obstacle[n][p][q] = true;
          }
        }
      }
    }
  }

  // dp[n][p][q]: ワープをn回繰り返した時、(p, q, r)の移動回数で行ける組合せの数
  vector<vector<vector<long long> > > dp(N + 1, vector<vector<long long> > (N + 1, vector<long long>(N + 1, 0)));
  dp[0][0][0] = 1;
  for (int n = 0; n <= N; n++) {
    for (int p = 0; p <= N; p++) {
      for (int q = 0; q <= N; q++) {
        int r = n - p - q;
        if (r < 0) {
          continue;
        }
        if (obstacle[n][p][q]) {
          dp[n][p][q] = 0;
        }
        if (n < N) {
          dp[n + 1][p + 1][q] += dp[n][p][q];
          dp[n + 1][p + 1][q] %= MOD;
          dp[n + 1][p][q + 1] += dp[n][p][q];
          dp[n + 1][p][q + 1] %= MOD;
          dp[n + 1][p][q] += dp[n][p][q];
          dp[n + 1][p][q] %= MOD;
        }
      }
    }
  }

  long long ans = 0;
  for (int p = 0; p <= N; p++) {
    for (int q = 0; q <= N; q++) {
      int r = N - p - q;
      if (r < 0) {
        continue;
      }
      ans += dp[N][p][q];
      ans %= MOD;
    }
  }
  cout << ans <<endl;
  return 0;
}
