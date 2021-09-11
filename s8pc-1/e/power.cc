// https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_e
// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a

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
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  vector<int> c(Q + 2);
  c.at(0) = 0;
  c.at(Q + 1) = 0;
  for (int n = 0; n < N; n++) {
    cin >> a.at(n);
  }
  for (int q = 0; q < Q; q++) {
    cin >> c.at(q + 1);
    c.at(q + 1)--;
  }
  vector<int> imos(N, 0);
  for (int q = 0; q < Q + 1; q++) {
    imos.at(min(c.at(q), c.at(q + 1)))++;
    imos.at(max(c.at(q), c.at(q + 1)))--;
  }
  vector<int> sum(N, 0);
  sum.at(0) = imos.at(0);
  for (int n = 1; n < N; n++) {
    sum.at(n) = imos.at(n) + sum.at(n - 1);
  }
  const int MOD = 1000000007;
  long long ans = 0LL;
  for (int n = 0; n < N - 1; n++) {
    ans += (long long)power(a.at(n), a.at(n + 1), MOD) * sum.at(n);
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
