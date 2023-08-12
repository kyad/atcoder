// https://www.youtube.com/watch?v=VluAlzOH83I&t=3627s

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
  mint ans = 0;
  for (int i = N - 1; i >= 1; i--) {
    const int a = S[i] - '0';
    ans++;
    ans += ans * (a - 1);
  }
  cout << ans << endl;
  return 0;
}
