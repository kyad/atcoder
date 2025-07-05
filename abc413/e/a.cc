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
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    int M = 1<<N;
    vector<int> P(M);
    for (int j = 0; j < M; j++) {
      cin >> P.at(j);
    }
    for (int w = 1; w < M; w *= 2) {
      vector<int> Q(M);
      for (int a = 0; a < M; a += w * 2) {
        int b = a + w;
        int c = b + w;
        if (P.at(a) < P.at(b)) {
          for (int j = a; j < c; j++) {
            Q.at(j) = P.at(j);
          }
        } else {
          for (int j = a; j < b; j++) {
            Q.at(j) = P.at(j + w);
          }
          for (int j = b; j < c; j++) {
            Q.at(j) = P.at(j - w);
          }
        }
      }
      P = Q;
    }
    dump(P);
  }
  return 0;
}
