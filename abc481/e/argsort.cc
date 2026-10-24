#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// https://atcoder.jp/contests/abc442/editorial/15136
long long cross(long long ax, long long ay, long long bx, int by) {
  return (long long) ax * by - (long long) ay * bx;
}

struct Point {
  int x, y, idx, h;
  Point(int _x, int _y) : x(_x), y(_y) {
    h = (y < 0 or (y == 0 and x < 0));
  };
  bool operator<(const Point &right) const {
    if (h != right.h) return h < right.h;
    long long cr = cross(x, y, right.x, right.y);
    return cr > 0;
  }
  bool operator<=(const Point &right) const {
    Point p(x, y);
    if (p < right) {
      return true;
    }
    if (x == right.x && y == right.y) {
      return true;
    }
    return false;
  }
};

void print_p(const Point &p) {
  cerr << p.x << ',' << p.y << ',' << p.idx << '\n';
}

void print_ps(const vector<Point> &ps) {
  for (size_t i = 0; i < ps.size(); i++) {
    cerr << i << ":";
    print_p(ps.at(i));
  }
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    int N;
    cin >> N;
    vector<Point> ps;
    for (int i = 0; i < N; i++) {
      int X, Y;
      cin >> X >> Y;
      Point p(X, Y);
      ps.push_back(p);
    }
    sort(ps.begin(), ps.end());
    // 2倍
    for (int i = 0; i < N; i++) {
      int x = ps.at(i).x;
      int y = ps.at(i).y;
      Point p(x, y);
      p.h += 2;
      ps.push_back(p);
    }
    int ans = 0;

    // 尺取り法。[l, r)は半開区間とする
    int r = 0;
    for (int l = 0; l < N * 2; l++) {
      long long x = ps.at(l).x;
      long long y = ps.at(l).y;
      // 条件を満たす最大のrを求める
      while (true) {
        int nr = r + 1;
        if (nr >= N * 2 + 1) {
          break;
        }
        // nrが条件を満たしているかチェック
        // 例：
        // int nsum = sum + (T[r] == 'x');
        // if (nsum > K) {
        //   break;
        // }
        if (l < r) {
          long long u = ps.at(r).x;
          long long v = ps.at(r).y;
          if (x * v - y * u <= 0) {
            break;
          }
        }
        r = nr;
        // 条件にrを含める
        // 例：
        // sum = nsum;
      }

      // この時点で[l, r)は条件を見たす最大の区間
      // 何かする。
      // r=0の場合があるので、r=0の場合は配列のr-1番目にアクセスしないように注意する。
      // 例：
      ans = max(ans, r - l);

      // lをインクリメントする前の処理
      if (l == r) {
        // このとき、[l, r)は空集合なので、条件からlを除外する処理は不要
        r++;  // 先にrをインクリメントする
      } else {
        // 条件からlを除外する
        // 例：
        // sum -= (T[l] == 'x');
      }
    }
    cout << ans << '\n';
  }
  
  return 0;
}
