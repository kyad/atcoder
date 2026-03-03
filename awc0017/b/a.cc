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
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int j = 0; j < M; j++) {
    int B;
    cin >> B;
    B--;
    if (B >= 1) {
      A.at(B - 1)++;
    }
    A.at(B)++;
    if (B <= N - 2) {
      A.at(B + 1)++;
    }
  }
  dump(A);
  return 0;
}
