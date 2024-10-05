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

using lll = __int128;
const long long INF = 4e18;

int main() {
  int N;
  long long _X;
  cin >> N >> _X;
  long long X = _X;
  vector<long long> A(N), B(N);
  vector<long long> P(N), Q(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> P.at(i) >> B.at(i) >> Q.at(i);
  }
  const long long MAX = 2000000010;
  long long left = 0;  // OK
  long long right = MAX;  // NG

  // W個製造できるか？
  auto check = [&](long long W) {
    long long total = 0;  // 全体のコスト
    for (int i = 0; i < N; i++) {  // i番目の工程でW個製造する時のコストを求める
      long long a = A[i];
      long long b = B[i];
      long long p = P[i];
      long long q = Q[i];
      long long cost = INF;  // 今のコスト
      for (long long s = 0; s <= b; s++) {
        long long t = ceildiv(W - a * s, b);
        if (t < 0) {
          continue;
        }
        long long now = p * s + q * t;
        cost = min(cost, now);
      }
      for (long long t = 0; t <= a; t++) {
        long long s = ceildiv(W - b * t, a);
        if (s < 0) {
          continue;
        }
        long long now = p * s + q * t;
        cost = min(cost, now);
      }
      assert(cost >= 0);
      total += cost;
    }
    bool ans = total <= X;
    return ans;
  };

  // left個以上生産できるか？  
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    if (check(mid)) {
      left = mid; // OK
    } else {
      right = mid; // NG
    }
  }
  long long ans = left;
  cout << ans << endl;
  return 0;
}
