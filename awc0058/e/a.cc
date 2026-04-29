#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  int ans = 1;
  const int INF = 2e9;
  int mn = INF;
  int mx = -INF;
  multiset<int> ms;
  // 尺取り法。[l, r)は半開区間とする
  int r = 0;
  for (int l = 0; l < N; l++) {
    // 条件を満たす最大のrを求める
    while (true) {
      int nr = r + 1;
      if (nr >= N + 1) {
        break;
      }
      // nrが条件を満たしているかチェック
      // 例：
      // int nsum = sum + (T[r] == 'x');
      // if (nsum > K) {
      //   break;
      // }
      int nmn = min(mn, A.at(nr - 1));
      int nmx = max(mx, A.at(nr - 1));
      if (nmx - nmn <= K) {
        // ok
      } else {
        break;
      }
      r = nr;
      // 条件にrを含める
      // 例：
      // sum = nsum;
      mn = nmn;
      mx = nmx;
      ms.insert(A.at(r - 1));
    }

    // この時点で[l, r)は条件を見たす最大の区間
    // 何かする。
    // 例：
    ans = max(ans, r - l);

    // lをインクリメントする前の処理
    if (l == r) {
      // このとき、[l, r)は空集合なので、条件からlを除外する処理は不要
      r++;  // 先にrをインクリメントする
    } else {
      // 条件からlを除外する
      // 例：
      // sum -= (T[l] == 'x');
      ms.erase(ms.find(A.at(l)));
      if (ms.empty()) {
        mn = INF;
        mx = -INF;
      } else {
        mn = *ms.begin();
        mx = *ms.rbegin();
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
