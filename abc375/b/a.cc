#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

/**
 * 距離の2乗を返す
 */
double dist2(double x0, double y0, double x1, double y1) {
  return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}


int main() {
  int N;
  cin >> N;
  vector<int> X, Y;
  X.push_back(0);
  Y.push_back(0);
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    X.push_back(x);
    Y.push_back(y);
  }
  X.push_back(0);
  Y.push_back(0);
  double ans = 0;
  int M = X.size();
  for (int i = 0; i + 1 < M; i++) {
    double now = dist2(X.at(i), Y.at(i), X.at(i + 1), Y.at(i + 1));
    ans += now;
  }
  cout << setprecision(15) << ans << endl;
  return 0;
}
