#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

const long long INF = 4e18;

/**
 * 距離の2乗を返す
 */
template<typename T> T dist2(T x0, T y0, T x1, T y1) {
  return (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    int TSX, TSY, TGX, TGY;
    cin >> TSX >> TSY >> TGX >> TGY;
    int ASX, ASY, AGX, AGY;
    cin >> ASX >> ASY >> AGX >> AGY;
    // スタートからゴールの距離
    double dt2 = dist2(TSX, TSY, TGX, TGY);
    double dt = sqrt(dt2);
    double da2 = dist2(ASX, ASY, AGX, AGY);
    double da = sqrt(da2);
    // 速度の成分
    double vtx = (double)(TGX - TSX) / dt;
    double vty = (double)(TGY - TSY) / dt;
    double vax = (double)(AGX - ASX) / da;
    double vay = (double)(AGY - ASY) / da;
    // 何度も使う変数 相対速度
    double vx = vtx - vax;
    double vy = vty - vay;
    // 何度も使う変数 初期値の差
    int X0 = TSX - ASX;
    int Y0 = TSY - ASY;
    // 時刻tにおける距離を求める関数
    auto f = [&](double t) {
      double ans = ((double)X0 + vx * t) * ((double)X0 + vx * t)
        + ((double)Y0 + vy * t) * ((double)Y0 + vy * t);
      ans = sqrt(ans);
      return ans;
    };
    double ans = INF;
    // 初期位置
    double now = f(0);
    ans = min(ans, now);
    // TとAの速い方のゴール
    double tt = dt / 1;
    double ta = da / 1;
    double tmin = min(tt, ta);
    double tmax = max(tt, ta);
    bool a_is_fast = false;
    if (ta < tt) {
      a_is_fast = true;
    }
    ans = f(tmin);
    ans = min(ans, now);
    // 微分が0
    if (vx * vx + vy * vy != 0) {
      double t1 = - (vx * X0 + vy * Y0) / (vx * vx + vy * vy);
      if (0 <= t1 && t1 <= tmin) {
        double now = f(t1);
        ans = min(ans, now);
      }
    }
    // tmin以降
    // Tが速く止まったとする
    if (a_is_fast) {
      swap(TSX, ASX);
      swap(TSY, ASY);
      swap(TGX, AGX);
      swap(TGY, AGY);
      swap(vtx, vax);
      swap(vty, vay);
    }
    double P = ASX - TGX;
    double Q = ASY - TGY;
    auto g = [&](double t) {
      double ans = (vax * t + P) * (vax * t + P)
        + (vay * t + Q) * (vay * t + Q);
      ans = sqrt(ans);
      return ans;
    };
    // 最後
    now = g(tmax);
    ans = min(ans, now);
    // 微分が0
    double t2 = - (P * vax + Q * vay) / (vax * vax + vay * vay);
    if (tmin <= t2 && t2 <= tmax) {
      double now = g(t2);
      ans = min(ans, now);
    }
    cout << setprecision(16) << ans << '\n';
  }
  return 0;
}
