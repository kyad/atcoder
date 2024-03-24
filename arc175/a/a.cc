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
  int N;
  cin >> N;
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
    P.at(n)--;
  }
  string S;
  cin >> S;
  auto f = [&](int take0) -> mint { // take0が0の時、P0は左を取る。1の時、P0は右を取る。
    vector<bool> remain(N, true);  // 残っている
    mint ans = 1;
    for (int i = 0; i < N; i++) {  // P[i]が使う時の検討
      // P[i]の左右を見る
      int p = P.at(i);  // 左のスプーン、今の人の番号
      int q = (p + 1) % N;  // 右のスプーン
      if (remain.at(p) && remain.at(q)) {
        if (take0 == 0) {  // P0が左(left)なら左を取らなければならない
          if (S.at(p) == 'R') {
            return 0;
          }
          remain.at(p) = false;
        } else {  // P0が右(right)なら右を取らなければならない
          if (S.at(p) == 'L') {
            return 0;
          }
          remain.at(q) = false;
        }
      } else if (remain.at(p) && !remain.at(q)) {
        // 左を取る
        remain.at(p) = false;
        if (take0 == 0) {  // P0が左(left)ならOK
          if (S.at(p) == '?') {
            ans *= 2;
          }
        } else {  // P0が右(right)ならNG
          return 0;
        }
      } else if (!remain.at(p) && remain.at(q)) {
        // 右を取る
        remain.at(q) = false;
        if (take0 == 0) {  // P0が左(left)ならNG
          return 0;
        } else {  // P0が右(right)ならOK
          if (S.at(p) == '?') {
            ans *= 2;
          }
        }
      } else {  // 左右とも残っていない
        return 0;
      }
    }
    return ans;
  };
  mint ans = 0;
  for (int i = 0; i < 2; i++) {
    mint now = f(i);
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
