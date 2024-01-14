// https://www.youtube.com/watch?v=l1KYJrKX8x4&t=6895s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

// int(sqrt(n)) for 0 <= n <= 10^18 (答えがintの範囲で収まる場合に動作する)
// 計算量 O(log(RIGHT_MAX))
int int_sqrt(long long n) {
  if (n == 0) {
    return 0;
  }    
  int left = 0;
  const int RIGHT_MAX = 1e9+1;  // >= sqrt(max(n)). 2乗してlong longの範囲に収まること
  int right = RIGHT_MAX;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    long long y = (long long)mid * mid - n;
    if (y <= 0) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return left;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  // dp[i]: iで終わる集合の確定数
  vector<mint> dp(N, 0);
  const int D = int_sqrt(200000);
  // s[j][i]: iまで見た時にj=A(1<=j<D)を使っている時の集合の経過の数
  vector<vector<mint> > s(D, vector<mint>(N, 0));
  dp[0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 1; j < D; j++) {
      dp[i] += s[j][i];
    }
    for (int j = 1; j < D; j++) {
      if (i + j < N) {
        s[j][i + j] += s[j][i];
      }
    }
    if (A[i] < D) {
      if (i + A[i] < N) {
        s[A[i]][i + A[i]] += dp[i];
      }
    } else {
      for (int k = i + A[i]; k < N; k += A[i]) {
        dp[k] += dp[i];
      }
    }
  }
  mint ans = 0;
  for (int i = 0; i < N; i++) {
    ans += dp[i];
  }
  cout << ans << endl;
  return 0;
}
