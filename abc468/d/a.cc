#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int dp[10000][10000][2];

int main() {
  string S;
  cin >> S;
  int N = S.size();
  //vector<vector<vector<int>>>dp(N, vector<vector<int>>(N, vector<int>(2, 0)));
  for (int i = 0; i < N; i++) {
    // dp.at(i).at(i).at(0) = 1;
    dp[i][i][0]=1;
  }
  for (int i = 0; i < N - 1; i++) {
    if (S.at(i) == S.at(i + 1)) {
      //dp.at(i).at(i + 1).at(0) = 1;
      dp[i][i+1][0]=1;
    } else {
      // dp.at(i).at(i + 1).at(1) = 1;
      dp[i][i+1][1]=1;
    }
  }
  for (int k = 2; k <= N - 1; k++) {
    for (int i = 0; i <= N - 1 - k; i++) {
      int j = i + k;
      if (S.at(i) == S.at(j)) {
        // dp.at(i).at(j).at(0) += dp.at(i + 1).at(j - 1).at(0);
        // dp.at(i).at(j).at(1) += dp.at(i + 1).at(j - 1).at(1);
        dp[i][j][0]+=dp[i+1][j-1][0];
        dp[i][j][1]+=dp[i+1][j-1][1];
      } else {
        //dp.at(i).at(j).at(1) += dp.at(i + 1).at(j - 1).at(0);
        dp[i][j][1]+=dp[i+1][j-1][0];
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      for (int k = 0; k < 2; k++) {
        //ans += dp.at(i).at(j).at(k);
        ans += dp[i][j][k];
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
