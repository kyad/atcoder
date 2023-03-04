#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  if (A > B) {
    swap(A, B);
  }
  assert(A <= B);
  double left = (sqrt(6.) - sqrt(2.)) * A; // OK
  double right = B; // NG
  right = min(right, 2. / sqrt(3) * A);
  while (right - left > 1e-12) {
    double mid = (left + right) / 2.;
    double theta = acos((double)A / mid);
    if (theta <= M_PI / 2) {
      // OK
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << setprecision(16) << left << endl;
  return 0;
}
