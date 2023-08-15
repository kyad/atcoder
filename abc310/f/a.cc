// https://www.youtube.com/watch?v=shcdsRfMg6A&t=4855s

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

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  // dp[i][s]: iまで見た時に状態をsにすることができる場合の数
  // sは出目の合計を0~10にできるかどうかのDPテーブル
  const int M = 10;
  const int M2 = 1<<(M+1);
  vector<mint> dp(M2, 0);
  dp[1] = 1;
  for (int i = 0; i <= N - 1; i++) {
    vector<mint> p(M2, 0);
    swap(dp, p);
    // iからi+1への遷移
    for (int s = 1; s < M2; s++) {  // iの状態
      // i+1回目の出目xで場合分けする
      for (int x = 1; x <= min(10, A[i + 1]); x++) {
        int ns = s;  // xを使わない時
        ns |= (s<<x);  // xを使う時
        ns &= (M2-1);
        dp[ns] += p[s];
      }
      // i+1個目の出目xが11以上の時
      if (A[i + 1] > M) {
        dp[s] += p[s] * (A[i + 1] - M);  // xを使わない時
        // xを使うと11以上になるので、xは使わない場合しかない
      }
    }
  }
  mint count = 0;
  for (int s = 1; s < M2; s++) {
    if (s>>M&1) {
      count += dp[s];
    }
  }
  mint all = 1;
  for (int i = 1; i <= N; i++) {
    all *= A[i];
  }
  mint ans = count / all;
  cout << ans.val() << endl;
  return 0;
}

