#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// 有理数 p / q
struct Rational {
  long long p;
  long long q;
  Rational(long long _p, long long _q): p(_p), q(_q) {};
  bool operator<(const Rational& right) const {
    __int128 L = (__int128)p * right.q;
    __int128 R = (__int128)q * right.p;
    return L < R;
  }
  bool operator>(const Rational& right) const {
    return right < *this;
  }
  double val() const {
    if (p == 0) {
      return 0;
    } else {
      assert(q != 0);
      return (double)p / q;
    }
  }
};
const Rational INF(4e18+5, 1);
const Rational ZERO(0, 0);
ostream& operator<<(ostream& os, const Rational &x) { os << x.p << '/' << x.q;
  os << setprecision(2) << "=(" << x.val() << ')';
  return os; }


int main() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      long long h;
      cin >> x >> h;
      x--;
      H.at(x) = h;
    } else {
      int a, b;
      cin >> a >> b;
      a--; b--;
      auto f = [&](int p) -> Rational {
        // 左
        int m = -1;
        if (p >= 1) {
          m = p - 1;
          for (int l = p - 2; l >= 0; l--) {
            if (H.at(l) * (p - m) > H.at(m) * (p - l)) {
              m = l;
            }
          }
        }
        // 右
        int n = -1;
        if (p <= N - 2) {
          n = p + 1;
          for (int r = p + 2; r < N; r++) {
            if (H.at(r) * (n - p) > H.at(n) * (r - p)) {
              n = r;
            }
          }
        }
        if (m == -1 && n == -1) {
          Rational ans(1, 1);
          return ans;
        } else if (m == -1) {
          Rational ans(n - p, H.at(n) + n - p);
          return ans;
        } else if (n == -1) {
          Rational ans(p - m, H.at(m) + p - m);
          return ans;
        } else {
          Rational ans((p - m) * (n - p), H.at(m) * (n - p) + H.at(n) * (p - m) + (p - m) * (n - p));
          return ans;
        }
      };
      int ans = a;
      Rational mx = f(a);
      for (int p = a + 1; p <= b; p++) {
        Rational now = f(p);
        if (now > mx) {
          ans = p;
          mx = now;
        }
      }
      cout << (ans + 1) << '\n';
    }
  }
  return 0;
}
