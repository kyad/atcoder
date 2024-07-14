#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/**
 * 距離の2乗を返す
 */
template<typename T> T dist2(T x0, T y0, T x1, T y1) {
  return (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
}

int main() {
  vector<int> X(3), Y(3);
  for (int i = 0; i < 3; i++) {
    cin >> X.at(i) >> Y.at(i);
  }
  vector<int> d(3);
  for (int i = 0; i < 3; i++) {
    int j = (i + 1) % 3;
    d.at(j) = dist2(X[i], Y[i], X[j], Y[j]);
  }
  bool ans = false;
  if (d[0] + d[1] == d[2] || d[1] + d[2] == d[0] || d[2] + d[0] == d[1]) {
    ans = true;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
