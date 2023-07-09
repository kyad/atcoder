// https://atcoder.jp/contests/arc164/editorial/6635

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int M = 39;

vector<long long> f(long long N) {
  vector<long long> A(M);
  for (int m = 0; m < M; m++) {
    A.at(m) = N % 3;
    N /= 3;
  }
  assert(N == 0);
  return A;
}

/// Return sign(x) (odd: 1, even: 0)
template<typename T> T sign(T x) { return (x % 2); }

void testcase() {
  long long N, K;
  cin >> N >> K;
  vector<long long> A = f(N);
  long long S = 0;
  for (long long a : A) {
    S += a;
  }
  if (K < S || K > N) {
    cout << "No" << '\n';
    return;
  }
  if (sign(S) != sign(K)) {
    cout << "No" << '\n';
    return;
  }
  cout << "Yes" << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    testcase();
  }
  return 0;
}
