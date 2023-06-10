#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
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

// m^n, O(log n)
long long power(long long m, long long n, int mod = 998244353) {
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


/**
 * Nの非自明な約数を返す。
 * 非自明な約数とは、1とNは含まないものとする。
 * 計算量：O(N)
 * 答のサイズ：O(N)
 * \param N Input.
 * \return Answer.
 */
vector<int> divisors(int N, bool include1 = false) {
  vector<int> ans;
  if (include1) {
    ans.push_back(1);
  }
  for (int n = 2; n < N; n++) {
    if (N % n == 0) {
      ans.push_back(n);
    }
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  
  auto solve = [&](int M) -> mint {
    vector<bool> a(M, true);
    for (int n = 0; n < N; n++) {
      if (S[n] == '.') {
        a[n % M] = false;
      }
    }
    int c1 = count(a.begin(), a.end(), true);
    print(c1);
    mint ans = power(2, c1);
    return ans;
  };

  mint ans = 0;
  vector<mint> B(N + 1);
  for (int M : divisors(N, true)) {
    hr;print(M);
    mint A = solve(M);
    print(A);
    for (int d : divisors(M, true)) {
      A -= B[d];
    }
    B[M] = A;
    print(M,B[M]);
    ans += B[M];
  }
  cout << ans.val() << endl;
  return 0;
}
