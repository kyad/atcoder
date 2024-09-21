#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

const int INF = 1e9;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  // dp[i]: 長さiの単調増加列の末尾の数字の最小値 (0<=i<=N) (符号反転)
  vector<int> dp(N + 1, INF);
  dp[0] = -INF;
  vector<int> ans(N, 0);
  for (int i = N - 2; i >= 0; i--) {
    int x = -H.at(i + 1);  // 符号反転
    vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), x);
    size_t pos = it - dp.begin();
    ans.at(i) = pos;
    *it = x;
    // 枝刈り
    if (it != dp.end()) {
      int count = 0;
      for (vector<int>::iterator j = next(it); j != dp.end(); j++) {
        *j = INF;
        count++;
        if (count >= 20000) {
          break;
        }
      }
    }
  }
  dump(ans);
  return 0;
}
