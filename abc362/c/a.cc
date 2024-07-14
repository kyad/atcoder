#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N;
  cin >> N;
  vector<long long> L(N), R(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i) >> R.at(i);
  }
  vector<long long> X(N);
  for (int i = 0; i < N; i++) {
    X.at(i) = L.at(i);
  }
  long long S = 0;
  for (int i = 0; i < N; i++) {
    S += X.at(i);
  }
  if (S > 0) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < N; i++) {
    if (S < 0) {
      long long diff = -S;
      long long dx = min(R.at(i) - L.at(i), diff);
      X.at(i) += dx;
      S += dx;
    }
  }
  if (S == 0) {
    cout << "Yes" << endl;
    dump(X);
  } else {
    cout << "No" << endl;
  }
  return 0;
}
