// https://atcoder.jp/contests/abc263/tasks/abc263_d

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, L, R;
  cin >> N >> L >> R;
  vector<int> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  vector<long long> S(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    S[n] = S[n - 1] + A[n];
  }
  vector<long long> M(N + 1);
  M[N] = S[N] - (long long)R * N;
  for (int x = N - 1; x >= 0; x--) {
    M[x] = min(M[x + 1], S[x] - (long long)R * x);
  }
  const long long INF = 4e18;
  long long ans = INF;
  for (int x = 0; x <= N; x++) {
    long long now = (long long)R * N + (long long)L * x - S[x] + M[x];
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
