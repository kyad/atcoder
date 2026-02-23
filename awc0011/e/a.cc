#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N + 1, 0);
  vector<long long> B(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  const long long INF = 4e18;
  // 最適値を計算するDP
  vector<vector<long long> > dp(N + 1, vector<long long>(M + 1, -INF));
  dp.at(0).at(0) = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      // 取らない
      chmax(dp.at(i).at(j), dp.at(i - 1).at(j));
      // 取る
      if (j - A.at(i) >= 0) {
        chmax(dp.at(i).at(j), dp.at(i - 1).at(j - A.at(i)) + B.at(i));
      }
    }
  }
  // 逆向きに辿るDP
  vector<bool> ans(N, false);
  vector<bool> reach(M + 1, false);  // 最適値を通る
  long long mx = *max_element(dp.at(N).begin(), dp.at(N).end());
  for (int j = 0; j <= M; j++) {
    if (mx == dp.at(N).at(j)) {
      reach.at(j) = true;
    }
  }
  for (int i = N; i >= 1; i--) {
    // i-1->iの遷移で、iを使うかどうかを確認する
    vector<bool> next_reach(M + 1, false);  // i-1のreach
    for (int j = 0; j <= M; j++) {
      // iで取らないを選んで最適
      if (reach.at(j) == true && dp.at(i).at(j) >= 0 && dp.at(i - 1).at(j) >= 0 && dp.at(i).at(j) == dp.at(i - 1).at(j)) {
        next_reach.at(j) = true;
      }
      // iで取るを選んで最適
      if (j - A.at(i) >= 0 && reach.at(j) == true && dp.at(i).at(j) >= 0 && dp.at(i - 1).at(j - A.at(i)) >= 0
          && dp.at(i).at(j) == dp.at(i - 1).at(j - A.at(i)) + B.at(i)) {
        ans.at(i - 1) = true;
        next_reach.at(j - A.at(i)) = true;
      }
    }
    reach = next_reach;
  }
  for (int i = 0; i < N; i++) {
    cout << (ans.at(i) ? "Yes" : "No") << '\n';
  }
  return 0;
}
