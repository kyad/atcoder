#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int N, W;
  cin >> N >> W;
  vector<pair<int, int> > K;  // 新しい(長さ(value), 容量(cost))
  for (int i = 0; i < N; i++) {
    int L, C;
    cin >> L >> C;
    int cnt = 1;
    while (C > 0) {
      if (cnt > C) {
        K.push_back(make_pair(L * C, C));  // Lをのこり分
        break;
      }
      K.push_back(make_pair(L * cnt, cnt));  // Lをcnt個分
      C -= cnt;
      cnt *= 2;
    }
  }
  int M = K.size();
  const long long INF = 4e18;
  vector<vector<long long> > dp(M + 1, vector<long long>(W + 1, INF));
  dp.at(0).at(0) = 0;
  K.insert(K.begin(), make_pair(0, 0));
  for (int i = 1; i <= M; i++) {
    for (int j = 0; j <= W; j++) {
      int value = K.at(i).first;
      int cost = K.at(i).second;
      chmin(dp.at(i).at(j), dp.at(i - 1).at(j));  // 取らない
      if (j - K.at(i).first >= 0) {
        chmin(dp.at(i).at(j), dp.at(i - 1).at(j - value) + cost);  // 取る
      }
    }
  }
  long long ans = dp.at(M).at(W);
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << '\n';
  return 0;
}

