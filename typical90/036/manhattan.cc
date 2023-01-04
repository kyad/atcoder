#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> X(N), Y(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n) >> Y.at(n);
  }
  // 45度回転
  vector<long long> s(N), t(N);
  for (int n = 0; n < N; n++) {
    s[n] = X[n] - Y[n];
    t[n] = X[n] + Y[n];
  }
  const long long INF = 4e18;
  long long smax = -INF;
  long long smin = INF;
  long long tmax = -INF;
  long long tmin = INF;
  for (int n = 0; n < N; n++) {
    smax = max(smax, s[n]);
    smin = min(smin, s[n]);
    tmax = max(tmax, t[n]);
    tmin = min(tmin, t[n]);
  }
  for (int q = 0; q < Q; q++) {
    int i;
    cin >> i;
    i--;
    long long ans = -INF;
    ans = max(ans, s[i] - smin);
    ans = max(ans, smax - s[i]);
    ans = max(ans, t[i] - tmin);
    ans = max(ans, tmax - t[i]);
    cout << ans << endl;
  }
  return 0;
}
