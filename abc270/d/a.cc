#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(K);
  for (int k = 0; k < K; k++) {
    cin >> A.at(k);
  }
  // dp[i]: i個から初めた時の最大値
  vector<int> dp(N + 1, -1);
  dp.at(0) = 0;
  for (int i = 0; i <= N; i++) {
    for (int a : A) {
      int ni = i - a;
      if (ni < 0) {
        continue;
      }
      if (dp[ni] < 0) {
        continue;
      }
      dp[i] = max(dp[i], ni - dp[ni] + a);
    };
  }
  cout << dp[N] << endl;
  return 0;
}
