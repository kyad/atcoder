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
  string S;
  cin >> S;
  int N = S.size();
  int M = 3;
  vector<vector<mint>> dp(N, vector<mint>(M, 0));
  int j = S.at(0) - 'a';
  dp.at(0).at(j) = 1;
  for (int i = 1; i < N; i++) {
    // 取らない
    for (int j = 0; j < M; j++) {
      dp.at(i).at(j) += dp.at(i - 1).at(j);
    }
    // 取る
    if (S.at(i) == 'a') {
      dp.at(i).at(0) += dp.at(i - 1).at(1) + dp.at(i - 1).at(2) + 1;
    } else if (S.at(i) == 'b') {
      dp.at(i).at(1) += dp.at(i - 1).at(2) + dp.at(i - 1).at(0) + 1;
    } else {
      dp.at(i).at(2) += dp.at(i - 1).at(0) + dp.at(i - 1).at(1) + 1;
    }
  }
  mint ans = 0;
  for (int j = 0; j < M; j++) {
    ans += dp.at(N - 1).at(j);
  }
  cout << ans << '\n';
  return 0;
}
