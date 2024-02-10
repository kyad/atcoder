#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

using lll = __int128;

// ax + by = gcd(a, b)を満たすx, yを返す
lll ext_gcd(lll a, lll b, lll &x, lll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  lll d = ext_gcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}


bool solve(lll X, lll Y, lll &A, lll &B) {
  assert(X > 0);
  assert(Y > 0);
  // AY - BX = 2が整数解を持つか？
  lll Z = 2;
  lll g = __gcd(X, Y);
  if (Z % g != 0) {
    return false;
  }
  // YA + X(-B) = gの解(A, B)を求める
  ext_gcd(Y, X, A, B);
  B *= -1;
  A *= (Z / g);
  B *= (Z / g);
#if 0
  if (A < 0 || B < 0) {
    return false;
  }
#endif
  if (A > 1000000000000000000LL) {
    return false;
  }
  if (B > 1000000000000000000LL) {
    return false;
  }
  return true;
}

bool solve1(lll X, lll Y, lll &A, lll &B) {
  lll xfac = 1;
  lll yfac = 1;
  if (X < 0) {
    X *= -1;
    xfac = -1;
  }
  if (Y < 0) {
    Y *= -1;
    yfac = -1;
  }
  if (Y == 0) {
    // 特殊ケース：軸上にある時
    if (X == 1 || X == 2) {
      A = 0;
      B = 2 / X;
      return true;
    }
    return false;
  }
  if (X == 0) {
    return false;  // もう片方で調べる
  }
  // 軸上に無い時
  if (solve(X, Y, A, B)) {
    A *= xfac;
    B *= yfac;
    return true;
  } else {
    return false;
  }
}


int main() {
  long long X, Y;
  cin >> X >> Y;
  lll A, B;
  if (solve1(X, Y, A, B)) {
    long long a = A;
    long long b = B;
    cout << a << ' ' << b << endl;
    return 0;
  } else if (solve1(Y, X, B, A)) {
    long long a = A;
    long long b = B;
    cout << a << ' ' << b << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
