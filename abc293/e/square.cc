#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint;

// modint
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

int main() {
  int A, M;
  long long X;
  cin >> A >> X >> M;
  mint::set_mod(M);
  mint a(A);
  auto f = [&](auto f, long long X) -> mint {
    if (X == 1) {
      return 1;
    }
    mint ans = (a.pow(X / 2) + 1) * f(f, X / 2);;
    if (X % 2) {
      ans = ans * a + 1;
    }
    return ans;
  };
  mint ans = f(f, X);
  cout << ans << endl;
  return 0;
}
