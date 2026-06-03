// https://atcoder.jp/contests/awc0083/editorial/21053

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
  }
  vector<vector<long long>> C(N, vector<long long>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> C.at(i).at(j);
    }
  }
  int N2 = 1 << N;
  // dp[S][u]: Sの最初からuまでのCの合計の最大値
  const long long INF = 4e18;
  vector<vector<long long>> dp(N2, vector<long long>(N, -INF));
  for (int u = 0; u < N; u++) {
    dp.at(1 << u).at(u) = 0;
  }
  auto start = [&](int bit) -> int {
    int start = -1;  // Sの最初
    for (int i = 0; i < N; i++) {
      if (bit >> i & 1) { // iを使う
        start = i;
        break;
      }
    }
    return start;
  };
  for (int bit = 1; bit < N2; bit++) {
    int st = start(bit);
    // 遷移
    for (int i = 0; i < N; i++) {
      if (!(bit >> i & 1)) {  // iはS内のみ対象
        continue;
      }
      for (int j = st + 1; j < N; j++) {
        if (bit >> j & 1) {  // jはS外のみ対象
          continue;
        }
        chmax(dp.at(bit | (1 << j)).at(j), dp.at(bit).at(i)+ C.at(i).at(j));
      }
    }
  }
  long long ans = -INF;
  for (int bit = 1; bit < N2; bit++) {
    if (__builtin_popcount(bit) != K) {
      continue;
    }
    int st = start(bit);
    long long sumP = 0;
    for (int u = 0; u < N; u++) {
      if (bit >> u & 1) {
        sumP += P.at(u);
      }
    }
    for (int u = 0; u < N; u++) {
      if (!(bit >> u & 1)) {
        continue;
      }
      long long now = dp.at(bit).at(u) + C.at(st).at(u) + sumP;
      chmax(ans, now);
    }
  }
  cout << ans << '\n';
  return 0;
}
