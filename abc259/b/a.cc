#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double a, b, d;
  cin >> a >> b >> d;
  double t = d * M_PI / 180.;
  double x = a * cos(t) - b * sin(t);
  double y = a * sin(t) + b * cos(t);
  cout << setprecision(15) << x << ' ' << y << endl;
  return 0;
}
