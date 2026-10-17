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
  long long K, T;
  cin >> N >> K >> T;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  long long t = 0;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (T <= A.at(i)) {
      int now = ceildiv(T - t, K);
      ans += now;
      t += now * K;
      break;
    }
    if (A.at(i) <= t) {
    } else {
      int now = ceildiv(A.at(i) - t, K);
      ans += now;
    }
    t = A.at(i) + K;
    if (t >= T) {
      break;
    }
  }
  if (t < T) {
    ans += ceildiv(T - t, K);
  }
  cout << ans << '\n';
  return 0;
}
