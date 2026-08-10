#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// xをbase進数で見た時の桁数を返す
int digits(long long x, int base, vector<int> &S) {
  int d = 0;
  while (x > 0) {
    S.push_back(x % base);
    x /= base;
    d++;
  }
  S.push_back(0);
  reverse(S.begin(), S.end());
  return d;
}

int main() {
  long long N;
  int K;
  cin >> N >> K;
  N++;
  vector<int> S;
  int D = digits(N, 10, S);
  // dp[i][j][k][l][m]: 上位桁からiまで見た時の個数で、i番目にjを置いて、揺れ値がkで、l=1ならN未満が確定、m=1なら0以外を使っている
  vector<vector<vector<vector<vector<long long>>>>> dp(D + 1, vector<vector<vector<vector<long long>>>>(10,  vector<vector<vector<long long>>>(K + 1, vector<vector<long long>>(2, vector<long long>(2, 0)))));
  dp.at(0).at(0).at(0).at(0).at(0) = 1;
  for (int i = 0; i <= D - 1; i++) {
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k <= K; k++) {
        for (int l = 0; l < 2; l++) {
          for (int m = 0; m < 2; m++) {
            int nj_max = 9;
            if (l == 0) {
              nj_max = S[i + 1];
            }
            for (int nj = 0; nj <= nj_max; nj++) {
              int ni = i + 1;
              int nk;
              if (m == 0) {
                nk = 0;  // 1桁目の場合、揺れ値は0
              } else {
                nk = k + abs(j - nj);
              }
              if (nk > K) {
                continue;
              }
              int nl;
              if (l == 1) {
                nl = 1;
              } else {
                if (S.at(ni) == nj) {
                  nl = 0;
                } else {
                  nl = 1;
                }
              }
              int nm;
              if (m == 1) {
                nm = 1;
              } else {
                if (nj != 0) {
                  nm = 1;
                } else {
                  nm = 0;
                }
              }
              dp.at(ni).at(nj).at(nk).at(nl).at(nm) += dp.at(i).at(j).at(k).at(l).at(m);
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int j = 0; j <= 9; j++) {
    ans += dp.at(D).at(j).at(K).at(1).at(1);
  }
  cout << ans << '\n';
  return 0;
}
