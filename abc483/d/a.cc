#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N + 2, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i);
  }
  vector<tuple<long long, long long, long long>> top(N + 2);
  top.at(0) = {0, 0, 0};
  for (int i = 1; i <= N + 1; i++) {
    auto [a, b, x] = top.at(i - 1);
    if (A.at(i) >= 0) {
      top.at(i) = make_tuple(a, max(b, x + A.at(i)), x + A.at(i));
    } else {
      top.at(i) = make_tuple(min(a, x + A.at(i)), b, x + A.at(i));
    }
  }
  vector<pair<long long, long long>> bottom(N + 2);
  bottom.at(N + 1) = {0, 0};
  for (int i = N; i >= 0; i--) {
    auto [a, b] = bottom.at(i + 1);
    long long X = A.at(i);
    if (X >= 0) {
      bottom.at(i) = make_pair(min(0LL, X + a), X + b);
    } else {
      bottom.at(i) = make_pair(X + a, max(0LL, X + b));
    }
  }
  long long ans = 1;
  // 動かさない時
  {
    auto [a, b, x] = top.at(N);
    ans = b - a + 1;
  }
  // 動かす時
  for (int k = 1; k <= N; k++) {
    auto [a, b, x] = top.at(k - 1);
    auto [c, d] = bottom.at(k + 1);
    long long X = A.at(k);
    long long left = min(a, x - X + c);
    long long right = max(b, x - X + d);
    long long now = right - left + 1;
    ans = max(ans, now);
  }
  cout << ans << '\n';
  return 0;
}
