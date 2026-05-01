#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// m^n, O(log n)
long long power(long long m, long long n, int mod) {
  long long a = m % mod;
  long long ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return ans;
}

int main() {
  int N, Q, M;
  cin >> N >> Q >> M;
  vector<int> D(N), P(N);
  for (int i = 0; i < N; i++) {
    cin >> D.at(i) >> P.at(i);
    P.at(i)--;
  }
  // ダブリングテーブル d[m][u]: グラフで考えた時、ノードuから2^m回移動した先のノード番号
  // ダブリングテーブル V[m][u]: グラフで考えた時、ノードuから2^m回移動した先の値
  const int DBL = 61;  // K<=10^18の場合、2^60~=10^18まで持っておけば十分
  vector<vector<int>> d(DBL, vector<int>(N));
  vector<vector<long long>> V(DBL, vector<long long>(N));
  // 初期値
  for (int u = 0; u < N; u++) {
    d.at(0).at(u) = P.at(u);
    V.at(0).at(u) = D.at(u) % M;
  }
  // ダブリングテーブルを埋める
  for (int m = 0; m < DBL - 1; m++) {
    for (int u = 0; u < N; u++) {
      // d[2^{m+1}][u]を、d[2^m][*]で表した式
      d.at(m + 1).at(u) = d.at(m).at(d.at(m).at(u));
      int v = d.at(m).at(u);
      long long pow = power(10, (1LL<<m), M);
      //mint pow = pow10[m];
      V.at(m + 1).at(u) = ((V.at(m).at(u) * pow) % M + V.at(m).at(v)) % M;
    }
  }
  for (int qi = 0; qi < Q; qi++) {
    int S;
    long long K;
    cin >> S >> K;
    S--;
    // ダブリングテーブルを使う
    // 何も適用しない時の初期値
    int u = S;
    long long v = 0;
    // K: 適用する回数(グラフで考えた時、移動する回数)
    for (int m = 0; m < DBL; m++) {
      if ((K >> m) & 1LL) {
        // 答えにd[m][*]を適用する
        long long pow = power(10, (1LL<<m), M);
        //mint pow = pow10[m];
        v = ((v * pow) % M + V.at(m).at(u)) % M;
        u = d.at(m).at(u);
      }
    }
    cout << v << '\n';
  }
  return 0;
}
