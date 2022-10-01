#include <iostream>
#include <vector>
using namespace std;

int main() {
  const long long INF = 4e18;
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(M + 1, 0), B(M + 1, 0);
  vector<long long> C(M + 1, 0);
  for (int m = 1; m <= M; m++) {
    cin >> A.at(m) >> B.at(m) >> C.at(m);
  }
  vector<int> E(K + 1, 0);
  for (int k = 1; k <= K; k++) {
    cin >> E.at(k);
  }
  // E[i]まで見た時にjに行くまでの最小値 (1-indexed)
  vector<long long> dp(N + 1, INF);
  dp[1] = 0;
  for (int i = 1; i <= K; i++) {
    int m = E.at(i);
    // mを取る
    dp[B[m]] = min(dp[B[m]], dp[A[m]] + C[m]);
  }
  long long ans = (dp[N] == INF ? -1 : dp[N]);
  cout << ans << endl;
  return 0;
}
