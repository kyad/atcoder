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
  long long SX, SY;
  cin >> SX >> SY;
  long long TX, TY;
  cin >> TX >> TY;

  // まず、SYを偶数にしたい
  if (SY % 2 == 1) {
    SX++;
    SY++;
    TX++;
    TY++;
  }

  // SY=0にする
  TY -= SY;  // SYが偶数なので
  SY = 0;

  // SX=0 or 1にする
  long long dx = (SX / 2) * 2;
  SX -= dx;
  TX -= dx;

  // TY < 0
  if (TY < 0) {
    TY *= -1;
  }

  // TX < 0
  if (TX < 0) {
    TX = -TX + 1;
  }

  // 計算
  long long ans = TY;
  if (TX <= TY + 1) {
  } else {
    ans += ceildiv(TX - (TY + 1), 2LL);
  }
  cout << ans << endl;
  return 0;
}
