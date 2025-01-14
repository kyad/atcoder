#include <iostream>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

const int MOD = 998244353;

using lll = __int128;

// xをbase進数で見た時の桁数を返す
int digits(long long x, int base) { int d = 0; while (x > 0) { x /= base; d++; } return d; }

// m^n, O(log n)
long long power(long long m, lll n, int mod = MOD) {
  long long a = m % mod;
  long long ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return ans;
}

int main() {
  long long N;
  cin >> N;
  int d = digits(N, 10);
  // Nをx個つなげたものを返す
  auto f = [&](auto f, long long x) -> mint {
    if (x == 0) {
      return 0;
    }
    mint h = f(f, x / 2);
    mint ans = h * power(10, (lll)x / 2 * d) + h;
    if (x % 2 == 1) {
      ans *= power(10, d);
      ans += N;
    }
    return ans;
  };
  mint ans = f(f, N);
  cout << ans.val() << endl;
  return 0;
}
