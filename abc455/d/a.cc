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
  vector<int> prev(2 * N, -1);
  vector<int> next(2 * N, -1);
  for (int i = 0; i < N; i++) {
    prev.at(i) = N + i;
    next.at(N + i) = i;
  }
  for (int qi = 0; qi < Q; qi++) {
    int C, P;
    cin >> C >> P;
    C--; P--;
    int cp = prev.at(C);
    next.at(cp) = -1;
    prev.at(C) = P;
    next.at(P) = C;
  }
  vector<int> ans(N, 0);
  for (int i = 0; i < N; i++) {
    int a = next.at(N + i);
    while (true) {
      if (a == -1) {
        break;
      }
      ans.at(i)++;
      a = next.at(a);
    }
  }
  dump(ans);
  return 0;
}
