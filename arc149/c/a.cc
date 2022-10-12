// https://atcoder.jp/contests/arc149/tasks/arc149_c

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<bool> used(N * N + 1, false);
  vector<int> ans(N * N, -1);
  const int odd_l = (N * N + 1) / 2 - N;
  const int odd_r = (N * N + 1) / 2 - 1;
  const int even_l = (N * N + 1) / 2;
  const int even_r = (N * N + 1) / 2 + N - 1;
  ans[odd_l] = 1;  used[1] = true;
  ans[odd_r] = 7;  used[7] = true;
  ans[even_l] = 8;  used[8] = true;
  ans[even_r] = 2;  used[2] = true;
  for (int i = odd_l + 1; i < odd_r; i++) {
    const int value =  6 * (i - odd_l) - 3;
    ans[i] = value;
    used[value] = true;
  }
  for (int i = even_l + 1; i < even_r; i++) {
    const int value =  6 * (i - even_l);
    ans[i] = value;
    used[value] = true;
  }
  // 奇数ゾーン
  {
    int i = 0;
    for (int value = 1; value <= N * N; value += 2) {
      if (used[value]) {
        continue;
      }
      ans[i++] = value;
    }
    assert(i == odd_l);
  }
  // 偶数ゾーン
  {
    int i = even_r + 1;
    for (int value = 2; value <= N * N; value += 2) {
      if (used[value]) {
        continue;
      }
      ans[i++] = value;
    }
    assert(i == N * N);
  }
  for (int i = 0; i < N * N; i++) {
    assert(ans[i] >= 1);
    cout << ans[i] << (i % N == N - 1 ? '\n' : ' ');
  }
  return 0;
}
