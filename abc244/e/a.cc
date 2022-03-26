#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MOD = 998244353;
  int N, M, K, S, T, X;
  cin >> N >> M >> K >> S >> T >> X;
  S--;
  T--;
  X--;
  vector<int> U(M), V(M);
  for (int m = 0; m < M; m++) {
    cin >> U.at(m) >> V.at(m);
    U.at(m)--;
    V.at(m)--;
  }
  vector<vector<vector<long long> > > dp(K + 1, vector<vector<long long> >(N, vector<long long>(2, 0)));
  dp[0][S][0] = 1;
  for (int k = 1; k <= K; k++) {
    for (int m = 0; m < M; m++) {
      for (int x = 0; x < 2; x++) {
        {
          // U -> V;
          int nx;
          if (V[m] == X) {
            nx = 1 - x;
          } else {
            nx = x;
          }
          dp[k][V[m]][nx] += dp[k - 1][U[m]][x];
          dp[k][V[m]][nx] %= MOD;
        }
        {
          // V -> U;
          int nx;
          if (U[m] == X) {
            nx = 1 - x;
          } else {
            nx = x;
          }
          dp[k][U[m]][nx] += dp[k - 1][V[m]][x];
          dp[k][U[m]][nx] %= MOD;
        }
      }
    }
  }
  cout << dp[K][T][0] << endl;
  return 0;
}
