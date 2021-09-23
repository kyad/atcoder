// https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_d

#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MOD = 10007;
  int N;
  cin >> N;
  string str;
  cin >> str;
  vector<int> num(N);
  for (int n = 0; n < N; n++) {
    if (str[n] == 'J') {
      num[n] = 0;
    } else if (str[n] == 'O') {
      num[n] = 1;
    } else {
      num[n] = 2;
    }
  }
  vector<vector<int> > dp(1<<3, vector<int>(N));
  for (int next = 0; next < 1<<3; next++) {
    if ((next >> 0 & 1) == 0) {
      dp[next][0] = 0;
      continue;
    }
    if ((next >> num[0] & 1) == 0) {
      dp[next][0] = 0;
      continue;
    }
    dp[next][0] = 1;
  }
  for (int n = 1; n < N; n++) {
    for (int prev = 0; prev < 1<<3; prev++) {
      vector<int> add(1<<3, 0);
      for (int key = 0; key < 3; key++) {
        if ((prev >> key & 1) == 0) {
          continue;
        }
        for (int next = 0; next < 1<<3; next++) {
          if ((next >> key & 1) == 0) {
            continue;
          }
          if ((next >> num[n] & 1) == 0) {
            continue;
          }
          add[next] = 1;
        }
      }
      for (int next = 0; next < 1<<3; next++) {
        dp[next][n] += dp[prev][n - 1] * add[next];
        dp[next][n] %= MOD;
      }
    }
  }
  int ans = 0;
  for (int bit = 0; bit < 1<<3; bit++) {
    ans += dp[bit][N - 1];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
