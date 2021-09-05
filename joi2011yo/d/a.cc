// https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_d

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> x(N);
  for (int n = 0; n < N; n++) {
    cin >> x.at(n);
  }
  vector<vector<long long> > dp(21, vector<long long>(N - 1, 0L));
  dp[x[0]][0] = 1;
  for (int n = 0; n < N - 2; n++) {
    for (int i = 0; i <= 20; i++) {
      const int mul[2] = {-1, 1};
      for (int k = 0; k < 2; k++) {
        int ni = i + mul[k] * x[n + 1];
        if (ni < 0 || ni > 20) {
          continue;
        }
        dp[ni][n + 1] += dp[i][n];
      }
    }
  }
  cout << dp[x[N - 1]][N - 2] << endl;
  return 0;
}
