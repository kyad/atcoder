// https://atcoder.jp/contests/abc473/editorial/24877

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i);
  }
  vector<long long> S(A);
  for (int i = 1; i <= N; i++) {
    S.at(i) += S.at(i - 1);
    S.at(i) %= K;
  }
  int last = -1;  // 最後に選んだ右端
  map<int, int> prev;  // 最後に現れた座標
  int ans = 0;
  for (int i = 0; i <= N; i++) {
    if (prev.contains(S.at(i))) {
      if (last <= prev[S[i]]) {
        last = i;
        ans++;
      }
    }
    prev[S[i]] = i;
  }
  cout << ans << '\n';
  return 0;
}
