#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, const T b) { a = max(a, b); }

int main() {
  int N;
  cin >> N;
  vector<int> X(N + 1, -1);
  vector<long long> Y(N + 1, -1);
  for (int n = 1; n <= N; n++) {
    cin >> X.at(n) >> Y.at(n);
  }
  const long long INF = 4e18;
  vector<vector<long long> > dp(N + 1, vector<long long>(2, -INF));
  dp[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    // 食べない
    for (int j = 0; j < 2; j++) {
      chmax(dp[i][j], dp[i - 1][j]);
    }
    // 食べる
    if (X[i] == 0) {
      chmax(dp[i][0], dp[i - 1][0] + Y[i]);
      chmax(dp[i][0], dp[i - 1][1] + Y[i]);
    } else {
      chmax(dp[i][1], dp[i - 1][0] + Y[i]);
    }
  }
  long long ans = max(dp[N][0], dp[N][1]);
  cout << ans << endl;
  return 0;
}
