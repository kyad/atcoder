#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N + 1, 0), B(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n) >> B.at(n);
  }
  vector<vector<int> > dp(N + 1, vector<int>(10001, -1));
  dp[0][0] = 0;
  for (int i = 0; i <= N - 1; i++) {
    for (int j = 0; j <= 10000; j++) {
      if (dp[i][j] < 0) {
        continue;
      }
      // (i, j)からの遷移
      if (j + A[i] <= 10000) {
        dp[i + 1][j + A[i + 1]] = 1;
      }
      if (j + B[i] <= 10000) {
        dp[i + 1][j + B[i + 1]] = 0;
      }
    }
  }
#if 0
  for (int i = 0; i <= N; i++) {
    cout << "i=" << i << " ";
    for (int j = 0; j < 40; j++) {
      cout << j << ":" << dp[i][j] << " ";
    }
    cout << endl;
  }
#endif
  int j = S;
  bool ans1 = true;
  vector<char> ans2;
  for (int i = N; i >= 1; i--) {
    if (dp[i][j] < 0) {
      ans1 = false;
      break;
    }
    if (dp[i][j] == 1) {
      j -= A[i];
      ans2.push_back('H');
    } else {
      j -= B[i];
      ans2.push_back('T');
    }
    if (j < 0) {
      ans1 = false;
      break;
    }
  }
  if (ans1) {
    cout << "Yes" << endl;
    reverse(ans2.begin(), ans2.end());
    for (size_t i = 0; i < ans2.size(); i++) {
      cout << ans2.at(i);
    }
    cout << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
