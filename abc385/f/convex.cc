// https://www.youtube.com/watch?v=O5l04fNO-bY&t=8276s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Point {
  long long x;
  long long y;
};

ostream& operator<<(ostream& os, const Point &p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}


template<class T> T outprod2(T ax, T ay, T bx, T by) {
  return ax * by - ay * bx;
}

int main() {
  int N;
  cin >> N;
  double ans = -1;
  // 凸包を求める
  vector<Point> ps;
  for (int i = 0; i < N; i++) {
    long long X, H;
    cin >> X >> H;
    Point p = {X, H};
    while (ps.size() >= 2) {
      Point a = ps.back();
      Point b = ps.end()[-2];
      Point pa = {a.x - p.x, a.y - p.y};
      Point pb = {b.x - p.x, b.y - p.y};
      long long oprod = pa.x * pb.y - pa.y * pb.x;
      if (oprod > 0) {  // 凸の時
        break;
      }
      ps.pop_back();
    }
    ps.push_back(p);
    {
      // 傾きを確認する
      if (ps.size() >= 2) {
        Point a = ps.back();
        Point b = ps.end()[-2];
        long long p = b.y * (b.x - a.x) - b.x * (b.y - a.y);
        long long q = b.x - a.x;
        double now = (double)p / q;
        ans = max(ans, now);
      }
    }
  }
  if (ans < 0) {
    cout << -1 << endl;
  } else {
    cout << setprecision(15) << ans << endl;
  }
  return 0;
}
