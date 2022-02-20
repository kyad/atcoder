#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> A(N), B(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n) >> B.at(n);
  }
  vector<vector<bool> > dp(N + 1, vector<bool>(10001, false));
  dp[0][0] = true;
  for (int n = 0; n < N; n++) {
    vector<bool> next(10001, false);
    for (int j = 0; j <= 10000; j++) {
      if (dp[n][j] == false) {
        continue;
      }
      int nj;
      nj = j + A[n];
      if (nj <= 10000) {
        next[nj] = true;
      }
      nj = j + B[n];
      if (nj <= 10000) {
        next[nj] = true;
      }
    }
    for (int j = 0; j <= 10000; j++) {
      dp[n + 1][j] = next[j];
    }
  }
  string ans = dp[N][X] ? "Yes" : "No";
  cout << ans << endl;
  return 0;
}
