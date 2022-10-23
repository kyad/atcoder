#include <iomanip>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  double A, B;
  cin >> A >> B;
  double ans = B / A;
  printf("%.03f\n", ans);
  return 0;
}
