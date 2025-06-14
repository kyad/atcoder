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
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N + 1, 0);
  vector<int> B(Q, -1);
  for (int q = 0; q < Q; q++) {
    int X;
    cin >> X;
    if (X >= 1) {
      A.at(X)++;
      B.at(q) = X;
    } else {
      int argmin = -1;
      int mn = 1e9;
      for (int i = 1; i <= N; i++) {
        if (A.at(i) < mn) {
          mn = A.at(i);
          argmin = i;
        }
      }
      A.at(argmin)++;
      B.at(q) = argmin;
    }
  }
  dump(B);
  return 0;
}
