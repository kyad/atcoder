#include <iostream>
#include <vector>
using namespace std;

// m^n, O(log n)
int power(int m, int n, int mod) {
  long long a = m;
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
  int N, D;
  cin >> N >> D;
  long long ans = 0;
  const int MOD= 998244353;
  // 片方が0
  for (int n = 1; n <= N; n++) {
    if (N - n < D) {
      break;
    }
    long long temp = power(2, D + n - 1, MOD);
    ans += temp;
    ans %= MOD;
  }
  // 片方が0以上
  for (int n = 1; n <= N; n++) {
    int num = D / 2 - max(1, D - N + n) + 1;
    if (num <= 0) {
      break;
    }
    num *= 2;
    if (D % 2 == 0) {
      num--;
    }
    long long temp = power(2, D + n - 3, MOD);
    temp *= num;
    temp %= MOD;
    ans += temp;
    ans %= MOD;
  }
  ans *= 2;
  ans %= MOD;
  cout << ans << endl;
  return 0;
}
