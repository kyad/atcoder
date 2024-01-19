// https://www.youtube.com/watch?v=e3zfWo1fOiY&t=4403s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long digit_sum(long long x, int base = 10) {
  int ans = 0;
  while (x > 0) {
    long long now = x % base;
    ans += now;
    x /= base;
  }
  return ans;
}

long long naive(long long N) {
  long long ans = 0;
  for (long long n = 1; n <= N; n++) {
    long long dsum = digit_sum(n);
    if (n % dsum == 0) {
      //long long q = n / dsum;
      ans++;
    } else {
    }
  }
  return ans;
}

long long solve(long long N) {
  vector<int> digits;
  while (N > 0) {
    digits.push_back(N % 10);
    N /= 10;
  }
  reverse(digits.begin(), digits.end());
  int M = digits.size();
  int Kmax = 126;  // 桁和の最大値
  long long ans = 0;
  for (int K = 1; K <= 126; K++) {
    // dp[i][j][s][r]: 上からi桁目まで見た時の総数。j=1はN未満が確定。sは桁和、rはKで割った時の余り
    vector<vector<vector<vector<long long> > > > dp(M + 1, vector<vector<vector<long long> > >(2, vector<vector<long long> >(Kmax + 1, vector<long long>(K, 0))));
    dp[0][0][0][0] = 1;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < 2; j++) {
        for (int s = 0; s <= Kmax; s++) {
          for (int r = 0; r < K; r++) {
            for (int d = 0; d < 10; d++) {
              int ni = i + 1;
              int nj = j;
              int ns = s + d;
              int nr = (10 * r + d) % K;
              if (j == 0) {
                if (d < digits[i]) {
                  nj = 1;
                } else if (d > digits[i]) {
                  continue;
                }
              }
              if (ns > K) {
                continue;
              }
              dp[ni][nj][ns][nr] += dp[i][j][s][r];
            }
          }
        }
      }
    }
    long long now = dp[M][0][K][0] + dp[M][1][K][0];
    ans += now;
  }
  return ans;
}

int main() {
  long long N;
  cin >> N;
  long long ans = solve(N);
  cout << ans << endl;
  return 0;
}
