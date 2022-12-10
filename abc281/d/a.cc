#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, const T b) { a = max(a, b); }

int main() {
  int N, K, D;
  cin >> N >> K >> D;
  vector<long long> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  vector<vector<vector<long long> > > dp(N + 1, vector<vector<long long> > (K + 1, vector<long long>(D, -1)));
  dp[0][0][0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= K; j++) {
      for (int k = 0; k < D; k++) {
        if (dp[i - 1][j][k] < 0) {
          continue;
        }
        // 取らない
        chmax(dp[i][j][k], dp[i - 1][j][k]);
        // 取る
        int nj = j + 1;
        int nk = (k + A[i]) % D;
        if (nj <= K) {
          chmax(dp[i][nj][nk], dp[i - 1][j][k] + A[i]);
        }
      }
    }
  }
  cout << dp[N][K][0] << endl;
  return 0;
}
