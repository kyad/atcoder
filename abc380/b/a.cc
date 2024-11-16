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
  string S;
  cin >> S;
  vector<int> A;
  int M = S.size();
  int len = 0;
  for (int j = 1; j < M; j++) {
    char c = S.at(j);
    if (c == '-') {
      len++;
    } else {
      A.push_back(len);
      len = 0;
    }
  }
  dump(A);
  return 0;
}
