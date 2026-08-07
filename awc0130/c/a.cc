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
  vector<int> A(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i);
  }
  vector<vector<mint>> dp(N + 1, vector<mint>(K, 0));
  dp.at(0).at(0) = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      // i+1を取らない
      dp.at(i + 1).at(j) += dp.at(i).at(j);
      // i+1を取る
      dp.at(i + 1).at((j + A.at(i + 1)) % K) += dp.at(i).at(j);
    }
  }
  mint ans = dp.at(N).at(0) - 1;
  cout << ans << '\n';
  return 0;
}
