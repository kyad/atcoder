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
  const int M = 10000000;
  vector<int> A;
  for (int i = 1; i * i <= M; i++) {
    A.push_back(i * i);
  }
  vector<int> count(M + 1, 0);
  for (int a : A) {
    for (int b : A) {
      if (a >= b) {
        continue;
      }
      int n = a + b;
      if (n <= M) {
        count.at(n)++;
      }
    }
  }
  vector<int> ans;
  for (int n = 1; n <= N; n++) {
    if (count.at(n) == 1) {
      ans.push_back(n);
    }
  }
  int k = ans.size();
  cout << k << '\n';
  dump(ans);
  return 0;
}
