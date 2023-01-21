#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/// Return sgn(x). If x == 0, then return 0.
template<typename T> T sgn(T x) {
  return x > 0 ? 1 : x < 0 ? -1 : 0;
}

vector<long long> cumsum(int N, const vector<long long> &y) {
  vector<long long> x(N + 1, 0);
  x[1] = y[1];
  for (int n = 2; n <= N; n++) {
    x[n] = x[n - 1] + y[n];
  }
  return x;
}

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

bool check_all_sgn(int N, const vector<int> &B, int sgn) {
  bool ans = true;
  for (int n = 1; n <= N; n++) {
    if (sgn * B[n] < 0) {
      ans = false;
    }
  }
  return ans;
}

void check(int N, const vector<int> &A, const vector<long long> &x) {
  long long sum = 0;
  assert((int)A.size() == N + 1);
  assert((int)x.size() == N + 1);
  for (int n = 1; n <= N; n++) {
    if (abs(x[n]) > 1000000000000LL) {
      cerr << "NG x[" << n << "]=" << x[n] << endl;
      exit(1);
    }
  }
  for (int n = 1; n <= N; n++) {
    sum += x[n] * A[n];
  }
  if (sum != 0) {
    cerr << "NG sum=" << sum << endl;
    exit(1);
  }
  for (int n = 1; n < N; n++) {
    if (x[n + 1] <= x[n]) {
      cerr << "NG x[" << n << "]=" << x[n] << " x[" << (n + 1) << "]=" << x[n + 1] << endl;
      exit(1);
    }
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  vector<int> B(N + 1, 0);
  B[N] = A[N];
  for (int n = N - 1; n >= 1; n--) {
    B[n] = A[n] + B[n + 1];
  }
  if (abs(B[1]) > 0) {
    long long sum = 0;
    vector<long long> y(N + 1, abs(B[1]));
    for (int i = 2; i <= N; i++) {
      sum += B[i];
    }
    y[1] = sum * (-sgn(B[1]));
    vector<long long> x = cumsum(N, y);
    cout << "Yes" << endl;
    dump(x, 1);
    check(N, A, x);
    return 0;
  }

  // B[1] == 0
  if (check_all_sgn(N, B, +1) || check_all_sgn(N, B, -1)) {
    cout << "No" << endl;
    return 0;
  }

  // B[p] = -1, B[q] = +1なるp, qを探す
  int p = -1;
  int q = -1;
  for (int n = 2; n <= N; n++) {
    if (B[n] == -1) {
      p = n;
    } else if (B[n] == +1) {
      q = n;
    }
  }
  assert(p >= 2);
  assert(q >= 2);

  long long X = 0;
  for (int n = 2; n <= N; n++) {
    X += B[n];
  }

  vector<long long> y(N + 1, 1);
  y[1] = -1000000000000LL;
  if (X >= 0) {
    y[p] = 1 + X;
  } else {
    y[q] = 1 - X;
  }
  vector<long long> x = cumsum(N, y);
  cout << "Yes" << endl;
  dump(x, 1);
  check(N, A, x);
  return 0;
}
