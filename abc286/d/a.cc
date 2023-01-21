#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> A(N + 1, 0), B(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n) >> B.at(n);
  }
  vector<vector<bool> > dp(N + 1, vector<bool>(X + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= X; j++) {
      for (int x = 0; x <= B[i]; x++) {
        int pj = j - A[i] * x;
        if (pj < 0) {
          continue;
        }
        if (dp[i - 1][pj]) {
          dp[i][j] = true;
        }
      }
    }
  }
  bool ans = dp[N][X];
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
