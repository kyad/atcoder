#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, const T b) { a = max(a, b); }

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N + 1, 0), B(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n) >> B.at(n);
  }
  vector<int> C(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    C.at(n) = min(A.at(n), B.at(n));
  }
  for (int n = 1; n <= N; n++) {
    S -= C[n];
    A[n] -= C[n];
    B[n] -= C[n];
  }
  if (S < 0) {
    cout << "Impossible" << endl;
    return 0;
  }
  vector<vector<int> > dp(N + 1, vector<int>(S + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= S; j++) {
      if (j - A[i] >= 0) {  // Aを取る
        chmax(dp[i][j], dp[i - 1][j - A[i]]);
      }
      if (j - B[i] >= 0) {  // Bを取る
        chmax(dp[i][j], dp[i - 1][j - B[i]]);
      }
    }
  }
  if (dp[N][S] == 0) {
    cout << "Impossible" << endl;
    return 0;
  }
  int j = S;
  string ans;
  for (int i = N; i >= 1; i--) {
    assert(dp[i][j] == 1);
    if (j - A[i] >= 0 && dp[i - 1][j - A[i]]) {
      ans.push_back('A');
      j -= A[i];
    } else if (j - B[i] >= 0 && dp[i - 1][j - B[i]]) {
      ans.push_back('B');
      j -= B[i];
    } else {
      assert(false);
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
