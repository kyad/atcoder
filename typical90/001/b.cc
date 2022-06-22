// https://atcoder.jp/contests/typical90/tasks/typical90_a

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;
  int K;
  cin >> K;
  vector<int> A(N + 2);
  A.at(0) = 0;
  A.at(N + 1) = L;
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  vector<int> B(N + 1);
  for (int n = 0; n <= N; n++) {
    B.at(n) = A.at(n + 1) - A.at(n);
  }
  // 全部のようかんが長さx以上になるように切る時、K回で切れるか？
  auto solve = [&](int x) -> bool {
    int count = 0;
    int now = 0;
    bool ans = true;
    for (int n = 0; n <= N; n++) {
      now += B.at(n);
      if (n == N) {
        if (now < x) {
          ans = false;
        }
        break;
      }
      if (count < K && now >= x) {
        count++;
        now = 0;
      }
    }
    if (ans) {
      ans = (count >= K);
    }
    return ans;
  };
  int left = 1;  // OK
  int right = 1000000001;  // NG
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (solve(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << left << endl;
  return 0;
}
