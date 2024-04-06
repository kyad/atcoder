#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> int argmax(vector<T> &A) {
  int N = A.size();
  assert(N >= 1);
  int ans = 0;
  T value = A.at(0);
  for (int i = 1; i < N; i++) {
    if (value < A.at(i)) {
      ans = i;
      value = A.at(i);
    }
  }
  return ans;
}

/**
 * 距離の2乗を返す
 */
template<typename T> T dist2(T x0, T y0, T x1, T y1) {
  return (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
}

int main() {
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
  }
  for (int i = 0; i < N; i++) {
    vector<int> L(N);
    for (int j = 0; j < N; j++) {
      L.at(j) = dist2(X.at(i), Y.at(i), X.at(j), Y.at(j));
    }
    int ans = argmax(L);
    cout << (ans + 1) << '\n';
  }
  return 0;
}
