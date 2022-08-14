#include <iostream>
using namespace std;

// xをbase進数で見た時の桁数を返す
int digits(long long x, int base) { int d = 0; while (x > 0) { x /= base; d++; } return d; }

// digits桁の10のべきを返す
long long pow10(int digits) {long long ans = 1; for (int i = 0; i < digits - 1; i++) { ans *= 10; } return ans; }

long long f(long long x) {
  int n = digits(x, 10);
  return min(pow10(n + 1) + x, x * 10);
}

long long solve(long long L, long long R) {
  long long left = L - 1;  // NG
  long long right = R;  // OK
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    if (f(mid) > R) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return R - right + 1;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    long long L, R;
    cin >> L >> R;
    long long ans = solve(L, R);
    cout << ans << endl;
  }
  return 0;
}
