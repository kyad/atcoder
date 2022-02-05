// https://atcoder.jp/contests/abc235/tasks/abc235_f
// cf. https://atcoder.jp/contests/abc235/submissions/28591650
// MLE

#include <iostream>
#include <vector>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
typedef modint998244353 mint;

int main() {
  string N;
  cin >> N;
  int n = N.size();
  vector<vector<vector<mint> > > dp(n + 1, vector<vector<mint> >(1<<10, vector<mint>(2, 0)));
  vector<vector<vector<mint> > > ds(n + 1, vector<vector<mint> >(1<<10, vector<mint>(2, 0)));
  // j == 0: Nと一致
  // j == 1: N未満
  for (int i = 0; i < n; i++) {
    int ni = i + 1;
    int d = N[i] - '0';
    for (int s = 0; s < 1<<10; s++) {
      for (int j = 0; j < 2; j++) {
        mint count = dp[i][s][j];
        mint sum = ds[i][s][j];
        for (int x = 0; x < 10; x++) {
          int nj = j;
          if (j == 0) {
            if (x > d) {
              continue;
            }
            if (x < d) {
              nj = 1;
            }
          }
          int ns = s | 1<<x;
          dp[ni][ns][nj] += count;
          ds[ni][ns][nj] += (sum * 10 + count * x);
          // 初期値を発生させる
          // s == 0 は、ns = s | xを発生させたいから。
          // j == (i == 0 ? 0 : 1)は、初期状態0はi==0の時はj==0扱い、i>0の時はj==1扱いで考えるから。
          // cf. https://qiita.com/pinokions009/items/1e98252718eeeeb5c9ab#%E5%88%9D%E6%9C%9F%E6%9D%A1%E4%BB%B6
          // x != 0は、最初の桁は0になってはいけないから。
          if (s == 0 && j == (i == 0 ? 0 : 1) && x != 0) {
            dp[ni][ns][nj]++;
            ds[ni][ns][nj] += x;
          }
        }
      }
    }
  }
  int M;
  cin >> M;
  int mask = 0;
  for (int m = 0; m < M; m++) {
    int C;
    cin >> C;
    mask |= 1<<C;
  }
  mint ans = 0;
  for (int s = 0; s < 1<<10; s++) {
    if (mask == (mask & s)) {
      for (int j = 0; j < 2; j++) {
        ans += ds[n][s][j];
      }
    }
  }
  cout << ans.val() << endl;
  return 0;
}
