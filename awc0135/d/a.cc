// https://atcoder.jp/contests/awc0135/editorial/23873

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

int main() {
  int N;
  long long V;
  cin >> N >> V;
  vector<int> X(N);
  vector<long long> D(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> D.at(i);
  }
  const long long INF = (long long)1e18+1;
  long long left = 0;  // NG
  long long right = INF;  // OK
  auto check = [&](long long K) -> bool {
    long long L = 0;
    long long R = 1e9;
    for (int i = 0; i < N; i++) {
      long long m = V - ceildiv(D.at(i), K);
      if (m < 0) {
        return false;
      }
      long long l = X.at(i) - m;
      long long r = X.at(i) + m;
      L = max(L, l);
      R = min(R, r);
    }
    return L <= R;
  };
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    if (check(mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  long long ans = right;
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << '\n';
  return 0;
}
