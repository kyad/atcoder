// https://atcoder.jp/contests/abc301/tasks/abc301_f
// https://www.youtube.com/watch?v=idmCu5t3ewg

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

mint perm(int n, int r) {
  mint ans = 1;
  for (int i = 0; i < r; i++) {
    ans *= n - i;
  }
  return ans;
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

const int MAX = 510000;  // n (<= 10^7)
const int MOD = 998244353;  // p (prime, > n)

long long fac[MAX];  // a! mod p
long long finv[MAX];  // (a!)^{-1} mod p
long long inv[MAX];  // a^{-1} mod p

// O(n)
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// nCk mod p, O(1)
long long COM(int n, int k) {
  if (n < k) {
    return 0;
  }
  if (n < 0 || k < 0) {
    return 0;
  }
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  COMinit();
  string S;
  cin >> S;
  int N = S.size();
  vector<mint> L(N), R(N);
  {
    // L[i]: iまで見た時にi-1までがDD型でない?の置き方
    int X = 0;  // 大文字の個数
    int Y = 0;  // ?の数
    vector<bool> used(26);
    for (int i = 0; i < N; i++) {
      for (int y = 0; y <= min(26, Y); y++) {  // y: ?の中で大文字の数
        mint now = COM(Y, y);
        now *= power(26, Y - y);
        now *= perm(26 - X, y);
        L[i] += now;
      }
      // 遷移
      if (isupper(S[i])) {
        if (used[S[i] - 'A']) {
          break;
        }
        used[S[i] - 'A'] = true;
        X++;
      }
      if (S[i] == '?') {
        Y++;
      }
    }
  }
  mint ans = 0;
  {
    // R[i]: iを見る時のi+1以降のAAAAAaaa型の個数
    mint X = 1;  // i+1までの小文字の置き方
    mint Y = 0;  // i+1までの大文字の置き方
    for (int i = N - 1; i >= 0; i--) {
      R[i] = Y;
      if (S[i] == '?') {
        mint nx = 26 * X;
        mint ny = 26 * (X + Y);
        X = nx;
        Y = ny;
      } else if (isupper(S[i])) {
        Y += X;
        X = 0;
      } else {  // 小文字
        Y = 0;
      }
    }
    ans += X + Y;  // DDが無い場合
  }
  for (int i = 0; i < N; i++) {
    int c = 0;
    if (S[i] == '?') {
      c = 26;
    } else if (islower(S[i])) {
      c = 1;
    }
    mint now = L[i] * R[i] * c;
    ans += now;
  }
  cout << ans.val() << endl;
  return 0;
}
