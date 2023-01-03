// https://atcoder.jp/contests/arc137/tasks/arc137_b

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  const int INF = 1e9;
  // mn[0] = min(S[r]-S[l]), mn[1] = -max(S[r]-S[l])を求める
  int table[2][2] = {{1, -1}, {-1, 1}};
  int mn[2];
  for (int k = 0; k < 2; k++) {
    vector<int> B(N + 1, 0);
    for (int n = 1; n <= N; n++) {
      B[n] = table[k][A[n]];
    }
    vector<int> S(N + 1, 0);
    for (int n = 1; n <= N; n++) {
      S[n] = S[n - 1] + B[n];
    }
    mn[k] = INF;
    int mxS = -INF;  // max_{l<=r}S[l]
    for (int r = 0; r <= N; r++) {
      mxS = max(mxS, S[r]);
      mn[k] = min(mn[k], S[r] - mxS);
    }
  }
  int ans = -mn[1] - mn[0] + 1;
  cout << ans << endl;
  return 0;
}
