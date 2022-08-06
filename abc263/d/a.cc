#include <iostream>
#include <vector>
using namespace std;

const long long INF = 4e18;

int main() {
  int N;
  long long L, R;
  cin >> N >> L >> R;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  // f(k): 左からk個まで、Lの置き換え操作した時の最小値
  // g(k): 右からk個まで、Rの置き換え操作した時の最小値
  vector<long long> f(N + 1, 0), g(N + 1, 0);
  f[0] = 0;
  for (int n = 1; n <= N; n++) {
    f[n] = min(f[n - 1] + A[n - 1], L * n);
  }
  g[0] = 0;
  for (int n = 1; n <= N; n++) {
    g[n] = min(g[n - 1] + A[N - n], R * n);
  }
  long long ans = INF;
  for (int k = 0; k <= N; k++) {
    ans = min(ans, f[k] + g[N - k]);
  }
  cout << ans << endl;
  return 0;
}
