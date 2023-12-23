#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> T ceildiv(T a, T b);
// floor(a / b)を計算する。aが負の場合は負の無限大へ丸める。
template<class T> T floordiv(T a, T b) { assert(b > 0); return (a >= 0) ? (a / b) : (-ceildiv(-a, b)); }
// ceil(a / b)を計算する。aが負の場合は正の無限大へ丸める。
template<class T> T ceildiv(T a, T b) { assert(b > 0); return (a >= 0) ? ((a + b - 1) / b) : (-floordiv(-a, b)); }

int main() {
  long long A, M, L, R;
  cin >> A >> M >> L >> R;
  L -= A; R -= A;
  L = ceildiv(L, M);
  R = floordiv(R, M);
  long long ans;
  if (R < L) {
    ans = 0;
  } else {
    ans = R - L + 1;
  }
  cout << ans << endl;
  return 0;
}
