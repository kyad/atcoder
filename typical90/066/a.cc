#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> L(N), R(N);
  for (int n = 0; n < N; n++) {
    cin >> L.at(n) >> R.at(n);
  }
  double ans = 0;
  for (int j = 1; j < N; j++) {  // 0-indexed
    for (int k = L[j]; k <= R[j]; k++) {
      double now = 0;
      for (int i = 0; i < j; i++) {
        now += max(0., min(1., (double)(R[i] - k) / (R[i] - L[i] + 1)));
      }
      now /= (R[j] - L[j] + 1);
      ans += now;
    }
  }
  cout << setprecision(15) << ans << endl;
  return 0;
}
