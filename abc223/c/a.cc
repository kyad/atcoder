#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n) >> B.at(n);
  }
  double t0 = 0;
  for (int n = 0; n < N; n++) {
    t0 += (double)A.at(n) / B.at(n);
  }
  t0 /= 2.0;
  double ans = 0;
  for (int n = 0; n < N; n++) {
    double temp = (double)A.at(n) / B.at(n);
    if (t0 > temp) {
      t0 -= temp;
      ans += A.at(n);
    } else {
      ans += t0 * (double)B.at(n);
      break;
    }
  }
  printf("%.10lf\n", ans);
  return 0;
}
