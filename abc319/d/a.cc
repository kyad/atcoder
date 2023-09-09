#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long MAX = 1000000000LL;

int main() {
  int N;
  long long M;
  cin >> N >> M;
  vector<long long> L(N);
  for (int n = 0; n < N; n++) {
    cin >> L.at(n);
  }
  auto sim = [&](long long x) {
    long long lines = 1;
    long long resi = x;
    for (int i = 0; i < N; i++) {
      if (L[i] <= resi) {
        resi -= L[i];
        if (resi >= 1) {
          resi--;
        }
      } else if (L[i] <= x) {
        lines++;
        resi = x - L[i];
        if (resi >= 1) {
          resi--;
        }
      } else {
        return false;
      }
    }
    if (lines <= M) {
      return true;
    } else {
      return false;
    }
  };
  long long left = 0;  // NG
  long long right = (MAX + 1LL) * N + 1LL;  // OK
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    bool now = sim(mid);
    if (now) {
      right = mid;
    } else {
      left = mid;
    }
  }
  long long ans = right;
  cout << ans << endl;
  return 0;
}
