#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, const T b) { a = max(a, b); }

int main() {
  int N;
  cin >> N;
  vector<vector<long long> > D(N, vector<long long>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int d;
      cin >> d;
      D.at(i).at(j) = d;
      D.at(j).at(i) = d;
    }
  }
  int N2 = 1<<N;
  vector<vector<long long> > dp(N + 1, vector<long long>(N2, 0));
  for (int i = 1; i <= N; i++) {
    for (int s = 0; s < N2; s++) {
      for (int u = 0; u < N; u++) {
        if (s>>u&1) {
          continue;
        }
        for (int v = 0; v < N; v++) {
          if (u == v) {
            continue;
          }
          if (s>>v&1) {
            continue;
          }
          // 取らない
          chmax(dp[i][s], dp[i - 1][s]);
          // 取る
          int ns = s | (1<<u) | (1<<v);
          chmax(dp[i][ns], dp[i - 1][s] + D.at(u).at(v));
        }
      }
    }
  }
  long long ans = 0;
  for (int s = 0; s < N2; s++) {
    chmax(ans, dp[N][s]);
  }
  cout << ans << endl;
  return 0;
}
