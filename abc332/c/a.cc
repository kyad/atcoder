#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  auto f = [&](int A) -> bool {
    int m = M;
    int a = A;
    for (int i = 0; i < N; i++) {
      if (S[i] == '0') {
        m = M;
        a = A;
      } else if (S[i] == '1') {
        if (m > 0) {
          m--;
        } else if (a > 0) {
          a--;
        } else {
          return false;
        }
      } else {
        if (a > 0) {
          a--;
        } else {
          return false;
        }
      }
    }
    return true;
  };
  if (f(0)) {
    cout << 0 << endl;
    return 0;
  }
  int left = 0;
  int right = N;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    bool now = f(mid);
    if (now) {
      right = mid;
    } else {
      left = mid;
    }
  }
  const int ans = right;
  cout << ans << endl;
  return 0;
}
