#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  map<int, vector<pair<int, int> > > mp;  // R->[(X, qi), ...];
  for (int qi = 0; qi < Q; qi++) {
    int R, X;
    cin >> R >> X;
    R--;
    mp[R].push_back(make_pair(X, qi));
  }
  vector<int> ans(Q, -1);

  // LISのDP
  const int INF = 1e9+1;
  // dp[i]: 長さiの単調増加列の末尾の数字の最小値 (0<=i<=N)
  vector<int> dp(N + 1, INF);
  dp[0] = -INF;
  for (int i = 0; i < N; i++) {
    // dpを埋める
    vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), A.at(i));
    *it = A.at(i);
    // Rがあればクエリ処理する
    if (mp.contains(i)) {
      for (auto [X, qi] : mp[i]) {
        ans.at(qi) = upper_bound(dp.begin(), dp.end(), X) - dp.begin() - 1;
      }
    }
  }
  for (int qi = 0; qi < Q; qi++) {
    cout << ans.at(qi) << '\n';
  }
  return 0;
}
