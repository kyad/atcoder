#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  // 尺取り法。[l, r)は半開区間とする
  int r = 0;
  long long ans = 0;
  for (int l = 0; l < N; l++) {
    // 条件を満たす最大のrを求める
    while (true) {
      int nr = r + 1;
      if (nr >= N + 1) {
        break;
      }
      if (l == nr - 1) {  // 自明でOK
        r = nr;
        continue;
      }
      // nrが条件を満たしているかチェック
      cout << "? " << (l + 1) << ' ' << (nr - 1 + 1) << endl;
      string res;
      cin >> res;
      if (res == "No") {
        break;
      }
      r = nr;
      // 条件にrを含める
    }

    // この時点で[l, r)は条件を見たす最大の区間
    // 何かする。
    // r=0の場合があるので、r=0の場合は配列のr-1番目にアクセスしないように注意する。
    long long now = max(0, r - l - 1);
    ans += now;

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

  cout << "! " << ans << endl;
  return 0;
}
