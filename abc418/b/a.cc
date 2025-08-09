#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  double ans = 0;
  auto f = [&](int i, int j) -> double {
    int t = j + 1 - i;
    if (t <= 2) {
      return 0;
    }
    if (S.at(i) != 't' || S.at(j) != 't') {
      return 0;
    }
    int x = 0;
    for (int k = i; k <= j; k++) {
      if (S.at(k) == 't') {
        x++;
      }
    }
    double ans = (double)(x - 2) / (t - 2);
    return ans;
  };
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      double now = f(i, j);
      ans = max(ans, now);
    }
  }
  cout << setprecision(15) << ans << endl;
  return 0;
}
