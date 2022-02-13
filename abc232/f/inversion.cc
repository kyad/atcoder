// https://atcoder.jp/contests/abc232/tasks/abc232_f

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X;
  long long Y;
  cin >> N >> X >> Y;
  vector<int> A(N), B(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  for (int n = 0; n < N; n++) {
    cin >> B.at(n);
  }
  const long long INF = 100000000LL * 100000000LL + 10000000000000000LL * 18 * 18 / 2 + 1;
  // dp[s]: sまで先に取った時点での費用の最小値
  int N2 = 1 << N;
  vector<long long> dp(N2, INF);
  dp[0] = 0;
  for (int s = 0; s < N2; s++) {
    int i = __builtin_popcount(s);
    for (int x = 0; x < N; x++) {
      if ((s >> x) & 1) {
        continue;
      }
      long long cost = Y * __builtin_popcount(s >> x) + (long long) X * abs(A[i] - B[x]);
      dp[s | (1<<x)] = min(dp[s | (1<<x)], dp[s] + cost);
    }
  }
  cout << dp[N2 - 1] << endl;
  return 0;
}
