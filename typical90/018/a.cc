// https://atcoder.jp/contests/typical90/tasks/typical90_r

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
  double T, L, X, Y;
  int Q;
  cin >> T >> L >> X >> Y >> Q;
  for (int q = 0; q < Q; q++) {
    double E;
    cin >> E;
    double phi = 2. * M_PI * E / T;
    double y = L / 2 * (1. - cos(phi));
    double x = sqrt(pow(X, 2) + pow(Y + L / 2 * sin(phi), 2) );
    double theta = atan2(y, x);
    double ans = theta * 180 / M_PI;
    cout << setprecision(15) << ans << endl;
  }
  return 0;
}
