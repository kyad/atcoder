#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }

  long long ans = 0;

  // 尺取り法。
  int r = 0;  // [l, r]は閉区間とする
  for (int l = 0; l < N; l++) {
    bool need_d = false;
    int d = -1;
    if (l < r) {
      d = A.at(l + 1) - A.at(l);
    } else {
      need_d = true;  // l==rの時はあとでdを決める必要がある
    }
    // 条件を満たす最大のrを求める
    while (true) {
      int nr = r + 1;
      if (nr >= N) {
        break;
      }
      // nrが条件を満たしているかチェック
      int count = r - l + 1;
      if (need_d && (count == 1)) {
        d = A.at(l + 1) - A.at(l);  // この場合は常にOK
      } else {
        // 公差チェック
        if (A.at(nr) - A.at(r) != d) {
          d = A.at(nr) - A.at(r);
          break;
        }
      }
      r = nr;
      // 条件にrを含める
    }

    // この時点で[l, r)は条件を見たす最大の区間
    // 何かする。
    long long now = r - l + 1;
    ans += now;

    // lをインクリメントする前の処理
    if (l == r) {
      // このとき、[l, r)は空集合なので、条件からlを除外する処理は不要
      r++;  // 先にrをインクリメントする
    } else {
      // 条件からlを除外する
    }
  }
  cout << ans << endl;
  return 0;
}
