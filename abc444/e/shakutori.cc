#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  long long D;
  cin >> N >> D;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  long long ans = 0;
  // 尺取り法。[l, r)は半開区間とする
  int r = 0;
  set<long long> st;
  for (int l = 0; l < N; l++) {
    // 条件を満たす最大のrを求める
    while (true) {
      int nr = r + 1;
      if (nr >= N + 1) {
        break;
      }
      // nrが条件を満たしているかチェック
      if (!st.empty()) {  // 空ならばOKなので
        long long x = A.at(nr - 1);
        {
          // xのすぐ上
          auto it = st.lower_bound(x);
          if (it != st.end()) {
            if (abs(*it - x) < D) {  // NG
              break;
            }
          }
        }
        {
          // xのすぐ下
          auto it = st.upper_bound(x);
          if (it != st.begin()) {
            if (abs(*prev(it) - x) < D) {  // NG
              break;
            }
          }
        }
      }
      r = nr;
      // 条件にrを含める
      st.insert(A.at(r - 1));
    }

    // この時点で[l, r)は条件を見たす最大の区間
    int now = r - l;
    ans += now;

    // lをインクリメントする前の処理
    if (l == r) {
      // このとき、[l, r)は空集合なので、条件からlを除外する処理は不要
      r++;  // 先にrをインクリメントする
    } else {
      st.erase(A.at(l));
    }
  }
  cout << ans << '\n';
  return 0;
}
