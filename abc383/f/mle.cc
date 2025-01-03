#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

const long long INF = 4e18;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

int main() {
  int N, X, K;
  cin >> N >> X >> K;
  vector<tuple<int, int, int> > items(N + 1);  // 色C, 価格P, 効用U
  items.at(0) = make_tuple(-1, 0, 0);
  for (int i = 1; i <= N; i++) {
    int P, U, C;
    cin >> P >> U >> C;
    items.at(i) = make_tuple(C, P, U);
  }
  sort(items.begin(), items.end());

  // dp[i][j][k]: iまで見た時に合計金額がjの時の満足度の最大値
  // k=0は今と違う色で買った状態が入る。k=1は今と同じ色で買った状態が入る。
  vector<vector<vector<long long> > > dp(N + 1, vector<vector<long long> > (X + 1, vector<long long>(2, -INF)));
  dp[0][0][0] = 0;
  int prevc = -1;
  for (int i = 1; i <= N; i++) {
    auto [C, P, U] = items.at(i);
    if (prevc != C) {   // 色が切り替わる時
      for (int j = 0; j <= X; j++) chmax(dp[i - 1][j][0], dp[i - 1][j][1]);  // 作業中を確定にchmax
      for (int j = 0; j <= X; j++) dp[i - 1][j][1] = dp[i - 1][j][0];  // 確定を作業中にコピー
    }
    prevc = C;
    for (int j = 0; j <= X; j++) {
      chmax(dp[i][j][1], dp[i - 1][j][1]);  // 買わない
      chmax(dp[i][j][0], dp[i - 1][j][0]);  // 買わない
      if (j - P >= 0) {
        chmax(dp[i][j][1], dp[i - 1][j - P][0] + U + K);  // 違う色から買う
        chmax(dp[i][j][1], dp[i - 1][j - P][1] + U    );  // 同じ色から買う
      }
    }
  }
  long long ans = -INF;
  for (int j = 0; j <= X; j++) {
    for (int k = 0; k < 2; k++) {
      chmax(ans, dp[N][j][k]);
    }
  }
  cout << ans << endl;
  return 0;
}
