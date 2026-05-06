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

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  long long mx = *max_element(S.begin(), S.end());
  bool selected = false;
  mint ans = 0;
  for (int i = 0; i < N; i++) {
    mint now = S.at(i);
    if (mx == S.at(i) && selected == false) {
      mint two = 2;
      now *= two.pow(K);
      selected = true;
    }
    ans += now;
  }
  cout << ans << '\n';
  return 0;
}
