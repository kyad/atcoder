// https://atcoder.jp/contests/s8pc-5/tasks/s8pc_5_b

#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double dist(int x0, int y0, int x1, int y1) {
  return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> x(N + M);
  vector<int> y(N + M);
  vector<int> r(N);
  for (int n = 0; n < N; n++) {
    cin >> x[n] >> y[n] >> r[n];
  }
  for (int m = 0; m < M; m++) {
    cin >> x[N + m] >> y[N + m];
  }
  const int INF = 200 * 1.5;
  double ans = INF;
  for (int n = 0; n < N; n++) {
    ans = min(ans, (double)r[n]);
  }
  for (int i = 0; i < M; i++) {
    for (int j = i + 1; j < M; j++) {
      ans = min(ans, dist(x[N + i], y[N + i], x[N + j], y[N + j]) / 2);
    }
  }
  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      ans = min(ans, dist(x[n], y[n], x[N + m], y[N + m]) - r[n]);
    }
  }
  cout << setprecision(16) << ans << endl;
  return 0;
}
