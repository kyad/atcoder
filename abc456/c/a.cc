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
  string S;
  cin >> S;
  int N = S.size();
  // 尺取り法。[l, r)は半開区間とする
  int r = 0;
  mint ans = 0;
  for (int l = 0; l < N; l++) {
    // 条件を満たす最大のrを求める
    while (true) {
      int nr = r + 1;
      if (nr >= N + 1) {
        break;
      }
      // nrが条件を満たしているかチェック
      if (nr - l >= 2 && S.at(nr - 2) == S.at(nr - 1)) {
        break;
      }
      r = nr;
    }

    // この時点で[l, r)は条件を見たす最大の区間
    // 何かする。
    ans += (r - l);

    // lをインクリメントする前の処理
    if (l == r) {
      // このとき、[l, r)は空集合なので、条件からlを除外する処理は不要
      r++;  // 先にrをインクリメントする
    } else {
      // 条件からlを除外する
      // 例：
      // sum -= (T[l] == 'x');
    }
  }
  
  cout << ans << '\n';
  return 0;
}
