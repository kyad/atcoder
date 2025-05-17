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

// xをbase進数で見た時の桁数を返す
int digits(long long x, int base) { int d = 0; while (x > 0) { x /= base; d++; } return d; }

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    long long N;
    int K;
    cin >> N >> K;
    int M = digits(N, 2);
    vector<vector<vector<mint> > > sum(M + 1, vector<vector<mint> >(K + 1, vector<mint>(2, 0)));
    vector<vector<vector<mint> > > count(M + 1, vector<vector<mint> >(K + 1, vector<mint>(2, 0)));
    count[0][0][0] = 1;
    for (int i = 1; i <= M; i++) {
      int l = M - i;
      for (int j = 0; j <= K; j++) {
        // 1を取る時
        if (j >= 1) {
          sum[i][j][1] += sum[i - 1][j - 1][1] + count[i - 1][j - 1][1] * (1LL << l);
          count[i][j][1] += count[i - 1][j - 1][1];
          if (N >> l & 1) {
            sum[i][j][0] += sum[i - 1][j - 1][0] + count[i - 1][j - 1][0] * (1LL << l);
            count[i][j][0] += count[i - 1][j - 1][0];
          }
        }
        // 0を取る時
        sum[i][j][1] += sum[i - 1][j][1];
        count[i][j][1] += count[i - 1][j][1];
        if ((N >> l & 1) == 1) {
          sum[i][j][1] += sum[i - 1][j][0];
          count[i][j][1] += count[i - 1][j][0];
        } else {
          sum[i][j][0] += sum[i - 1][j][0];
          count[i][j][0] += count[i - 1][j][0];
        }
      }
    }
    mint ans = sum[M][K][0] + sum[M][K][1];
    cout << ans.val() << '\n';
  }
  return 0;
}
