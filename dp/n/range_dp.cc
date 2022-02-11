// https://atcoder.jp/contests/dp/tasks/dp_n

#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL<<60;

// dp[i][j]: iからjまでのスライムを合体させるまでのコストの最小値 (1-indexed)
vector<vector<long long> > dp;
// S[n] = a[1] + ... + a[n] (1-indexed)
vector<long long> S;

long long rec(int left, int right) {
  if (dp[left][right] < INF) {
    return dp[left][right];
  }
  // 合体前のコストの最小値
  long long ans = INF;
  for (int k = left; k < right; k++) {
    long long temp = rec(left, k) + rec(k + 1, right);
    ans = min(ans, temp);
  }
  // 合体する時のコストを加える
  ans += S[right] - S[left - 1];
  return dp[left][right] = ans;
}

int main() {
  int N;
  cin >> N;
  S.resize(N + 1, 0);
  vector<int> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
    S[n] = S[n - 1] + A[n];
  }
  dp.resize(N + 1, vector<long long>(N + 1, INF));
  for (int n = 1; n <= N; n++) {
    dp[n][n] = 0;
  }
  long long ans = rec(1, N);
  cout << ans << endl;
  return 0;
}
