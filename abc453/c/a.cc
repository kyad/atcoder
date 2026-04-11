#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i);
  }
  int N2 = 1<<N;
  int ans = -1;
  for (int bit = 0; bit < N2; bit++) {
    int now = 0;
    double x = 0.5;
    for (int i = 0; i < N; i++) {
      int sign;
      if (bit>>i&1) {  //右
        sign = 1;
      } else {
        sign = -1;
      }
      double nx = x + sign * L.at(i);
      if (x * nx < 0) {
        now++;
      }
      x = nx;
    }
    ans = max(ans, now);
  }
  cout << ans << '\n';
  return 0;
}
