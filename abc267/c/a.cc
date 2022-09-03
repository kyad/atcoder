#include <iostream>
#include <vector>
using namespace std;

int main() {
  const long long INF = 4e18;
  int N, M;
  cin >> N >> M;
  vector<long long> A(N + 1), S(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  for (int n = 1; n <= N; n++) {
    S.at(n) = S.at(n - 1) + A.at(n);
  }
  vector<long long> T(N + 1, -INF);
  T[M] = 0;
  for (int n = 1; n <= M; n++) {
    T[M] += A[n] * n;
  }
  for (int n = M + 1; n <= N; n++) {
    long long D = S[n - 1] - S[n - M - 1];
    T[n] = T[n - 1] - D + A[n] * M;
  }
  long long ans = -INF;
  for (int n = M; n <= N; n++) {
    ans = max(ans, T[n]);
  }
  cout << ans << endl;
  return 0;
}
