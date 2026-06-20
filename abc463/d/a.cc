#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 4e18;

int main() {
  int N, K;
  cin >> N >> K;
  vector<pair<long long, long long> > RL(N);
  for (int i = 0; i < N; i++) {
    long long L, R;
    cin >> L >> R;
    RL.at(i) = make_pair(R, L);
  }
  sort(RL.begin(), RL.end());
  long long right = 1e9 + 1;  // NG
  long long left = 0;         // OK
  auto check = [&](long long X) {
    int count = 0;
    long long right = -INF;
    for (auto [R, L] : RL) {
      if (right + X <= L) {
        right = R;
        count++;
        if (count >= K) {
          return true;
        }
      }
    }
    return false;
  };
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    if (check(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  long long ans = left;
  if (ans == 0) {
    ans = -1;
  }
  cout << ans << '\n';
  return 0;
}
