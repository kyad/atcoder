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
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    A.at(i)--;
  }
  vector<int> dp(N, -1);
  dp.at(N - 1) = A.at(N - 1);
  for (int i = N - 2; i >= 0; i--) {
    if (A.at(i) == i) {
      dp.at(i) = i;
    } else {
      dp.at(i) = dp.at(A.at(i));
    }
  }
  vector<int> ans(N);
  for (int i = 0; i < N; i++) {
    ans.at(i) = dp.at(i) + 1;
  }
  dump(ans);
  return 0;
}
