#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

const long long E17 = 100000000000000000LL;  // 1e17
const long long E18 = 1000000000000000000LL;  // 1e18

// xをbase進数で見た時の桁数を返す
int digits(long long x, int base = 10) { int d = 0; while (x > 0) { x /= base; d++; } return d; }

// 1 + ... + x
mint S(long long x) {
  mint ans = x;
  ans *= (x + 1);
  ans /= 2;
  return ans;
}

// L=1, R=xの時の答を返す
mint f(long long x) {
  mint ans = 0;
  for (long long l = 1LL; l <= E17; l *= 10LL) {
    if (x < l) {
      break;
    }
    long long r = l * 10LL;
    mint now = digits(l);
    if (x >= r) {
      now *= (S(r - 1) - S(l - 1));
    } else {
      now *= (S(x) - S(l - 1));
    }
    ans += now;
  }
  if (x == E18) {
    ans += (mint)digits(E18) * E18;
  }
  return ans;
}

int main() {
  long long L, R;
  cin >> L >> R;
  mint ans = f(R) - f(L - 1);
  cout << ans.val() << endl;
  return 0;
}
