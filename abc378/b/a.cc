#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
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
  vector<int> q(N), r(N);
  for (int i = 0; i < N; i++) {
    cin >> q.at(i) >> r.at(i);
  }
  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int t, d;
    cin >> t >> d;
    t--;
    int ans = ceildiv(d - r.at(t), q.at(t)) * q.at(t) + r.at(t);
    cout << ans << '\n';
  }
  return 0;
}
