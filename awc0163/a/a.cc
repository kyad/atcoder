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
  long long M;
  long long K;
  cin >> N >> M >> K;
  long long all = 0;
  for (int i = 0; i < N; i++) {
    long long A;
    cin >> A;
    long long now = ceildiv(A, K);
    all += now;
  }
  long long ans = max(0LL, all - M);
  cout << ans << '\n';
  return 0;
}
