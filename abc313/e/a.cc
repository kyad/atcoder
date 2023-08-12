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

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  for (int i = 0; i < N - 1; i++) {
    if (S[i] > '1' && S[i + 1] > '1') {
      cout << -1 << endl;
      return 0;
    }
  }
  int i = N - 1;
  mint ans = 0;
  while (i >= 1) {
    // Find q
    const int q = S[i] - '0';
    const int qi = i;
    i--;
    // Find p
    while (i >= 1 && S[i] == '1') {
      i--;
    }
    const int p = qi - i - 1;
    // Calc
    ans += ans * (q - 1);
    ans += p + q;
  }
  cout << ans << endl;
  return 0;
}
