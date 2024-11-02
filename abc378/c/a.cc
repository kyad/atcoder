#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
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
  vector<int> B(N, -1);
  map<int, int> prev;  // A[i]が前に現れた位置
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    if (prev.contains(A)) {
      B.at(i) = prev[A];
    }
    prev[A] = i + 1;
  }
  dump(B);
  return 0;
}
