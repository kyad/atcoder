#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, const T b) { a = max(a, b); }

int main() {
  int N;
  cin >> N;
  vector<long long> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  vector<long long> S(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    S[n] = S[n - 1] + A[n];
  }
  vector<long long> value(N + 1, 0);  // value[cost]
  for (int c = 2; c <= N; c++) {
    if (c % 2 == 1) {
      value[c] = S[(c - 1) / 2] * 2;
    } else {
      value[c] = S[c / 2] * 2 - A[c / 2];
    }
  }
  vector<vector<long long> > dp(N + 1, vector<long long>(N + 1, 0));
  for (int i = 2; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      int c = i; // コスト
      // iを取らない
      chmax(dp[i][j], dp[i - 1][j]);
      // iを取る
      if (j - c >= 0) {
        chmax(dp[i][j], dp[i - 1][j - c] + value[c]);
        chmax(dp[i][j], dp[i][j - c] + value[c]);  // iを取る(重複)
      }
    }
  }
  long long ans = 0;
  for (int j = 0; j <= N; j++) {
    chmax(ans, dp[N][j]);
  }
  cout << ans << endl;
  return 0;
}
