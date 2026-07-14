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
  int N, K;
  cin >> N >> K;
  int M = 10000;
  vector<int> P(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> P.at(i);
  }
  vector<vector<mint>> dp(N + 1, vector<mint>(M + 1, 0));
  dp.at(0).at(0) = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      dp.at(i).at(j) += dp.at(i - 1).at(j);
      if (j - P.at(i) >= 0) {
        dp.at(i).at(j) += dp.at(i - 1).at(j - P.at(i));
      }
    }
  }
  mint ans = dp.at(N).at(K);
  cout << ans << '\n';
  return 0;
}
