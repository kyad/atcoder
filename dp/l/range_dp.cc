// https://atcoder.jp/contests/dp/tasks/dp_l

#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1000000000LL * 3000 + 1;
vector<int> A;
vector<vector<long long> > dp;  // dp[l][r]: [l, r]から始める時のX-Yの最大値

long long rec(int l, int r) {
  if (dp[l][r] < INF) {
    return dp[l][r];
  }
  if (l == r) {
    return dp[l][r] = A[l];
  }
  return dp[l][r] = max(A[l] - rec(l + 1, r), A[r] - rec(l, r - 1));
}

int main() {
  int N;
  cin >> N;
  A.resize(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  dp.resize(N, vector<long long>(N, INF));
  cout << rec(0, N - 1) << endl;
  return 0;
}
