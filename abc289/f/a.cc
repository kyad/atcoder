// https://atcoder.jp/contests/abc289/tasks/abc289_f

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  auto solve = [](int a, int b, int c, int s, int t, vector<int> &ax, vector<int> &ay) {
    if (a == b) {
      if (s == t) {
        // OK
      } else {
        // t == 2 * a - s  --> odd
        // NG
        return false;
      }
    } else {
      if (abs(t - s) % 2) {
        return false;
      } else if (s < t) {
        for (int i = 0; i < abs(t - s) / 2; i++) {
          ax.push_back(a);
          ay.push_back(c);
          ax.push_back(a + 1);
          ay.push_back(c);
        }
      } else {  // t < s
        for (int i = 0; i < abs(t - s) / 2; i++) {
          ax.push_back(a + 1);
          ay.push_back(c);
          ax.push_back(a);
          ay.push_back(c);
        }
      }
    }
    return true;
  };
  auto solve1 = [&](int odd) -> bool {
    vector<int> ax, ay;
    if (odd) {
      sx = 2 * a - sx;
      sy = 2 * c - sy;
      ax.push_back(a);
      ay.push_back(c);
    }
    // sx --> tx
    if (!solve(a, b, c, sx, tx, ax, ay)) {
      return false;
    }
    // sy --> ty
    if (!solve(c, d, a, sy, ty, ay, ax)) {
      return false;
    }
    cout << "Yes" << endl;
    for (size_t i = 0; i < ax.size(); i++) {
      cout << ax.at(i) << ' ' << ay.at(i) << '\n';
    }
    return true;
  };
  for (int odd = 0; odd < 2; odd++) {
    if (solve1(odd)) {
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
