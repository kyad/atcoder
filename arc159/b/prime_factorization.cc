#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

/**
 * 素因数分解
 * 計算量 O(sqrt(n))
 *
 * @param[in] n 素因数分解する数。
 *              制約 n >= 1
 * @return vector<long long> 素因数分解した結果。小さい順に重複込みで返す。1は含まない。
 *               nが1の時は空を返す。
 *               nが素数の時はnのみ返す。
 */
vector<long long> prime_factorization(long long n) {
  assert(n >= 1);
  vector<long long> ans;
  for (long long m = 2; m * m <= n; m++) {
    while (n % m == 0) {
      n /= m;
      ans.push_back(m);
    }
  }
  if (n != 1) {
    ans.push_back(n);
  }
  return ans;
}

int main() {
  long long a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 1 << endl;
    return 0;
  }
  if (a > b) {
    swap(a, b);
  }
  assert(a < b);
  long long ans = 0;
  while (a >= 1 && b >= 1) {
    long long g = __gcd(a, b);
    if (g >= 2) {
      a -= g;
      b -= g;
      a /= g;
      b /= g;
      ans++;
    } else {  // 互いに素
      long long t = b - a;
      long long d = a;
      vector<long long> primes = prime_factorization(t);
      for (long long p : primes) {
        if (p > a) {
          continue;
        }
        long long x = a % p;
        d = min(d, x);
      }
      a -= d;
      b -= d;
      ans += d;
    }
  }
  cout << ans << endl;
  return 0;
}
