#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int> > A(H + 1, vector<int>(W + 1, -1));
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> A[i][j];
    }
  }
  auto check = [&](int m, int a, int b, int c) -> bool {
    bool ans = true;
    for (int j = 1; j <= W; j++) {
      bool now = false;
      if (j >= 2 && A[m][j] == A[m][j - 1]) {
        now = true;
      }
      if (j <= H - 1 && A[m][j] == A[m][j + 1]) {
        now = true;
      }
      int q = A[m][j];
      if (b) {
        q = 1 - q;
      }
      if (m != 1) {
        // check m - 1 and m
        assert(a >= 0);
        int p = A[m - 1][j];
        if (a) {
          p = 1 - p;
        }
        if (p == q) {
          now = true;
        }
      }
      if (m != H) {
        // check m and m + 1
        assert(c >= 0);
        int r = A[m + 1][j];
        if (c) {
          r = 1 - r;
        }
        if (q == r) {
          now = true;
        }
      }
      if (!now) {
        ans = false;
      }
    }
    return ans;
  };

  const int INF = 1e9+1;
  if (H == 2) {
    int ans = INF;
    for (int k = 0; k < 2; k++) {
      for (int l = 0; l < 2; l++) {
        if (check(2, l, k, -1) && check(1, -1, l, k)) {
          ans = min(ans, k + l);
        }
      }
    }
    if (ans == INF) {
      ans = -1;
    }
    cout << ans << endl;
    return 0;
  }

  vector<vector<vector<int> > > dp(H + 1, vector<vector<int> > (2, vector<int>(2, INF)));
  for (int k = 0; k < 2; k++) {
    for (int l = 0; l < 2; l++) {
      if (!check(1, -1, l, k)) {  // 1行目のチェック
        continue;
      }
      dp[2][k][l] = k + l;
    }
  }

  // dp[i - 1][pk][pl] --> dp[i][nk][nl], nl==pk
  for (int i = 3; i <= H; i++) {
    for (int pk = 0; pk < 2; pk++) {
      for (int pl = 0; pl < 2; pl++) {
        for (int nk = 0; nk < 2; nk++) {
          int nl = pk;
          //cout <<"("<<i<<","<<pk<<","<<pl<<")->("<<i+1<<","<<nk<<","<<nl<<")"<<endl;
          if (dp[i - 1][pk][pl] == INF) {
            continue;
          }
          if (!check(i - 1, pl, nl, nk)) {
            continue;
          }
          chmin(dp[i][nk][nl], dp[i - 1][pk][pl] + nk);
        }
      }
    }
  }
  int ans = INF;
  for (int k = 0; k < 2; k++) {
    for (int l = 0; l < 2; l++) {
      //cout <<"("<<H<<","<<k<<","<<l<<")"<<endl;
      if (!check(H, l, k, -1)) {  // 最終行のチェック
        continue;
      }
      //cout <<"("<<H<<","<<k<<","<<l<<")"<<"OK"<<endl;
      chmin(ans, dp[H][k][l]);
    }
  }
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
