// https://atcoder.jp/contests/abc227/tasks/abc227_e

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  string S;
  int K;
  cin >> S >> K;
  int N = (int)S.size();
  int M = N * (N - 1) / 2;
  map<char, vector<int> > pos;
  for (int n = 0; n < N; n++) {
    pos[S[n]].push_back(n);
  }
  // 先頭からK, E, Yをそれぞれi, j, k個使って、Sの最初のi+j+k文字までからの転倒数がtの文字列の個数がdp[i][j][k][t]
  vector<vector<vector<vector<long long> > > > dp(pos['K'].size() + 1, vector<vector<vector<long long> > >(pos['E'].size() + 1, vector<vector<long long> >(pos['Y'].size() + 1, vector<long long>(M + 1, 0))));
  dp[0][0][0][0] = 1;
  for (int i = 0; i <= pos['K'].size(); i++) {
    for (int j = 0; j <= pos['E'].size(); j++) {
      for (int k = 0; k <= pos['Y'].size(); k++) {
        // use K
        if (i < pos['K'].size()) {
          int t_add = 0;
          for (int e_idx = 0; e_idx < j; e_idx++) {
            if (pos['E'][e_idx] > pos['K'][i]) {  // 今から置くKによって、いくつ転倒数が増えるかチェック
              t_add++;
            }
          }
          for (int y_idx = 0; y_idx < k; y_idx++) {
          if (pos['Y'][y_idx] > pos['K'][i]) {
            t_add++;
          }
          }
          for (int t = 0; t <= M - t_add; t++) {
            dp[i + 1][j][k][t + t_add] += dp[i][j][k][t];
          }
        }
        // use E
        if (j < pos['E'].size()) {
          int t_add = 0;
          for (int k_idx = 0; k_idx < i; k_idx++) {
            if (pos['K'][k_idx] > pos['E'][j]) {
              t_add++;
            }
          }
          for (int y_idx = 0; y_idx < k; y_idx++) {
            if (pos['Y'][y_idx] > pos['E'][j]) {
              t_add++;
            }
          }
          for (int t = 0; t <= M - t_add; t++) {
            dp[i][j + 1][k][t + t_add] += dp[i][j][k][t];
          }
        }
        // use Y
        if (k < pos['Y'].size()) {
          int t_add = 0;
          for (int k_idx = 0; k_idx < i; k_idx++) {
            if (pos['K'][k_idx] > pos['Y'][k]) {
              t_add++;
            }
          }
          for (int e_idx = 0; e_idx < j; e_idx++) {
            if (pos['E'][e_idx] > pos['Y'][k]) {
              t_add++;
            }
          }
          for (int t = 0; t <= M - t_add; t++) {
            dp[i][j][k + 1][t + t_add] += dp[i][j][k][t];
          }
        }
      }
    }
  }
  long long ans = 0;
  K = min(K, M);
  for (int t = 0; t <= K; t++) {
    ans += dp[pos['K'].size()][pos['E'].size()][pos['Y'].size()][t];
  }
  cout << ans << endl;
  return 0;
}
