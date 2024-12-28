// https://atcoder.jp/contests/abc386/editorial/11697

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  long long ans = 0;
  auto f = [&](auto f, long long sum, int i, int c) {
    if (c == 0) {
      ans = max(ans, sum);
      return;
    }
    if (i == N) {
      return;
    }
    f(f, sum, i + 1, c);  // iを取らない
    sum ^= A.at(i);
    f(f, sum, i + 1, c - 1);  // iを取る
  };

  if (K <= N - K) {
    f(f, 0, 0, K);
  } else {
    long long all_sum = 0;
    for (int i = 0; i < N; i++) {
      all_sum ^= A.at(i);
    }
    f(f, all_sum, 0, N - K);
  }

  cout << ans << endl;
  return 0;
}
