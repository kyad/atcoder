#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int K;
  cin >> K;
  string S;
  cin >> S;
  S.insert(0, "_");
  string T;
  cin >> T;
  T.insert(0, "_");
  int N = S.size();
  int M = T.size();
  // dp[i][j]: Sのi文字目とTのj文字目までの編集距離
  vector<map<int, int> > dp(N + 1);
  dp[0][0] = 0;
  // 配るDP
  for (int i = 0; i < N; i++) {
    queue<int> js;
    for (auto it = dp[i].begin(); it != dp[i].end(); it++) {
      js.push(it->first);
    }
    while (!js.empty()) {
      int j = js.front();
      int cur = dp[i][j];
      js.pop();
      // Tを削除
      if (cur + 1 <= K && i + 1 <= N) {
        if (dp[i + 1].contains(j)) {
          chmin(dp[i + 1][j], cur + 1);
        } else {
          dp[i + 1][j] = cur + 1;
        }
      }
      // Sを削除
      if (cur + 1 <= K && j + 1 <= M) {
        if (dp[i].contains(j + 1)) {
          chmin(dp[i][j + 1], cur + 1);
        } else {
          dp[i][j + 1] = cur + 1;
          js.push(j + 1);
        }
      }
      // SとTを置換
      if (i + 1 <= N && j + 1 <= M) {
        if (S[i + 1] == T[j + 1]) {
          if (dp[i + 1].contains(j + 1)) {
            chmin(dp[i + 1][j + 1], cur);
          } else {
            dp[i + 1][j + 1] = cur;
          }
        } else if (cur + 1 <= K) {
          if (dp[i + 1].contains(j + 1)) {
            chmin(dp[i + 1][j + 1], cur + 1);
          } else {
            dp[i + 1][j + 1] = cur + 1;
          }
        }
      }
    }
  }
  if (dp[N].contains(M) && dp[N][M] <= K) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
