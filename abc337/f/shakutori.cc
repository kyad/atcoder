// https://www.youtube.com/watch?v=3wCA_J6cfqY&t=7243s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> C(2 * N, -1);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
    C[i]--;
  }
  // Cをリピートする
  for (int i = N; i < 2 * N; i++) {
    C[i] = C[i - N];
  }
  // cnt[c]: 色cの個数
  vector<int> cnt(N, 0);
  for (int i = 0; i < N; i++) {
    cnt[C[i]]++;
  }
  
  // 状態
  map<int, int> mp;  // mp[c]: 今の色cの個数
  multiset<int> ms;  // 今の箱の色の集合
  vector<int> hist(N, 0);  // hist[c]: msの中にあるcの数
  vector<int> R(N, 0);  // R[c]: cを入れられる残り個数
  int sum = 0;  // 箱の中にあるボールの総数

  // 尺取り法。[l, r)は半開区間とする
  // lから始めてM色見つかるまで進める
  int r = 0;
  for (int l = 0; l < N; l++) {
    // 条件を満たす最大のrを求める
    while (true) {
      int nr = r + 1;
      if (nr >= l + N + 1) {
        break;
      }
      // nrが条件を満たしているかチェック
      int nc = C[nr - 1];
      if (ms.contains(nc) && R[nc] > 0) {
        // 既にある箱に入れる
        // 条件にrを含める
        r = nr;
        R[nc]--;
        continue;
      } else if ((int)ms.size() < M) {
        // 新しい箱を作る
        // 条件にrを含める
        r = nr;
        ms.insert(nc);
        hist[nc]++;
        R[nc] = K - 1;
        int diff;
        if (hist[nc] <= cnt[nc] / K) {
          diff = K;
        } else {
          diff = cnt[nc] % K;
        }
        sum += diff;
        continue;
      } else {
        break;
      }
    }

    // この時点で[l, r)は条件を見たす最大の区間
    // 何かする。
    cout << sum << '\n';

    // lをインクリメントする前の処理
    if (l == r) {
      // このとき、[l, r)は空集合なので、条件からlを除外する処理は不要
      r++;  // 先にrをインクリメントする
    } else {
      // 条件からlを除外する
      R[C[l]]++;
      if (R[C[l]] == K) {
        // 箱を除外する
        int diff;
        if (hist[C[l]] <= cnt[C[l]] / K) {
          diff = K;
        } else {
          diff = cnt[C[l]] % K;
        }
        sum -= diff;
        ms.erase(ms.find(C[l]));
        hist[C[l]]--;
        R[C[l]] = 0;
      }
    }
  }
  return 0;
}
