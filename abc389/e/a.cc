// https://www.youtube.com/watch?v=h3hSv7XRFzk&t=5049s

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

using lll = __int128;

int main() {
  int N;
  long long _M;
  cin >> N >> _M;
  lll M = _M;
  vector<lll> P(N);
  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;
    P.at(i) = p;
  }
  // y円未満は全て買うとした時に条件を満たすか？（M円以下にできるか？）
  // 条件を満たすなら個数を返す。満たさないなら-1を返す。
  auto check = [&](lll y) -> lll {
    lll cnt = 0;
    lll cost = 0;
    for (int i = 0; i < N; i++) {
      lll k = (y + P.at(i) - 1) / (P.at(i) * 2);
      cnt += k;
      if (k > 0 && M / k / k / P.at(i) < 1) {  // オーバフロー対策
        return -1;
      }
      cost += k * k * P.at(i);
      if (cost > M) {  // オーバーフロー対策
        return -1;
      }
    }
    cnt += (M - cost) / y;
    return cnt;
  };
  long long left = 0;  // OK
  long long right = 1e18+1;  // NG
  while (left + 1 < right) {
    long long mid = (left + right) / 2;
    if (check(mid) >= 0) {
      left = mid;
    } else {
      right = mid;
    }
  }
  long long ans = check(left);
  cout << ans << endl;
  return 0;
}
