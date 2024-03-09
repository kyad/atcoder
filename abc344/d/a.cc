#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }
const int INF = 1e9;

int main() {
  string T;
  cin >> T;
  int M = T.size();
  T.insert(T.begin(), '0');  // 冒頭に0を挿入する

  int N;
  cin >> N;
  vector<vector<string> > S(N + 1);
  vector<int> A(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i);
    for (int a = 0; a < A.at(i); a++) {
      string s;
      cin >> s;
      S.at(i).push_back(s);
    }
  }

  vector<vector<int> > dp(N + 1, vector<int>(M + 1, INF));
  dp[0][0] = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      chmin(dp[i][j], dp[i - 1][j]);  // iを取らない
      for (int a = 0; a < A[i]; a++) {  // Siaを取る
        int s = S[i][a].size();
        if (j - s < 0) {
          continue;
        }
        bool ok = true;
        for (int k = 0; k < s; k++) {
          if (S[i][a][k] != T[j - s + 1 + k]) {
            ok = false;
            break;
          }
        }
        if (!ok) {
          continue;
        }
        chmin(dp[i][j], dp[i - 1][j - s] + 1);
      }
    }
  }
  int ans = dp[N][M];
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
