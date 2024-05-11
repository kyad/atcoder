#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

// xをbase進数で見た時の桁数を返す
int digits(long long x, int base) { int d = 0; while (x > 0) { x /= base; d++; } return d; }
// m^n, O(log n)
long long power(long long m, long long n, int mod) {
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
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> D(N);
  for (int i = 0; i < N; i++) {
    D.at(i) = digits(A.at(i), 10);
  }
  vector<long long> B(N);
  for (int i = 0; i < N; i++) {
    B.at(i) = 1;
    for (int j = 0; j < D.at(i); j++) {
      B.at(i) *= 10LL;
    }
  }
  vector<mint> a(N), b(N);
  for (int i = 0; i < N; i++) {
    a.at(i) = A.at(i);
    b.at(i) = B.at(i);
  }
  // 計算
  vector<mint> s(N);
  s.at(0) = a.at(0);
  for (int i = 1; i < N; i++) {
    s.at(i) = s.at(i - 1) + a.at(i);
  }
  mint ans = 0;
  for (int i = 1; i < N; i++) {
    mint now = b.at(i) * s.at(i - 1) + a.at(i) * i;
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
