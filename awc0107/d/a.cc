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
using lll = __int128;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  long long left = 0;  // OK
  //long long right = 1e18 + 1e9 + 3LL; // NG
  long long right = 2e18;  // NG
  auto check = [&](long long X) {
    lll need = 0;
    for (int i = 0; i < N; i++) {
      long long now = max(0LL, X - A.at(i));
      need += now;
    }
    return (need <= (lll)K);
  };
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    if (check(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  // 全部をleft以上にする
  for (int i = 0; i < N; i++) {
    if (A.at(i) < left) {
      long long delta = left - A.at(i);
      A.at(i) += delta;
      K -= delta;
    }
  }
  // 残りのK個を配る
  assert(K < N);
  sort(A.begin(), A.end());
  for (int i = 0; i < K; i++) {
    A.at(i)++;
  }
  mint ans = 1;
  for (int i = 0; i < N; i++) {
    ans *= A.at(i);
  }
  cout << ans << '\n';
  return 0;
}
