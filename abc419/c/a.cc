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
  cin >> N;
  vector<long long> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  long long mx = -1;
  for (int i = 0; i < N; i++) {
    long long dx = max(abs(X.at(i) - X.at(0)), abs(X.at(i) - X.at(N - 1)));
    long long dy = max(abs(Y.at(i) - Y.at(0)), abs(Y.at(i) - Y.at(N - 1)));
    long long now = max(dx, dy);
    mx = max(mx, now);
  }
  long long ans = ceildiv(mx, 2LL);
  cout << ans << endl;
  return 0;
}
