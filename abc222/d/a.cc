#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> B(N);
  for (int n = 0; n < N; n++) {
    cin >> B.at(n);
  }
  const int MOD = 998244353;
  vector<vector<long long> > dp(3002, vector<long long>(N, 0));
  for (int n = 0; n < N; n++) {
    vector<long long> imos(3002, 0);
    if (n == 0) {
      imos.at(A.at(0))++;
      imos.at(B.at(0) + 1) += (MOD - 1);
    } else {
      for (int c = 0; c <= 3000; c++) {
        imos.at(max(c, A.at(n))) += dp[c][n - 1];
        imos.at(max(c, A.at(n))) %= MOD;
        imos.at(B.at(n) + 1) += (MOD - dp[c][n - 1]);
        imos.at(B.at(n) + 1) %= MOD;
      }
    }
    for (int i = 1; i <= 3001; i++) {
      imos.at(i) += imos.at(i - 1);
      imos.at(i) %= MOD;
    }
    for (int c = 0; c <= 3000; c++) {
      dp[c][n] = imos[c];
    }
  }
  long long ans = 0;
  for (int c = 0; c <= 3000; c++) {
    ans += dp[c][N - 1];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}

  
         
