#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

long long dist2(long long x0, long long y0, long long x1, long long y1) {
  long long ans = (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
  return ans;
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<bool> light(N, false);
  for (int k = 0; k < K; k++) {
    int A;
    cin >> A;
    A--;
    light[A] = true;
  }
  vector<long long> X(N), Y(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n) >> Y.at(n);
  }
  long long mx = -1;
  for (int i = 0; i < N; i++) {
    if (light[i]) {
      continue;
    }
    long long mn = 1e18;
    for (int j = 0; j < N; j++) {
      if (!light[j]) {
        continue;
      }
      long long now = dist2(X[i], Y[i], X[j], Y[j]);
      mn = min(mn, now);
    }
    mx = max(mx, mn);
  }
  double ans = sqrt(mx);
  cout << std::setprecision(15) << ans << endl;
  return 0;
}
