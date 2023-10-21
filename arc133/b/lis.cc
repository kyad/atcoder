// https://www.youtube.com/watch?v=fb2WRUxMkxs&t=660s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/**
 * 最長増加部分列 (Longest Increasing Subsequence, LIS)
 * 計算量 O(NlogN)
 */
template<class T> pair<vector<int>, vector<T> > lis(const vector<T>& X) {
  const int INF = 1e9+1;
  int N = X.size();
  // dp[i]: 長さiの単調増加列の末尾の数字の最小値 (0<=i<=N)
  vector<T> dp(N + 1, INF);
  dp[0] = -INF;
  // len[i]: iまで見た時の最大の単調増加列の長さ (0<=i<N)
  vector<int> len(N, 0);
  // value[i]: iまで見た時の最大の単調増加列の末尾の数字の最小値 (0<=i<N)
  vector<T> value(N, 0);
  for (int i = 0; i < N; i++) {
    vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), X.at(i));
    size_t pos = it - dp.begin();
    if (i == 0) {
      len.at(0) = (int)pos;
    } else {
      len.at(i) = max((int)pos, len.at(i - 1));
    }
    *it = X.at(i);
    value.at(i) = dp.at(len.at(i));
  }
  return make_pair(len, value);
}

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
  }
  vector<int> Q(N);
  for (int n = 0; n < N; n++) {
    cin >> Q.at(n);
  }
  vector<int> invQ(N + 1, -1);
  for (int j = 0; j < N; j++) {
    invQ[Q[j]] = j;
  }
  // QjがPiの倍数である時(i, -j)を入れる
  vector<pair<int, int> > a;
  for (int i = 0; i < N; i++) {
    for (int q = P[i]; q <= N; q += P[i]) {
      int j = invQ[q];
      a.push_back(make_pair(i, -j));
    }
  }
  sort(a.begin(), a.end());
  vector<int> v;
  for (auto [i, jj]: a) {
    int j = -jj;
    v.push_back(j);
  }
  auto [len, value] = lis(v);
  int ans = *max_element(len.begin(), len.end());
  cout << ans << endl;
  return 0;
}
