#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  double A, B;
  cin >> A >> B;
  double g = 1;
  auto f = [&](double x) {
    double ans = A / sqrt(x + g) + B * x;
    return ans;
  };
  double x0 = pow(A / (B * 2), 2. / 3) - g;
  long long X0 = (long long)(x0) - 1;
  long long X1 = (long long)(x0);
  long long X2 = (long long)(x0) + 1;
  double ans = f(X0);
  ans = min(ans, f(X1));
  ans = min(ans, f(X2));
  cout << setprecision(15) << ans << endl;
  return 0;
}
