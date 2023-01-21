// https://atcoder.jp/contests/arc153/tasks/arc153_c

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> T sgn(T x) {
  return x > 0 ? 1 : x < 0 ? -1 : 0;
}

template<typename T> void dump(const vector<T> &x) {
  for (size_t i = 0; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

template<typename T> void check(const vector<int> &A, const vector<T> &x) {
  long long sum = 0;
  assert(A.size() == x.size());
  for (size_t n = 0; n < A.size(); n++) {
    sum += x[n] * A[n];
  }
  if (sum != 0) {
    cerr << "NG sum=" << sum << endl;
    exit(1);
  }
  for (size_t n = 0; n < A.size() - 1; n++) {
    if (x[n + 1] <= x[n]) {
      cerr << "NG x[" << n << "]=" << x[n] << " x[" << (n + 1) << "]=" << x[n + 1] << endl;
      exit(1);
    }
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> B(N, 0);
  B.at(N - 1) = A.at(N - 1);
  for (int n = N - 2; n >= 0; n--) {
    B.at(n) = B.at(n + 1) + A.at(n);
  }
  if (B[0] != 0) {
    long long x0 = 0;
    for (int n = 1; n <= N - 1; n++) {
      x0 += B[n];
    }
    x0 *= -sgn(B[0]);
    vector<long long> x(N, x0);
    for (int n = 1; n < N; n++) {
      x[n] = x[n - 1] + abs(B[0]);
    }
    cout << "Yes" << endl; 
    check(A, x);
    dump(x);
    return 0;
  } else {
    // Check all positive
    bool ok = true;
    for (int n = 1; n < N; n++) {
      if (B.at(n) < 0) {
        ok = false;
      }
    }
    if (ok) {
      cout << "No" << endl;
      return 0;
    }
    // Check all negative
    ok = true;
    for (int n = 1; n < N; n++) {
      if (B.at(n) > 0) {
        ok = false;
      }
    }
    if (ok) {
      cout << "No" << endl;
      return 0;
    }
    // Other cases
    int p = -1;
    int q = -1;
    for (int n = 1; n < N; n++) {
      if (p < 0 && B.at(n) == -1) {
        p = n;
      }
      if (q < 0 && B.at(n) == 1) {
        q = n;
      }
    }
    assert(p >= 1);
    assert(q >= 1);
    long long X = 0;
    for (int n = 1; n < N; n++) {
      X += B[n];
    }
    vector<long long> x(N, 1);
    if (X >= 0) {
      for (int n = 1; n < N; n++) {
        x[n] = x[n - 1] + ((n == p) ? (1 + X) : 1);
      }
    } else {
      for (int n = 1; n < N; n++) {
        x[n] = x[n - 1] + ((n == q) ? (1 - X) : 1);
      }
    }
    cout << "Yes" << endl;
    dump(x);
    check(A, x);
  }
  return 0;
}
