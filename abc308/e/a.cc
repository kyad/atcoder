#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int mex(int a, int b, int c) {
  vector<int> count(4, 0);
  count[a]++;
  count[b]++;
  count[c]++;
  int ans = 0;
  for (int i = 0; i <= 2; i++) {
    if (count[i] == 0) {
      break;
    }
    ans = i + 1;
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  string S;
  cin >> S;
  // sx
  vector<vector<long long> > sx(N, vector<long long>(3, 0));
  for (int n = N - 1; n >= 0; n--) {
    if (S[n] == 'X') {
      int a = A[n];
      sx[n][a]++;
    }
  }
  // 累積和
  for (int n = N - 2; n >= 0; n--) {
    for (int a = 0; a < 3; a++) {
      sx[n][a] += sx[n + 1][a];
    }
  }
  // dp[i][j][k]: i以降のEXの個数
  vector<vector<vector<long long> > > dp(N, vector<vector<long long> >(3, vector<long long>(3, 0LL)));
  for (int i = N - 2; i >= 0; i--) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        dp[i][j][k] += dp[i + 1][j][k];
        if (S[i] == 'E') {
          int a = A[i];
          if (a == j) {
            dp[i][j][k] += sx[i + 1][k];
          }
        }
      }
    }
  }
  // MEX
  long long ans = 0;
  for (int n = 0; n < N; n++) {
    if (S[n] != 'M') {
      continue;
    }
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        int m = mex(A[n], j, k);
        ans += dp[n][j][k] * m;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
