#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

int main() {
  int N;
  cin >> N;
  vector<int> W(N + 1, 0);
  vector<long long> H(N + 1, 0), B(N + 1, 0);
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    cin >> W.at(i) >> H.at(i) >> B.at(i);
    sum += W.at(i);
  }
  int M = *max_element(W.begin(), W.end()) * N;
  // dp[i][j]: iまで見た時で頭の重さがjの時の嬉しさの最大値
  vector<vector<long long> > dp(N + 1, vector<long long>(M + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      // iを頭に付ける
      if (j - W.at(i) >= 0) {
        chmax(dp[i][j], dp[i - 1][j - W.at(i)] + H.at(i));
      }
      // iを体に付ける
      chmax(dp[i][j], dp[i - 1][j] + B.at(i));
    }
  }
  long long ans = -1;
  for (int j = 0; j <= M; j++) {
    int head = j;
    int body = sum - head;
    if (head > body) {
      continue;
    }
    chmax(ans, dp[N][j]);
  }
  cout << ans << endl;
  return 0;
}
