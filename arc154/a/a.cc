#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int MOD = 998244353;
  int N;
  cin >> N;
  string A, B;
  cin >> A;
  cin >> B;
  for (int n = 0; n < N; n++) {
    if (A.at(n) > B.at(n)) {
      swap(A.at(n), B.at(n));
    }
  }
  auto f = [&](string &A) -> long long {
    long long p = (A[0] - '0');
    for (int n = 1; n < N; n++) {
      p *= 10;
      p += (A[n] - '0');
      p %= MOD;
    }
    return p;
  };
  long long p = f(A);
  long long q = f(B);
  long long ans = (p * q) % MOD;
  cout << ans << endl;
  return 0;
}
