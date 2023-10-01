#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int N, K, P;
  cin >> N >> K >> P;
  vector<long long> C(N + 1, 0);
  vector<vector<long long> > A(N + 1, vector<long long>(K, 0));
  for (int n = 1; n <= N; n++) {
    cin >> C.at(n);
    for (int k = 0; k < K; k++) {
      cin >> A.at(n).at(k);
    }
  }

  auto encode = [&](vector<int> X) {
    assert((int)X.size() == K);
    int ans = 0;
    for (int k = 0; k < K; k++) {
      ans *= (P + 1);
      assert(0 <= X[k] && X[k] <= P);
      ans += X[k];
    }
    return ans;
  };
  auto decode = [&](int z) -> vector<int>{
    vector<int> x(K);
    for (int k = 0; k < K; k++) {
      x[K - 1 - k] = z % (P + 1);
      z /= (P + 1);
    }
    return x;
  };
  int M = 1;
  for (int k = 0; k < K; k++) M *= (P + 1);

  // dp[i][j]: iまで見た時に状態がjになる場合のコストの総和の最小値
  // 0<=i<=N, 0<=j<M, M=(P+1)^K
  const long long INF = 4e18;
  vector<vector<long long> > dp(N + 1, vector<long long>(M, INF));
  dp[0][0] = 0;
  // 配るDP
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      // i+1を取らない
      chmin(dp[i + 1][j], dp[i][j]);
      // i+1を取る
      vector<int> x = decode(j);
      for (int k = 0; k < K; k++) {
        x[k] += A[i + 1][k];
        chmin(x[k], P);
      }
      int nj = encode(x);
      assert(nj < M);
      chmin(dp[i + 1][nj], dp[i][j] + C[i + 1]);
    }
  }
  long long ans = dp[N][M - 1];
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}
