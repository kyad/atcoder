#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    int N, M, K;
    cin >> N >> M >> K;
    string S;
    cin >> S;
    vector<vector<int> > graph(N);
    for (int m = 0; m < M; m++) {
      int U, V;
      cin >> U >> V;
      U--; V--;
      graph.at(U).push_back(V);
    }
    // dp[k][u]: 今k回目を動かしているときでuにいるときに自分が勝ちならtrue
    vector<vector<bool> > dp(K * 2 + 1, vector<bool>(N, false));
    // 初期値
    for (int u = 0; u < N; u++) {
      if (S.at(u) == 'A') {
        dp.at(K * 2).at(u) = true;
      }
    }
    // dpの遷移
    for (int k = K * 2 - 1; k >= 0; k--) {
      for (int u = 0; u < N; u++) {
        dp.at(k).at(u) = false;
        for (int v : graph.at(u)) {
          if (dp.at(k + 1).at(v) == false) {
            dp.at(k).at(u) = true;
            break;
          }
        }
      }
    }
    string ans;
    if (dp.at(0).at(0) == true) {
      ans = "Alice";
    } else {
      ans = "Bob";
    }
    cout << ans << endl;
  }
  return 0;
}
