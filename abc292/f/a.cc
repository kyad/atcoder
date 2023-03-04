#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  double A, B;
  cin >> A >> B;
  if (A > B) {
    swap(A, B);
  }
  assert(A <= B);
  double left = 0;  // OK
  double right = M_PI / 6; // NG
  while (right - left > 1e-12) {
    double theta = (left + right) / 2.;  // mid
    double p = A / cos(theta);
    double q = p * cos(M_PI / 6 - theta);
    if (q <= B) {
      left = theta;  // OK
    } else {
      right = theta;  // NG
    }
  }
  double ans = A / cos(left);
  cout << setprecision(15) << ans << endl;
  return 0;
}
