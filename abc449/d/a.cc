#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long f(long long P, long long Q) {
  if (P == 0 || Q == 0) {
    return 0;
  }
  // P>=Qとする
  if (P < Q) {
    swap(P, Q);
  }
  long long p = (P / 2) * 2;
  long long q = (Q / 2) * 2;
  // (Q, Q)の内側
  long long ans0 = q * (q + 1) / 2;
  // (Q, Q)の外側
  long long r = ((Q + 2) / 2) * 2;
  long long ans1 = ((p - r) / 2 + 1) * Q;
  long long ans = ans0 + ans1;
  return ans;
}

long long g(long long R) {
  if (R == 0) {
    return 0;
  }
  long long r = (R / 2) * 2;
  return r / 2;
}

// 第1象限を求める
long long h(long long L, long long R, long long D, long long U) {
  if (R <= 0) return 0;
  if (U <= 0) return 0;
  if (L <= 0) L = 1;
  if (R <= 0) R = 1;
  if (D <= 0) D = 1;
  if (U <= 0) U = 1;
  long long a = f(R, U);
  long long b = f(L - 1, U);
  long long c = f(R, D - 1);
  long long d = f(L - 1, D - 1);
  long long ans = a - b - c + d;
  return ans;
}

// x軸(正)を求める
long long x(long long L, long long R) {
  if (L <= 0) L = 1;
  if (R <= 0) R = 1;
  long long ans = g(R) - g(L - 1);
  return ans;
}

int main() {
  long long L, R, D, U;
  cin >> L >> R >> D >> U;
  long long ans1 = h(L, R, D, U);  // 第1象限
  long long ans2 = h(-R, -L, D, U);  // 第2象限
  long long ans3 = h(-R, -L, -U, -D);  // 第3象限
  long long ans4 = h(L, R, -U, -D);  // 第4象限
  long long x1 = 0, x2 = 0;
  if (D <= 0 && 0 <= U) {
    x1 = x(L, R); // x軸 正
    x2 = x(-R, -L); // x軸 負
  }
  long long y1 = 0, y2 = 0;
  if (L <= 0 && 0 <= R) {
    y1 = x(D, U); // y軸 正
    y2 = x(-U, -D); // y軸 負
  }
  long long z = 0;
  if (D <= 0 && 0 <= U && L <= 0 && 0 <= R) {
    z = 1;
  }
  long long ans = ans1 + ans2 + ans3 + ans4 + x1 + x2 + y1 + y2 + z;
  cout << ans << '\n';
  return 0;
}
