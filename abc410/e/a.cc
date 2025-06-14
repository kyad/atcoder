#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

int main() {
  int N, H, M;
  cin >> N >> H >> M;
  vector<vector<int> > dp(N + 1, vector<int>(H + 1, -1));  // dp[i][j]: i回目で体力の残りがjの時の魔力の残りの最大値
  dp.at(0).at(H) = M;
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int A, B;
    cin >> A >> B;
    // 物理攻撃の時
    for (int j = H; j >= 0; j--) {
      if (dp.at(i - 1).at(j) < 0) {  // そのような状態に遷移しない
        continue;
      }
      int nj = j - A;
      if (nj < 0) {
        continue;
      }
      chmax(dp.at(i).at(nj), dp.at(i - 1).at(j));
    }
    // 魔法攻撃の時
    for (int j = H; j >= 0; j--) {
      if (dp.at(i - 1).at(j) < 0) {  // そのような状態に遷移しない
        continue;
      }
      if (dp.at(i - 1).at(j) < B) {  // 魔法を使えない
        continue;
      }
      chmax(dp.at(i).at(j), dp.at(i - 1).at(j) - B);
    }
    // 行動できないかの判定
    int mx = *max_element(dp.at(i).begin(), dp.at(i).end());
    if (mx < 0) {
      break;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
