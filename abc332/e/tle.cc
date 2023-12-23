// https://www.youtube.com/watch?v=tGS6K5a0ZQE&t=4072s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int N, D;
  cin >> N >> D;
  vector<double> W(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> W.at(i);
  }
  double ave = 0;
  for (int i = 0; i < N; i++) {
    ave += W[i];
  }
  ave /= D;

  int N2 = 1<<N;

  // x[s]: 状態sに関するWの二乗和
  vector<__float128> x(N2, 0);
  for (int s = 0; s < N2; s++) {
    for (int j = 0; j < N; j++) {
      if (s>>j&1) {
        x[s] += W.at(j);
      }
    }
  }

  // dp[i][s]: i袋目(0<=i<=D)まで見た時に、まだ決まっていないグッズがs(0<=s<2^N)の時のx_i^2の合計
  const long long INF = 4e18;
  vector<vector<__float128> > dp(D + 1, vector<__float128>(N2, INF));
  dp[0][N2 - 1] = 0;
  for (int i = 1; i <= D; i++) {
    for (int s = 0; s < N2; s++) {
      // i個目の袋に入れるグッズの集合をtとする。tはsの部分集合を動く。
      for (int t = s;; t = (t - 1) & s) {
        if (t == 0) {  // 終了条件
          break;
        }
        __float128 now = dp[i - 1][s] + x[t] * x[t];
        int ns = s ^ t;  // 次はS\T。
        chmin(dp[i][ns], now);
      }
    }
  }
  double ans = dp[D][0] / D - ave * ave;
  cout << setprecision(15) << ans << endl;
  return 0;
}
