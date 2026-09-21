#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> T(N);
  for (int i = 0; i < N; i++) {
    cin >> T.at(i);
  }
  // 尺取り法。[l, r)は半開区間とする
  int r = 0;
  map<int, int> mp;
  int k = 0;  // 重複している個数
  size_t ans = 0;
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
      int dk;
      if (mp.contains(T.at(r))) {
        dk = 1;
      } else {
        dk = 0;
      }
      int nk = k + dk;
      if (nk > K) {
        break;
      }
      r = nr;
      // 条件にrを含める
      // 例：
      // sum = nsum;
      mp[T.at(r - 1)]++;
      k = nk;
    }

    // この時点で[l, r)は条件を見たす最大の区間
    // 何かする。
    // r=0の場合があるので、r=0の場合は配列のr-1番目にアクセスしないように注意する。
    // 例：
    // ans = max(ans, r - l);
    ans = max(ans, mp.size());

    // lをインクリメントする前の処理
    if (l == r) {
      // このとき、[l, r)は空集合なので、条件からlを除外する処理は不要
      r++;  // 先にrをインクリメントする
    } else {
      // 条件からlを除外する
      // 例：
      // sum -= (T[l] == 'x');
      assert(mp[T.at(l)] >= 1);
      if (mp[T.at(l)] == 1) {
        mp.erase(T.at(l));
      } else {
        mp[T.at(l)]--;
        k--;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
