// https://atcoder.jp/contests/abc323/editorial/7349

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// Cを原点かつBが第一象限にあるように正規化
void normalize(long long& XA, long long& YA, long long& XB, long long& YB, long long XC, long long YC) {
  XA -= XC; YA -= YC;
  XB -= XC; YB -= YC;
  if (XB < 0) {
    XA = -XA; XB = -XB;
  }
  if (YB < 0) {
    YA = -YA; YB = -YB;
  }
}

// S -> T
long long dist(long long sx, long long sy, long long tx, long long ty) {
  long long ans = abs(sx - tx) + abs(sy - (ty + 1));
  if (sx == tx && sy < ty) ans += 2;
  return ans;
}

// Y移動の最小値
long long solvey(long long& XA, long long& YA, long long XB, long long& YB) {
  if (YB == 0) {
    return 0;
  }
  // (XA, YA) --> (XB, YB+1)
  long long ans = dist(XA, YA, XB, YB);
  // (XB, YB+1) --> (XB, 1)
  ans += YB;
  // 終了位置
  XA = XB; YA = 1;
  YB = 0;
  return ans;
}

// Y軸に沿って移動→X軸に沿って移動の順に合わせる時の答
long long solveyx(long long XA, long long YA, long long XB, long long YB) {
  // Y軸に沿って移動
  long long disty = solvey(XA, YA, XB, YB);

  // X軸に沿って移動
  long long distx = solvey(YA, XA, YB, XB);

  long long ans = disty + distx;
  return ans;
}


int main() {
  long long XA, YA, XB, YB, XC, YC;
  cin >> XA >> YA >> XB >> YB >> XC >> YC;
  normalize(XA, YA, XB, YB, XC, YC);

  // Y軸に沿って移動→X軸に沿って移動の順に合わせる時の答
  long long ansyx = solveyx(XA, YA, XB, YB);
  
  // X軸に沿って移動→Y軸に沿って移動の順に合わせる時の答
  long long ansxy = solveyx(YA, XA, YB, XB);

  long long ans = min(ansyx, ansxy);

  cout << ans << endl;
  return 0;
}
