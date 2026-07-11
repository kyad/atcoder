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
  vector<int> ans(M, -1);
  for (int i = 0; i < N; i++) {
    int C, S;
    cin >> C >> S;
    C--;
    ans.at(C) = max(ans.at(C), S);
  }
  dump(ans);
  return 0;
}
