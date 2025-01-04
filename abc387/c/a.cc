#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// xをbase進数で見た時の桁数を返す
int digits(long long x, int base) { int d = 0; while (x > 0) { x /= base; d++; } return d; }

// m^n, O(log n)
long long power(long long m, long long n, long long mod=1e18) {
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

long long naive(long long N) {
  long long ans = 0;
  for (int n = 10; n <= N; n++) {
    int d = digits(n, 10);
    vector<int> a(d);  // a[i]の上からiケタ目
    int nn = n;
    for (int i = 0; i < d; i++) {
      a.at(d - 1 - i) = nn % 10;
      nn /= 10;
    }
    bool ok = true;
    for (int i = 1; i <= d - 1; i++) {
      if (a[i] >= a[0]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans++;
    }
  }
  return ans;
}

int main() {
  long long L, R;
  cin >> L >> R;

  // d桁のヘビ数を返す
  auto g = [&](int d) {
    long long ans = 0;
    for (int i = 1; i <= 9; i++) {  // 上から1桁目
      ans += power(i, d - 1);
    }
    return ans;
  };

  // n以下のヘビ数を返す
  auto f = [&](long long n) -> long long {
    if (n < 10) {
      return 0;
    }
    int d = digits(n, 10);
    vector<int> a(d);  // a[i]の上からiケタ目
    for (int i = 0; i < d; i++) {
      a.at(d - 1 - i) = n % 10;
      n /= 10;
    }
    long long ans = 0;
    for (int i = 0; i < d; i++) {
      // 上からi-1桁目までaで確定しているとして、
      // i桁目がa[i]-1以下の組み合わせを数える
      long long now = 0;
      if (i == 0) {  // 1桁目は特別扱い
        for (int j = 1; j <= a[0] - 1; j++) {
          now += power(j, d - 1);
        }
        ans += now;
      } else {
        now = min(a[i], a[0]);
        now *= power(a[0], d - 1 - i);
        ans += now;
        if (a[i] >= a[0]) {  // 6472の7のパターン
          break;
        }
      }
    }
    // 最後、N自身の処理
    long long now = 1;
    for (int i = 1; i < d; i++) {
      if (a[i] >= a[0]) {
        now = 0;
      }
    }
    ans += now;

    // d桁以下の処理
    for (int i = 2; i <= d - 1; i++) {
      long long now = g(i);
      ans += now;
    }
    return ans;
  };

#if 1
  long long ans = f(R);
  ans -= f(L - 1);
#else  
  long long ans = naive(R);
  ans -= naive(L - 1);
#endif  
  cout << ans << endl;
  return 0;
}
