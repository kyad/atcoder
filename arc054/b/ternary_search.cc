// https://atcoder.jp/contests/arc054/tasks/arc054_b

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

double f(double x, double P) {
  return x + P / pow(2, x / 1.5);
}

int main() {
  double P;
  cin >> P;
  double left = 0;
  double right = pow(10, 18);
  while ((right - left) > 1e-9) {
    double c1 = (left * 2 + right) / 3;
    double c2 = (left + right * 2) / 3;
    if (f(c1, P) > f(c2, P)) {
      left = c1;
    } else {
      right = c2;
    }
  }
  double x = (left + right) / 2;
  double ans = f(x, P);
  cout << setprecision(15) << ans << endl;
  return 0;
}
