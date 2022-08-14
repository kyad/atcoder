// https://atcoder.jp/contests/arc142/tasks/arc142_c

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> d1(N + 1, 0), d2(N + 1, 0); // 1, 2からの距離。1-indexed
  for (int n = 3; n <= N; n++) {
    cout << "? 1 " << n << endl;
    cin >> d1.at(n);
    if (d1.at(n) < 0) {
      exit(1);
    }
    cout << "? 2 " << n << endl;
    cin >> d2.at(n);
    if (d2.at(n) < 0) {
      exit(1);
    }
  }
  int ans = 100;
  int count = 0;
  // 1, 2から距離1の頂点番号
  int u1 = -1;
  int u2 = -1;
  for (int n = 3; n <= N; n++) {
    int now = d1.at(n) + d2.at(n);
    if (abs(d1.at(n) - d2.at(n)) == 1) {
      count++;
    }
    ans = min(ans, now);
    if (d1.at(n) == 1) {
      u1 = n;
    }
    if (d2.at(n) == 1) {
      u2 = n;
    }
  }
  // Care for 3 - 1 - 2 - 4
  if (count == N - 2) {
    if (u1 >= 3 && u2 >= 3) {
      cout << "? " << u1 << ' ' << u2 << endl;
      int d;
      cin >> d;
      if (d < 0) {
        exit(1);
      }
      if (d >= 2) {
        ans = 1;
      }
    } else {
      // 1 - 2 - *
      ans = 1;
    }
  }
  cout << "! " << ans << endl;
  return 0;
}
