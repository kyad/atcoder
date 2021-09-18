// https://atcoder.jp/contests/arc125/tasks/arc125_a

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> S(N);
  vector<int> T(M);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  for (int m = 0; m < M; m++) {
    cin >> T.at(m);
  }
  int p = S.at(0);
  int ans = 0;
  bool first_dial = true;
  for (int m = 0; m < M; m++) {
    if (T.at(m) == p) {
      ans++;
      continue;
    }
    if (!first_dial) {
      ans += 2;
      p = 1 - p;
      continue;
    }
    int right;
    for (right = 1; right < N; right++) {
      if (S.at(right) == 1 - p) {
        break;
      }
    }
    if (right == N) {
      ans = -1;
      break;
    }
    int left = 0;
    for (int n = N - 1; n >= 0; n--) {
      left++;
      if (S.at(n) == 1 - p) {
        break;
      }
    }
    ans += (min(right, left) + 1);
    first_dial = false;
    p = 1 - p;
  }
  cout << ans << endl;
  return 0;
}
