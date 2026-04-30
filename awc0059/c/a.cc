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
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<int> imos(N + 1, 0);
  for (int j = 0; j < M; j++) {
    int L, R;
    cin >> L >> R;
    L--;
    imos.at(L)++;
    imos.at(R)--;
  }
  for (int i = 0; i < N; i++) {
    imos.at(i + 1) += imos.at(i);
  }
  vector<long long> ans(N);
  for (int i = 0; i < N; i++) {
    ans.at(i) = A.at(i) * imos.at(i);
  }
  dump(ans);
  return 0;
}
