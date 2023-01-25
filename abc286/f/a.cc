#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/math>
using namespace atcoder;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i);
    if (i + 1 == x.size()) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
}

int main() {
  vector<int> ps = {4, 9, 5, 7, 11, 13, 17, 19, 23};
  vector<int> ls = {0};
  int N = ps.size();
  for (int i = 0; i < N; i++) {
    int nl = ls[i] + ps[i];
    ls.push_back(nl);
  }
  int M = ls[N];
  vector<int> A(M, 0);
  for (int i = 0; i < N; i++) {
    int left = ls[i];
    for (int j = 0; j < ps[i]; j++) {
      A[left + j] = ((j + 1) % ps[i]) + left + 1;
    }
  }
  cout << M << endl;
  dump(A);

  vector<int> B(M, -1);
  for (int m = 0; m < M; m++) {
    cin >> B.at(m);
  }
  vector<long long> r(N, -1);
  for (int i = 0; i < N; i++) {
    int left = ls[i];
    r[i] = (B[left] - 1 - left + ps[i]) % ps[i];
  }
  vector<long long> m(N);
  for (int i = 0; i < N; i++) {
    m.at(i) = ps.at(i);
  }
  pair<long long, long long> p = crt(r, m);
  cout << p.first << endl;
  return 0;
}
