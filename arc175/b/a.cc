#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template<class T> T ceildiv(T a, T b);
// floor(a / b)を計算する。aが負の場合は負の無限大へ丸める。
template<class T> T floordiv(T a, T b) { assert(b > 0); return (a >= 0) ? (a / b) : (-ceildiv(-a, b)); }
// ceil(a / b)を計算する。aが負の場合は正の無限大へ丸める。
template<class T> T ceildiv(T a, T b) { assert(b > 0); return (a >= 0) ? ((a + b - 1) / b) : (-floordiv(-a, b)); }

int main() {
  int N;
  long long A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;
  stack<char> st;
  for (char c : S) {
    if (!st.empty() && st.top() == '(' && c == ')') {
      st.pop();
    } else {
      st.push(c);
    }
  }
  int p = 0, q = 0;
  while (!st.empty()) {
    if (st.top() == '(') {
      q++;
    } else {
      p++;
    }
    st.pop();
  }
  int r = min(p, q);
  auto f = [&](int p, int q) -> long long {  // rが偶数の時のソルバ
    int r = min(p, q);
    assert(r % 2 == 0);
    const long long INF = 4e18;
    long long ans = INF;
    for (int k = 0; k <= r / 2; k++) {  // k: 交換回数
      int s, t;  // 残った), (
      // 取る数=2k
      s = p - 2 * k;
      t = q - 2 * k;
      assert(s >= 0);
      assert(s % 2 == 0);
      assert(t >= 0);
      assert(t % 2 == 0);
      long long now = A * k + B * (s / 2 + t / 2);
      ans = min(ans, now);
    }
    return ans;
  };
  long long ans;
  if (r % 2 == 0) {
    ans = f(p, q);
  } else {
    long long ans1 = A;
    long long ans2 = B * 2;
    long long now = f(p - 1, q - 1);
    ans = min(ans1, ans2) + now;
  }
  cout << ans << endl;
  return 0;
}
