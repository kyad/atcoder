#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// 有理数 p / q
struct Rational {
  int p;
  int q;
  Rational(int _p, int _q): p(_p), q(_q) {};
  bool operator<(const Rational& right) const {
    long long L = (long long)p * right.q;
    long long R = (long long)q * right.p;
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
const Rational INF(2e9+5, 1);
const Rational ZERO(0, 0);
ostream& operator<<(ostream& os, const Rational &x) { os << x.p << '/' << x.q;
  os << setprecision(2) << "=(" << x.val() << ')';
  return os; }

int main() {
  int N;
  cin >> N;
  vector<int> P(N), S(N);
  for (int i = 0; i < N; i++) {
    cin >> P.at(i) >> S.at(i);
  }
  
  Rational mx = Rational(S.at(0), P.at(0));
  int ans = 0;
  for (int i = 1; i < N; i++) {
    Rational A = Rational(S.at(i), P.at(i));
    if (A > mx) {
      mx = A;
      ans = i;
    }
  }
  cout << ans + 1 << '\n';
  return 0;
}
