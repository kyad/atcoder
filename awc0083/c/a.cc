#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long M;
  cin >> N >> M;
  vector<long long> X(N), C(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> C.at(i);
  }
  // 尺取り法。[l, r)は半開区間とする
  int r = 0;
  long long sum = 0;
  long long ans = 0;
  for (int l = 0; l < N; l++) {
    // 条件を満たす最大のrを求める
    while (true) {
      int nr = r + 1;
      if (nr >= N + 1) {
        break;
      }
      // nrが条件を満たしているかチェック
      long long nsum = sum + C.at(nr - 1);
      if (nsum > M) {
        break;
      }
      r = nr;
      // 条件にrを含める
      sum = nsum;
    }

    // この時点で[l, r)は条件を見たす最大の区間
    // 何かする。
    if (r >= 1) {
      ans = max(ans, X.at(r - 1) - X.at(l));
    }

    // lをインクリメントする前の処理
    if (l == r) {
      // このとき、[l, r)は空集合なので、条件からlを除外する処理は不要
      r++;  // 先にrをインクリメントする
    } else {
      // 条件からlを除外する
      // 例：
      sum -= C.at(l);
    }
  }
  cout << ans << '\n';
  return 0;
}
