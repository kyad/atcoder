#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> T ceildiv(T a, T b);
// floor(a / b)を計算する。aが負の場合は負の無限大へ丸める。
template<class T> T floordiv(T a, T b) { assert(b > 0); return (a >= 0) ? (a / b) : (-ceildiv(-a, b)); }
// ceil(a / b)を計算する。aが負の場合は正の無限大へ丸める。
template<class T> T ceildiv(T a, T b) { assert(b > 0); return (a >= 0) ? ((a + b - 1) / b) : (-floordiv(-a, b)); }

const long long INF = 4e18;

void testcase() {
  vector<long long> A(6, 0);
  for (int i = 1; i <= 5; i++) {
    cin >> A.at(i);
  }
  vector<long long> P(6, 0);
  for (int i = 1; i <= 5; i++) {
    cin >> P.at(i);
  }

  // ans1
  long long ans11 = P[5] * (A[1] + ceildiv(A[2] - A[4], 2LL) - A[5]);
  long long ans12 = INF;
  if (abs(A[2] - A[4]) % 2 == 1) {
    long long d5 = A[1] + (A[2] - A[4] - 1) / 2 - A[5];
    if (d5 >= 0) {
      ans12 = P[5] * d5 + P[4];
    }
  }
  long long ans1 = min(ans11, ans12);
  
  // ans2
  long long ans2 = P[4] * (A[1] * 2 + A[2] - A[4] - A[5] * 2);

  // ans
  long long ans = min(ans1, ans2);
  if (ans < 0) {
    ans = 0;
  }
  cout << ans << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    testcase();
  }
  return 0;
}
