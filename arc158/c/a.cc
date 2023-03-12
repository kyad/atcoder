#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long f(long long x) {
  long long ans = 0;
  while (x > 0) {
    long long now = x % 10;
    ans += now;
    x /= 10;
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  long long ans = 0;
  for (int n = 0; n < N; n++) {
    ans += f(A.at(n));
  }
  ans *= (2 * N);
  long long carry = 0;
  // D = 10^15
  long long D = 1;
  for (int i = 0; i < 15; i++) {
    D *= 10;
  }
  for (int k = 14; k >= 0; k--) {
    vector<long long> x(A);
    sort(x.begin(), x.end());
    long long now = 0;
    for (int n = 0; n < N; n++) {
      long long a = D - x[n];
      long long count = x.end() - lower_bound(x.begin(), x.end(), a);
      now += count;
    }
    carry += now;
    // Next
    D /= 10;
    for (int n = 0; n < N; n++) {
      long long d = A[n] / D;
      A[n] -= d * D;
    }
  }
  ans -= carry * 9;
  cout << ans << endl;
  return 0;
}
