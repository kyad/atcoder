#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
  double D;
  cin >> D;
  double r = D / 2;
  double ans = r * r * M_PI;
  cout << setprecision(16) << ans << '\n';
  return 0;
}
